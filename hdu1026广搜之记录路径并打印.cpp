#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=111;
char s[MAX][MAX];
int record[MAX*MAX][3];
vector<int>x;
vector<int>y;
vector<int>t;
vector<int>fight;
int dir[4][2]={1,0,-1,0,0,1,0,-1}; 
typedef struct point{
	int x;
	int y;
	int time;
	bool operator<(const point &a)const{
		return time>a.time;
	}
};
point start;
int n,m;
void BFS(){
	start.x=start.y=start.time=0;
	record[0][0]=-1;
	priority_queue<point>enqueue;
	point next,outqueue;
	enqueue.push(start);
	while(!enqueue.empty()){
		outqueue=enqueue.top();
		enqueue.pop();
		for(int i=0;i<4;++i){
			next.x=outqueue.x+dir[i][0];
			next.y=outqueue.y+dir[i][1];
			next.time=outqueue.time+1;
			if(next.x<0||next.y<0||next.x>=n||next.y>=m||s[next.x][next.y]=='X')continue;
			record[(next.x)*m+next.y][0]=(outqueue.x)*m+outqueue.y;
			record[(next.x)*m+next.y][1]=next.time;
			record[(next.x)*m+next.y][2]=0;
			if(s[next.x][next.y]!='.'){
			   next.time+=(s[next.x][next.y]-'0');
			   record[(next.x)*m+next.y][2]=(s[next.x][next.y]-'0');
			}
			if(next.x==n-1&&next.y==m-1){
				printf("It takes %d seconds to reach the target position, let me show you the way.\n",record[n*m-1][1]+record[n*m-1][2]);
				x.clear();
				y.clear();
				t.clear();
				fight.clear();
				for(int u=m*n-1;u!=-1;u=record[u][0]){
					x.push_back(u/m);
					y.push_back(u%m);
					t.push_back(record[u][1]);
					fight.push_back(record[u][2]);
				}
				for(int j=x.size()-1;j>0;j--){
					printf("%ds:(%d,%d)->(%d,%d)\n",t[j-1],x[j],y[j],x[j-1],y[j-1]);
					for(int k=1;k<=fight[j-1];++k){
						printf("%ds:FIGHT AT (%d,%d)\n",t[j-1]+k,x[j-1],y[j-1]);
					}
				}
				return;
			}
			s[next.x][next.y]='X';
			enqueue.push(next);
		}
	}
	cout<<"God please help our poor hero."<<endl;
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		for(int i=0;i<n;++i){
			cin>>s[i];
		}
		s[0][0]='X';
		BFS();
		cout<<"FINISH"<<endl;
	}
	return 0;
}