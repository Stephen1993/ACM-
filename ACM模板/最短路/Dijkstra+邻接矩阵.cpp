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

const int MAX=111;
int dist[MAX][MAX];
int n,m;
bool mark[MAX];

int Dijkstra(int s,int t){
	for(int i=1;i<=n;++i)mark[i]=false;
	mark[s]=true;
	while(1){
		int point=t;
		for(int i=1;i<=n;++i){
			if(!mark[i] && dist[s][point]>dist[s][i])point=i;
		}
		if(point == t)return dist[s][t];
		mark[point]=true;
		for(int i=1;i<=n;++i){
			if(!mark[i])dist[s][i]=min(dist[s][i],dist[s][point]+dist[point][i]);
		}
	}
}

int main(){
	int u,v,w;
	while(cin>>n>>m,n || m){
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				dist[i][j]=dist[j][i]=INF;
			}
		}
		for(int i=0;i<m;++i){
			cin>>u>>v>>w;
			dist[u][v]=dist[v][u]=w;
		}
		cout<<Dijkstra(1,n)<<endl;
	}
	return 0;
}