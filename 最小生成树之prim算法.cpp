#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define maxn 105
const int inf = 1000000000;

int n,m;
int g[maxn][maxn];

bool mark[maxn];
int dis[maxn];
int Prim(int st){
    for(int i=1;i<=n;++i) mark[i]= 0, dis[i]= g[st][i]; // 初始化;
    mark[st]= 1;
    dis[st]= 0;
    int cost= 0;  // 总的花费;
    for(int times=1; times<n; ++times){ // 循环n-1次;
        int mindis= inf, id= -1;
        for(int i=1;i<=n;++i)
            if( !mark[i] && mindis>dis[i] )
                mindis= dis[i], id= i;

        if( id == -1 ) return -1; // 在循环结束前就找不到新的点了，那么说明无法构成MST;
        mark[id]= 1;
        cost += dis[id];

        for(int i=1;i<=n;++i)  // 用新加入的点去更新其他未加入的点;
            if( !mark[i] )
                if( dis[i] > g[id][i] )
                    dis[i]= g[id][i];
    }
    return cost;
}

int main()
{
    //freopen("A.in","r",stdin);
    while( cin>>m>>n, m ){
        for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)g[i][j]= inf;
        while(m--){
            int x,y,w;
            scanf("%d%d%d", &x,&y,&w);
            if( g[x][y] > w )   // 有些题目会有这样的trick，存在重边，那么应该取最短的;
                g[x][y]= g[y][x]= w;
        }

        int ans= Prim(1);
        if( -1 == ans ) puts("?");
        else printf("%d\n", ans);
    }
}
