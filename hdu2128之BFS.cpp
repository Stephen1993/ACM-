#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<vector>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=8+10;
vector<long long int>mark[MAX][MAX][MAX*MAX*9];//在i,j含有炸弹k时所炸过的墙 
char Map[MAX][MAX];
int n,m;
int dir[4][2]={0,1,0,-1,1,0,-1,0};

struct Node{
	int x,y,num,time;
	unsigned long long open;//表示已经炸过的墙(最多8*8位) 
	unsigned long long key;//表示已经取过的炸药位置(最多8*8) 
	Node(){}
	Node(int X,int Y,int Num,int Time,unsigned long long Open,unsigned long long Key){
		x=X,y=Y,num=Num;
		time=Time,open=Open,key=Key;
	}
	bool operator<(Node const &a)const{
		return time>a.time;
	}
}start;

bool check(Node &next){
	int size=mark[next.x][next.y][next.num].size();
	for(int i=0;i<size;++i){//判断在该位置拥有炸弹num的情况下炸过的墙是否一样 
		if(next.open == mark[next.x][next.y][next.num][i])return true;
	}
	return false;
}

int BFS(){
	priority_queue<Node>q;
	Node oq,next;
	q.push(start);
	while(!q.empty()){
		oq=q.top();
		q.pop();
		for(int i=0;i<4;++i){
			next=Node(oq.x+dir[i][0],oq.y+dir[i][1],oq.num,oq.time+1,oq.open,oq.key);
			if(next.x<0 || next.y<0 || next.x>=n || next.y>=m)continue;
			if(Map[next.x][next.y] == 'X'){//该点是墙 
				int k=next.x*m+next.y;
				if( !((next.open>>k)&1) )--next.num,++next.time;//是否已炸过 
				next.open|=((1ll)<<k);
			}
			if(Map[next.x][next.y]>='1' && Map[next.x][next.y]<='9'){//该点有炸药可取 
				int k=next.x*m+next.y;
				if( !((next.key>>k)&1) )next.num+=Map[next.x][next.y]-'0';//是否已取过 
				next.key|=((1ll)<<k);
			}
			if(next.num<0 || check(next))continue;
			mark[next.x][next.y][next.num].push_back(next.open);
			if(Map[next.x][next.y] == 'D')return next.time;
			q.push(next);
		}
	}
	return -1;
}

void Init(){
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			for(int k=0;k<=m*n*9;++k){
				mark[i][j][k].clear();//初始化没炸过任何墙 
			}
		}
	}
}

int main(){
	while(cin>>n>>m,n+m){
		Init();
		memset(mark,-1,sizeof mark);
		for(int i=0;i<n;++i)cin>>Map[i];
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				if(Map[i][j] == 'S')start=Node(i,j,0,0,0,0);
			}
		}
		cout<<BFS()<<endl;
	}
	return 0;
}