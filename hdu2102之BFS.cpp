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

const int MAX=10+10;
char Map[2][MAX][MAX];
int n,m,t;
int dir[4][2]={0,1,0,-1,1,0,-1,0};
int mark[2][MAX][MAX];//标记第k个迷宫i,j位置是否访问过 

struct Node{
	int x,y,id,time;//id表示第几个迷宫
	Node(){}
	Node(int X,int Y,int Id,int Time):x(X),y(Y),id(Id),time(Time){}
}start;

bool BFS(int &flag){
	queue<Node>q;
	Node oq,next;
	q.push(start);
	mark[start.id][start.x][start.y]=flag;
	while(!q.empty()){
		oq=q.front();
		q.pop();
		if(oq.time>=t)return false;
		for(int i=0;i<4;++i){
			next=Node(oq.x+dir[i][0],oq.y+dir[i][1],oq.id,oq.time+1);
			if(next.x<0 || next.y<0 || next.x>=n || next.y>=m)continue;
			if(Map[next.id][next.x][next.y] == '#')next.id=!next.id;
			if(Map[next.id][next.x][next.y] == '*' || mark[next.id][next.x][next.y] == flag)continue;
			mark[next.id][next.x][next.y]=flag;
			if(Map[next.id][next.x][next.y] == '#')continue;
			if(Map[next.id][next.x][next.y] == 'P')return true;
			q.push(next);
		}
	}
	return false;
}

void Input(int id){
	for(int i=0;i<n;++i)cin>>Map[id][i];
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(Map[id][i][j] == 'S')start=Node(i,j,id,0);
		}
	}
}

int main(){
	int T,num=0;
	cin>>T;
	while(T--){
		cin>>n>>m>>t;
		Input(0);
		Input(1);
		if(BFS(++num))cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}