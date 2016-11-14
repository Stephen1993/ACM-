#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=(1<<16)+10;
int n,m,val,h;
int s[20],c[20],d[20];
int dp[MAX][20],dist[110][110];

void Init(int num){
	for(int i=0;i<=num;++i){
		for(int j=i+1;j<=num;++j)dist[i][j]=dist[j][i]=INF;
	}
}

void floyd(){
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
			}
		}
	}
}

void DP(){
	int bit=1<<(h+1);
	memset(dp,-1,sizeof dp);
	dp[1][0]=val;
	for(int i=1;i<bit;++i){
		for(int j=0;j<=h;++j){
			if(dp[i][j] == -1)continue;
			for(int k=1;k<=h;++k){
				if(dp[i][j]<dist[s[j]][s[k]]+d[k])continue;
				int p=1<<k,w=c[k]-d[k];
				if(i&p)continue;
				dp[i|p][k]=max(dp[i|p][k],dp[i][j]-dist[s[j]][s[k]]+w);
			}
		}
	}
	bool flag=false;
	for(int i=0;i<=h;++i)if(dp[bit-1][i]-dist[s[i]][1]>=0)flag=true;
	if(flag)printf("YES\n");
	else printf("NO\n");
}

int main(){
	int t,u,v,w;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&m,&val);
		Init(n);
		for(int i=0;i<m;++i){
			scanf("%d%d%d",&u,&v,&w);
			dist[u][v]=dist[v][u]=min(dist[u][v],w);
		}
		scanf("%d",&h);
		for(int i=1;i<=h;++i){
			scanf("%d%d%d",&s[i],&c[i],&d[i]);
		}
		floyd();
		s[0]=1,c[0]=d[0]=0;
		DP();
	}
	return 0;
}