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

const int MAX=20+10;
char Map[MAX][MAX];
int mark[MAX][MAX][MAX][MAX];//标记在位置i,j且终点位置在x,y
int n,m;
int dir[4][2]={0,1,1,0,0,-1,-1,0};

struct Node{
	int x,y,ex,ey,time;//记录本点位置和终点位置
	Node(){}
	Node(int X,int Y,int Ex,int Ey,int Time):x(X),y(Y),ex(Ex),ey(Ey),time(Time){}
}start;

int BFS(int &flag){
	if(start.x == start.ex && start.y == start.ey)return start.time;
	if(start.x == start.ex && (start.y-start.ey == 1 || start.y-start.ey == -1))return start.time;
	if(start.y == start.ey && (start.x-start.ex == 1 || start.x-start.ex == -1))return start.time;
	queue<Node>q;
	Node oq,next;
	q.push(start);
	mark[start.x][start.y][start.ex][start.ey]=flag;
	while(!q.empty()){
		oq=q.front();
		q.pop();
		for(int i=0;i<4;++i){
			int k=(i+2)%4;
			next=Node(oq.x+dir[i][0],oq.y+dir[i][1],oq.ex+dir[k][0],oq.ey+dir[k][1],oq.time+1);
			if(next.x<0 || next.y<0 || next.x>=n || next.y>=m)continue;
			if(next.ex<0 || next.ey<0 || next.ex>=n || next.ey>=m)next.ex=oq.ex,next.ey=oq.ey;;
			if(Map[next.ex][next.ey] == 'X')next.ex=oq.ex,next.ey=oq.ey;
			if(Map[next.x][next.y] == 'X' || mark[next.x][next.y][next.ex][next.ey] == flag)continue;
			mark[next.x][next.y][next.ex][next.ey]=flag;
			if(next.x == next.ex && next.y == next.ey)return next.time;
			if(next.x == next.ex && (next.y-next.ey == 1 || next.y-next.ey == -1))return next.time;
			if(next.y == next.ey && (next.x-next.ex == 1 || next.x-next.ex == -1))return next.time;
			q.push(next);
		}
	}
	return -1;
}

int main(){
	int num=0;
	while(cin>>n>>m){
		for(int i=0;i<n;++i)cin>>Map[i];
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				if(Map[i][j] == 'Z')start.x=i,start.y=j;
				if(Map[i][j] == 'S')start.ex=i,start.ey=j;
			}
		}
		start.time=0;
		int temp=BFS(++num);
		if(temp == -1)cout<<"Bad Luck!"<<endl;
		else cout<<temp<<endl;
	}
	return 0;
}