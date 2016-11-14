/*
典型的最短路;
大家看看我的代码，注意dijkstra怎么写;
*/
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

template<class T> bool up_min(T& a,const T& b){return b<a? a=b,1 : 0;}
#define maxn 110
const int inf= 1000000000;

int n,m;
int g[maxn][maxn];

bool vis[maxn];
int dis[maxn];
int dijkstra(){
    for(int i=1;i<=n;++i) dis[i]= inf, vis[i]= 0;
    dis[1]= 0, vis[1]= 1;  // 源点要初始化到;
    for(int i=2;i<=n;++i) dis[i]= g[1][i];

    while(1){
        int mindis= inf, idx= -1;
        for(int i=2;i<=n;++i)
            if( !vis[i] && up_min( mindis, dis[i] ) )
                idx= i;

        if( n==idx ) return dis[n]; // 找到终点了直接返回距离;
        vis[idx]= 1;

        for(int i=2;i<=n;++i)
            if( !vis[i] )
                up_min( dis[i], dis[idx]+g[idx][i] );
    }
}

int main()
{
    //freopen(".in","r",stdin);
    while( cin>>n>>m, n+m ){
        int i,j,u,v,w;
        for(i=1;i<=n;++i)for(j=1;j<=n;++j)g[i][j]= inf;
        while( m-- ){
            scanf("%d%d%d", &u, &v, &w);
            if( up_min( g[u][v], w ) )
                g[v][u]= w;
        }
        cout<< dijkstra() <<endl;
    }
}