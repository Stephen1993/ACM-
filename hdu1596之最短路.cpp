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
double dist[MAX][MAX];
bool mark[MAX];
int n,m,s,t;

void dijkstra(int s,int t){
	for(int i=1;i<=n;++i)mark[i]=false;
	mark[s]=true;
	while(1){
		int point=t;
		for(int i=1;i<=n;++i){
			if(!mark[i] && dist[s][i]>dist[s][point])point=i;
		}
		if(point == t)return;
		mark[point]=true;
		for(int i=1;i<=n;++i){
			if(!mark[i])dist[s][i]=max(dist[s][i],dist[s][point]*dist[point][i]);
		}
	}
}

int main(){
	while(scanf("%d",&n)!=EOF){
		memset(dist,0,sizeof dist);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j)scanf("%lf",&dist[i][j]);
		}
		scanf("%d",&m);
		for(int i=0;i<m;++i){
			scanf("%d%d",&s,&t);
			dijkstra(s,t);
			if(dist[s][t] == 0.0)cout<<"What a pity!"<<endl;
			else cout<<fixed<<setprecision(3)<<dist[s][t]<<endl;
		}
	}
	return 0;
}