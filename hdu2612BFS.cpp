#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#define INF 999999999
using namespace std;

const int MAX=201;
char s[MAX][MAX];
int Y[MAX][MAX],M[MAX][MAX],n,m;
int dir[4][2]={0,1,0,-1,1,0,-1,0};
bool mark[MAX][MAX];

typedef struct{
	int x,y,t;
}node;

void BFS(int x,int y,char z){
	queue<node>enqueue;
	node next,outqueue;
	next.x=x,next.y=y,next.t=0;
	enqueue.push(next);
	memset(mark,false,sizeof mark);
	mark[x][y]=true;
	while(!enqueue.empty()){
		outqueue=enqueue.front();
		enqueue.pop();
		for(int i=0;i<4;++i){
			next.x=outqueue.x+dir[i][0];
			next.y=outqueue.y+dir[i][1];
			next.t=outqueue.t+1;
			if(next.x>=n || next.x<0 || next.y>=m || next.y<0 || mark[next.x][next.y] || s[next.x][next.y] == '#')continue;
			mark[next.x][next.y]=true;
			if(s[next.x][next.y] == '@'){
				if(z == 'Y')Y[next.x][next.y]=next.t;
				else M[next.x][next.y]=next.t;
			}
			enqueue.push(next);
		}
	}
}

int main(){
	int a,b,x,y;
	while(cin>>n>>m){
		memset(Y,0,sizeof Y);
		memset(M,0,sizeof M);
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				cin>>s[i][j];
				if(s[i][j] == 'Y')a=i,b=j;
				if(s[i][j] == 'M')x=i,y=j;
			}
		}
		BFS(a,b,'Y');
		BFS(x,y,'M');
		int sum=INF;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				if(Y[i][j] && M[i][j])sum=min(sum,Y[i][j]+M[i][j]);
			}
		}
		cout<<sum*11<<endl;
	}
	return 0;
}