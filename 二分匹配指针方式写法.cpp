/*
二分图最大匹配模版题，hdu也有此题，
但这题我记得在fzu上的是不可以用邻接矩阵来做，反正当时我提交是超时了，所以学习了邻接表，用邻接表来表示图，在遍历的时候可以很快。

其次下面的模版中我加了段，那个东西叫初始化贪心匹配，也是用来优化加速的，很多二分图匹配题给的图如果是很多点，很多边的话，用邻接表存图，再初始化贪心匹配的话就可以避免超时。

邻接表的表示可以用下面的写法，或者vector来写，自行百度吧，不会的可以问，这个每个人必须会。
*/

#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
#define MM(a,b) memset(a,b,sizeof(a));
typedef long long lld;
typedef unsigned long long u64;
#define maxn 1010

void up_min(int &x,int y){if((x>y)||(x==-1))x=y;}
int n, top;
struct Edge{
    int v;
    Edge *next;
}*adj[maxn+maxn], edge[maxn*maxn];
void Addedge(int u,int v){
    Edge *p= &edge[++top];
    p->v= v;
    p->next= adj[u];
    adj[u]= p;
}

int mate[maxn+maxn];
bool vis[maxn+maxn];
bool Find(int u){
    for(Edge *p=adj[u];p;p=p->next){
        int v= p->v;
        if( !vis[v] ){
            vis[v]=1;
            if( mate[v]== -1 || Find( mate[v] ) ){
                mate[v]= u;
                return 1;
            }
        }
    }
    return 0;
}
int MMG(){
    int i,ans=0;
    MM(mate,-1);
    for(i=0;i<n;++i){
        for(Edge *p= adj[i];p;p= p->next){
            if( mate[ p->v ]== -1 ){
                mate[i]= p->v;
                mate[ p->v ]= i;
                ++ans;
                break;
            }
        }
    }
    for(i=0;i<n;++i){
        if( mate[i]== -1 ){
            MM(vis,0);
            if( Find(i) ) ++ans;
        }
    }
    return ans;
}
int main()
{
    while(cin>>n){
        int i,u,v,t;
        top= 0;
        MM(adj,0);
        for(i=0;i<n;++i){
            scanf("%d: (%d)",&u,&t);
            while(t--){
                scanf("%d",&v);
                Addedge(u,v+n);
                Addedge(v+n,u);
            }
        }
        int ans= MMG();
        printf("%d\n", n- ans/2);
    }
}
