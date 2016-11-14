#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<iomanip>
#include<limits.h>
#include<cmath>
using namespace std;

const int MAX=10;
char map[MAX][MAX];
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
int n,m,start_time;
int start_x,start_y,end_x,end_y;

bool DFS(int x,int y,int use_time){
	int next_x,next_y;
	int left_time=start_time-use_time;//剩余可走时间 
	int over_time=left_time-abs(x-end_x)-abs(y-end_y);//假如没有墙花最少时间到出口处所剩余的时间 
	if(over_time<0||over_time&1){//奇偶剪枝，你可以这样想：你花了最少的时间（即你当前的位置与终点位置横纵坐标差）， 
		return false;            //然后你到了终点，但是你还有时间多，所以你闲着无聊从出口处退回迷宫一步，然后你又前进一步 
	}                            //到达出口处，时间是2，假如你退回n步，只能再前进n步到达出口处了，时间2n为偶数（所说的退回其实是因为有墙）. 
	for(int i=0;i<4;++i){
		next_x=x+dir[i][0];
		next_y=y+dir[i][1];
		if(next_x==end_x&&next_y==end_y&&left_time==1&&left_time==1){
			return true;
		}
		else if(map[next_x][next_y]=='.'&&next_x>=0&&next_y<m&&next_x<n&&next_y>=0){
			map[next_x][next_y]='X';//走过的地方标记为墙，下次就不会再走了 
			bool flag=DFS(next_x,next_y,use_time+1);
			map[next_x][next_y]='.';//返回的时候要把该点标为未走. 
			if(flag)return true;
		}
	}
	return false;
}

int main(){
	while(cin>>n>>m>>start_time,n&&m&&start_time){
		int wall=0;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				//scanf("%c",&map[i][j]);
				cin>>map[i][j];
				if(map[i][j]=='S'){
					start_x=i;
					start_y=j;
				}
				if(map[i][j]=='D'){
					end_x=i;
					end_y=j;
				}
				if(map[i][j]=='X'){
					wall++;
				}
			}
		}
		if(n*m-wall<=start_time){//剪枝，剩余的路数比墙还少则输出NO,题目的意思可是说走出迷宫的时间要恰好等于所给的时间哦。 
			cout<<"NO"<<endl;
			continue;
		}
		map[start_x][start_y]='X';
		bool flag=DFS(start_x,start_y,0);
		if(flag)cout<<"YES"<<endl;
		else cout<<"NO"<<endl; 
	}
	return 0;
}