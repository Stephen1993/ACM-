#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=20+10;
char Map[MAX][MAX];
int n,m,t;
int mark[MAX][MAX][1<<11];//1<<1表示在i,j点获得x种的钥匙是否已走过
int dir[4][2]={0,1,0,-1,1,0,-1,0};

struct Node{
	int x,y,time,key;//在x,y点的时间和获得的钥匙 
	Node(){}
	Node(int X,int Y,int Time,int Key):x(X),y(Y),time(Time),key(Key){}
}start;

int BFS(int &flag){
	mark[start.x][start.y][start.key]=flag;
	queue<Node>q;
	Node next,oq;
	q.push(start);
	while(!q.empty()){
		oq=q.front();
		q.pop();
		for(int i=0;i<4;++i){
			next=Node(oq.x+dir[i][0],oq.y+dir[i][1],oq.time+1,oq.key);
			if(next.x<0 || next.y<0 || next.x>=n || next.y>=m)continue;
			if(mark[next.x][next.y][next.key] == flag || Map[next.x][next.y] == '*')continue;
			mark[next.x][next.y][next.key]=flag;
			if(next.time>=t)return -1;
			if(Map[next.x][next.y] == '^')return next.time;
			if(Map[next.x][next.y]>='A' && Map[next.x][next.y]<='Z'){
				int k=Map[next.x][next.y]-'A';
				if(next.key & (1<<k))q.push(next);//表示有这个钥匙A~J分别对应key里的第1~10位
				continue;
			}
			if(Map[next.x][next.y]>='a' && Map[next.x][next.y]<='z'){
				int k=Map[next.x][next.y]-'a';
				next.key=next.key | (1<<k);
			}
			q.push(next);
		}
	}
	return -1;
}

int main(){
	int num=0;
	while(cin>>n>>m>>t){
		for(int i=0;i<n;++i)cin>>Map[i];
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				if(Map[i][j] == '@'){start.x=i,start.y=j;start.time=start.key=0;}
			}
		}
		cout<<BFS(++num)<<endl;
	}
	return 0;
} 