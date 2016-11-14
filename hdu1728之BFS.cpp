#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<iomanip>
#include<limits.h>
using namespace std;
#define INF 999999
const int MAX=111;
char s[MAX][MAX];
int t[MAX][MAX];
int n,m,sum;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
typedef struct{
	int front_x;
	int front_y;
	int x;
	int y;
	int num;
}point;
point start,end;
bool bfs(){
	for(int i=0;i<m;++i){
		for(int j=0;j<n;++j){
			t[i][j]=INF;
		}
	}
	t[start.x][start.y]=0;
	queue<point>enqueue;
	point outqueue,next;
	enqueue.push(start);
	while(!enqueue.empty()){
		outqueue=enqueue.front();
		enqueue.pop();
		for(int i=0;i<4;++i){
			next.x=outqueue.x+dir[i][0];
			next.y=outqueue.y+dir[i][1];
			next.num=outqueue.num;
			next.front_x=outqueue.x;
			next.front_y=outqueue.y;
			if((outqueue.front_x==outqueue.x&&next.x!=outqueue.x)||(outqueue.front_y==outqueue.y&&next.y!=outqueue.y))
			    next.num++;
	        //if(next.num<=sum&&next.x==end.x&&next.y==end.y){
        	//	return true;
        //	}
        	if(next.num<=sum&&s[next.x][next.y]=='.'&&next.x>=0&&next.x<m&&next.y>=0&&next.y<n&&(next.x!=outqueue.front_x||next.y!=outqueue.front_y)&&next.num<=t[next.x][next.y]){
	        	enqueue.push(next);
	        	t[next.x][next.y]=next.num;
        	}
		}
	}
	if(t[end.x][end.y]<=sum)return true;
	return false;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>m>>n;
		for(int i=0;i<m;++i){
			scanf("%s",s[i]);
		}
		cin>>sum>>start.y>>start.x>>end.y>>end.x;
		start.y--;
		start.x--;
		start.front_x=-1;
		start.front_y=-1;
		end.x--;
		end.y--;
		start.num=0;
		s[start.x][start.y]='*';
		if(bfs())cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	return 0;
}