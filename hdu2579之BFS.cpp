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

const int MAX=100+10;
char Map[MAX][MAX];
int mark[MAX][MAX][20];
int n,m,k;
int dir[4][2]={0,1,0,-1,1,0,-1,0};

struct Node{
	int x,y,time;
	Node(){}
	Node(int X,int Y,int Time):x(X),y(Y),time(Time){}
}start;

int BFS(int &flag){
	queue<Node>q;
	Node oq,next;
	q.push(start);
	mark[start.x][start.y][start.time%k]=flag;
	while(!q.empty()){
		oq=q.front();
		q.pop();
		for(int i=0;i<4;++i){
			next=Node(oq.x+dir[i][0],oq.y+dir[i][1],oq.time+1);
			if(next.x<0 || next.y<0 || next.x>=n || next.y>=m)continue;
			if(mark[next.x][next.y][next.time%k] == flag)continue;
			if(next.time%k != 0 && Map[next.x][next.y] == '#')continue;
			mark[next.x][next.y][next.time%k]=flag;
			if(Map[next.x][next.y] == 'G')return next.time;
			q.push(next);
		}
	}
	return -1;
}

int main(){
	int num=0,t;
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		for(int i=0;i<n;++i)cin>>Map[i];
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				if(Map[i][j] == 'Y')start.x=i,start.y=j;
			}
		}
		start.time=0;
		int temp=BFS(++num);
		if(temp != -1)cout<<temp<<endl;
		else cout<<"Please give me another chance!"<<endl;
	}
	return 0;
}