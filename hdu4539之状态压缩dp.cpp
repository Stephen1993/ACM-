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

const int MAX=169+10;
int n,m,lastsize,nowsize,lastlastsize;
int Map[110][15],last[MAX],lastlast[MAX],ans[MAX];
int dp[MAX][MAX],temp[MAX][MAX],now[MAX];

void dfs(int id,int k,int p,int sum){
    if(k>=m){now[++nowsize]=p;ans[nowsize]=sum;return;}
    if(k>=2 && Map[id][k] == 1 && (p & (1<<(k-2))) == 0)dfs(id,k+1,p|(1<<k),sum+1);
    else if(k<2 && Map[id][k] == 1)dfs(id,k+1,p|(1<<k),sum+1);
    dfs(id,k+1,p,sum);
}

void DP(){
    temp[1][1]=last[1]=lastlast[1]=0;
    lastsize=nowsize=lastlastsize=1;
    for(int k=0;k<n;++k){
        nowsize=0;
        dfs(k,0,0,0);
        for(int i=1;i<=nowsize;++i)for(int j=1;j<=lastsize;++j)dp[i][j]=0;
        for(int i=1;i<=nowsize;++i){
            for(int j=1;j<=lastsize;++j){
                for(int t=1;t<=lastlastsize;++t){
                    if(now[i] & lastlast[t])continue;
                    if(now[i] & (last[j]<<1))continue;
                    if(now[i] & (last[j]>>1))continue;
                    dp[i][j]=max(dp[i][j],temp[j][t]+ans[i]);
                }
            }
        }
        for(int i=1;i<=nowsize;++i)for(int j=1;j<=lastsize;++j)temp[i][j]=dp[i][j];
        for(int i=1;i<=lastsize;++i)lastlast[i]=last[i];
        for(int i=1;i<=nowsize;++i)last[i]=now[i];
        lastlastsize=lastsize,lastsize=nowsize;
    }
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j)scanf("%d",&Map[i][j]);
		}
		DP();
		int sum=0;
		for(int i=1;i<=lastsize;++i)for(int j=1;j<=lastlastsize;++j)sum=max(sum,temp[i][j]);
		cout<<sum<<endl;
	}
	return 0;
}