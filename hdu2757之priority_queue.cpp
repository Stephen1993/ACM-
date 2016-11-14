#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=1000+10;
int n,m,t,sx,sy,ex,ey;
char Map[MAX][MAX];
int mark[MAX][MAX];
int dir[8][2]={-1,0,-1,1,0,1,1,1,1,0,1,-1,0,-1,-1,-1};

struct Node{
	int x,y,time;
	Node(){}
	Node(int X,int Y,int Time):x(X),y(Y),time(Time){}
	bool operator<(const Node &a)const{
		return time>a.time; 
	}
};

int BFS(){
	memset(mark,-1,sizeof mark);
	priority_queue<Node>q;
	Node next,oq;
	q.push(Node(sx,sy,0));
	mark[sx][sy]=0;
	while(!q.empty()){
		oq=q.top();
		q.pop();
		if(oq.x == ex && oq.y == ey)return mark[ex][ey];
		for(int i=0;i<8;++i){
			next=Node(oq.x+dir[i][0],oq.y+dir[i][1],oq.time);
			if(next.x<0 || next.y<0 || next.x>=n || next.y>=m)continue;
			if(Map[oq.x][oq.y] != i+'0')++next.time;
			if(mark[next.x][next.y] == -1 || mark[next.x][next.y] > next.time){
				mark[next.x][next.y]=next.time,q.push(next);
			} 
		}
	}
	return -1;
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<n;++i)scanf("%s",Map[i]);
		scanf("%d",&t);
		while(t--){
			scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
			--sx,--sy,--ex,--ey;
			printf("%d\n",BFS());
		}
	}
	return 0;
}