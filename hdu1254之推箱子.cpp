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

const int MAX=10;
short map1[MAX][MAX];
bool flag,dire[MAX][MAX][4],mark[MAX][MAX];
short dir[4][2]={1,0,0,1,-1,0,0,-1};
int sum,n,m;
short peo_x,peo_y,pox_x,pox_y;

typedef struct{
	short pel_x;
	short pel_y;
	short x;
	short y;
	int time;
}node;
node start;

void DFS(short x,short y,short end_x,short end_y){
	if(x==end_x&&y==end_y){flag=true;return;}
	mark[x][y]=true;
	for(int i=0;i<4;++i){
		int a=x+dir[i][0];
		int b=y+dir[i][1];
		if(a>=0&&b>=0&&a<m&&b<n&&!mark[a][b]&&(map1[a][b]==0||map1[a][b]==4||map1[a][b]==3))DFS(a,b,end_x,end_y);
		if(flag)return;
	}
	return;
}

void BFS(){
	memset(dire,false,sizeof dire);
	queue<node>enqueue;
	node next,outqueue;
	start.x=pox_x,start.y=pox_y,start.time=0,start.pel_x=peo_x,start.pel_y=peo_y;
	enqueue.push(start);
	while(!enqueue.empty()){
		outqueue=enqueue.front();
		map1[outqueue.x][outqueue.y]=2;
		enqueue.pop();
		for(int i=0;i<4;++i){
			next.x=outqueue.x+dir[i][0];
			next.y=outqueue.y+dir[i][1];
			next.time=outqueue.time+1;
			next.pel_x=outqueue.x;
			next.pel_y=outqueue.y;
			memset(mark,false,sizeof mark);
			flag=false;
			if(next.x<0||next.y<0||next.x>=m||next.y>=n||map1[next.x][next.y]==1||dire[next.x][next.y][(i+2)%4]||
			   map1[outqueue.x+dir[(i+2)%4][0]][outqueue.y+dir[(i+2)%4][1]]==1)continue;
			DFS(outqueue.x+dir[(i+2)%4][0],outqueue.y+dir[(i+2)%4][1],outqueue.pel_x,outqueue.pel_y);
			if(!flag)continue;
            if(map1[next.x][next.y]==3){
            	sum=next.time;
            	return;
            } 
            dire[next.x][next.y][(i+2)%4]=true;
            enqueue.push(next);
		}
		map1[outqueue.x][outqueue.y]=0;
	}
	return;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>m>>n;
		for(int i=0;i<m;++i){
			for(int j=0;j<n;++j){
				cin>>map1[i][j];
				if(map1[i][j]==2)pox_x=i,pox_y=j;
				if(map1[i][j]==4)peo_x=i,peo_y=j;
			}
		}
		sum=-1;
		BFS();
		cout<<sum<<endl;
	}
	return 0;
}