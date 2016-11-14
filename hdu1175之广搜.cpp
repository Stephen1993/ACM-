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
const int MAX=1001;
int s[MAX][MAX];
int dir[4][2]={1,0,-1,0,0,1,0,-1};
typedef struct{
	int x;
	int y;
	int last;//·½Ïò. 
	int time;
}noto;
int sum[MAX][MAX];
noto start;
int n,m,x1,y1,x2,y2;
bool bfs(){
	queue<noto>enqueue;
	noto outqueue,next;
	start.x=x1,start.y=y1;
	start.time=0,start.last=-1;
	sum[x1][y1]=0;
	enqueue.push(start);
	while(!enqueue.empty()){
		outqueue=enqueue.front();
		enqueue.pop();
		for(int i=0;i<4;++i){
			next.x=outqueue.x+dir[i][0];
			next.y=outqueue.y+dir[i][1];
			next.last=i;
			if(outqueue.last==i||outqueue.last==-1)
				next.time=outqueue.time;
			else
				next.time=outqueue.time+1;
			if(next.x<1||next.y<1||next.x>n||next.y>m||next.time>2||(s[next.x][next.y]!=0&&(next.x!=x2||next.y!=y2))||next.time>sum[next.x][next.y])
			  continue;
	        sum[next.x][next.y]=next.time;
	        if(next.x==x2&&next.y==y2)return true;
	        enqueue.push(next);
		}
	}
	return false;
}
int main(){
	while(cin>>n>>m,n||m){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				scanf("%d",&s[i][j]);
			}
		}
		int p;
		cin>>p;
		while(p--){
			for(int i=1;i<=n;++i){
				for(int j=1;j<=m;++j){
					sum[i][j]=INF;
				}
			}
			cin>>x1>>y1>>x2>>y2;
			if(s[x1][y1]!=s[x2][y2]||(x1==x2&&y1==y2)||s[x1][y1]==0)cout<<"NO"<<endl;
			else if(bfs())cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
	return 0;
}