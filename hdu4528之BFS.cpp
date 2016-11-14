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
bool DR[MAX],DC[MAX],ER[MAX],EC[MAX];//分别表示能看到大明和二明的行和列
int mark[MAX][MAX][2][2];
int n,m,t,dr,dc,er,ec;//记录D,E所在的行列 
int dir[4][2]={0,1,0,-1,1,0,-1,0};

struct Node{
	int x,y,t;
	bool d,e;
	Node(){}
	Node(int X,int Y,int T,bool D,bool E):x(X),y(Y),t(T){d=D,e=E;}
}start;

void Init(int &n,int &m){
	memset(DR,false,sizeof(bool)*(n+1));
	memset(ER,false,sizeof(bool)*(n+1));
	memset(DC,false,sizeof(bool)*(m+1));
	memset(EC,false,sizeof(bool)*(m+1));
}

void Mark(int i,int j,bool *flagR,bool *flagC){
	int x=i,y=j;
	while(++x<n && (Map[x][j] == '.' || Map[x][j] == 'S'))flagR[x]=true;
	while(++y<m && (Map[i][y] == '.' || Map[i][y] == 'S'))flagC[y]=true;
	x=i,y=j;
	while(--x>=0 && (Map[x][j] == '.' || Map[x][j] == 'S'))flagR[x]=true;
	while(--y>=0 && (Map[i][y] == '.' || Map[i][y] == 'S'))flagC[y]=true;
}

void check(bool &d,bool &e,int x,int y){//判断该行该列是否有大明二明 
	d=((DR[x] && dc == y) || (DC[y] && dr == x) || d);
	e=((ER[x] && ec == y) || (EC[y] && er == x) || e);
}

int BFS(int &flag){
	check(start.d,start.e,start.x,start.y);
	if(start.d && start.e)return 0;
	queue<Node>q;
	Node oq,next;
	q.push(start);
	mark[start.x][start.y][start.d][start.e]=flag;
	while(!q.empty()){
		oq=q.front();
		q.pop();
		if(oq.t>=t)return -1;
		for(int i=0;i<4;++i){
			next=Node(oq.x+dir[i][0],oq.y+dir[i][1],oq.t+1,oq.d,oq.e);
			if(next.x<0 || next.y<0 || next.x>=n || next.y>=m)continue;
			if(Map[next.x][next.y] != '.' || mark[next.x][next.y][next.d][next.e] == flag)continue;
			mark[next.x][next.y][next.d][next.e]=flag;
			check(next.d,next.e,next.x,next.y);
			if(next.d && next.e)return next.t;
			q.push(next);
		}
	} 
	return -1;
}

int main(){
	int T,num=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&t);
		Init(n,m);
		for(int i=0;i<n;++i)scanf("%s",Map[i]);
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				if(Map[i][j] == 'S')start=Node(i,j,0,0,0);
				else if(Map[i][j] == 'D')dr=i,dc=j,Mark(i,j,DR,DC);
				else if(Map[i][j] == 'E')er=i,ec=j,Mark(i,j,ER,EC);
			}
		}
		int Time=BFS(++num);
		printf("Case %d:\n%d\n",num,Time);
	}
	return 0;
}