#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=100+10;
int n,m,size,w[MAX],val[MAX];
int dp[MAX][MAX],head[MAX];

struct Edge{
    int v,next;
    Edge(){}
    Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[MAX*2];

void Init(int num){
    for(int i=0;i<=num;++i){
        head[i]=-1;
        for(int j=0;j<=m;++j)dp[i][j]=0;
    }
    size=0;
}

void InsertEdge(int u,int v){
    edge[size]=Edge(v,head[u]);
    head[u]=size++;
}

void dfs(int u,int father){
    for(int i=head[u];i != -1;i=edge[i].next){
        int v=edge[i].v,num=w[v]/20+(w[v]%20?1:0);
        if(v == father)continue;
        dfs(v,u);
        for(int j=m;j>=0;--j){
            for(int k=max(1,num);k+j<=m;++k){//k=max(1,num)表示至少要消耗1个士兵 
                dp[u][j+k]=max(dp[u][j+k],dp[u][j]+dp[v][k-num]+val[v]);
            }
        }
    }
}

int main(){
    int u,v;
    while(scanf("%d%d",&n,&m),n+m != -2){
        Init(n);
        InsertEdge(0,1);
        for(int i=1;i<=n;++i)scanf("%d%d",&w[i],&val[i]);
        for(int i=1;i<n;++i)scanf("%d%d",&u,&v),InsertEdge(u,v),InsertEdge(v,u);
        dfs(0,-1);
        cout<<dp[0][m]<<endl;
    }
    return 0;
}
/*
Input:
5 2
0 1
0 1
0 5
0 1
0 2
1 2
1 3
2 4
2 5
Output:
9
*/