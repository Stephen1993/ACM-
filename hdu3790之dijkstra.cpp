#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 999999999
using namespace std;

const int MAX=1001;
int dist[MAX][MAX][2];
int n,m;
bool mark[MAX];

void dijkstra(int s,int t){
	for(int i=1;i<=n;++i)mark[i]=false;
	mark[s]=true;
	while(1){
		int point=t;
		for(int i=1;i<=n;++i){
			if(!mark[i] && dist[s][i][0]<dist[s][point][0])point=i;
		}
		if(point == t)return;
		mark[point]=true;
		for(int i=1;i<=n;++i){
			if(!mark[i]){
				if(dist[s][i][0]>dist[s][point][0]+dist[point][i][0]){
					dist[s][i][0]=dist[s][point][0]+dist[point][i][0];
					dist[s][i][1]=dist[s][point][1]+dist[point][i][1];
				}
				else if(dist[s][i][0] == dist[s][point][0]+dist[point][i][0]){
					dist[s][i][1]=min(dist[s][i][1],dist[s][point][1]+dist[point][i][1]);
				}
			}
		}
	}
}

int main(){
	int a,b,c,d,s,t;
	while(cin>>n>>m,n || m){
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				dist[i][j][0]=dist[i][j][1]=dist[j][i][1]=dist[j][i][0]=INF;
			}
		}
		for(int i=0;i<m;++i){
			scanf("%d%d%d%d",&a,&b,&c,&d);
			if(c<dist[a][b][0]){
				dist[a][b][0]=dist[b][a][0]=c;
			    dist[a][b][1]=dist[b][a][1]=d;
			}
			else if(c == dist[a][b][0] && d<dist[a][b][1])dist[a][b][1]=dist[b][a][1]=d;
		}
		cin>>s>>t;
		dijkstra(s,t);
		cout<<dist[s][t][0]<<' '<<dist[s][t][1]<<endl;
	}
	return 0;
}