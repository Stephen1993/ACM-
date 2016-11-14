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

const int MAX=10000+10;
int n,m,size,top,index,ans1,ans2;
int head[MAX],dfn[MAX],low[MAX],stack[MAX];

struct Edge{
    int v,next;
    Edge(){}
    Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[MAX*20];

void Init(int num){
    for(int i=0;i<=num;++i)head[i]=-1,dfn[i]=0;
    size=top=index=ans1=ans2=0;
}

void InsertEdge(int u,int v){
    edge[size]=Edge(v,head[u]);
    head[u]=size++;
}

int tarjan(int u,int father){
    if(dfn[u])return 0;
    dfn[u]=low[u]=++index;
    stack[++top]=u;
    bool flag=true;
    int sum=0,num=0;
    for(int i=head[u];i != -1;i=edge[i].next){
        int v=edge[i].v;
        if(v == father && flag){flag=false;continue;}
        if(!dfn[v]){
            num=tarjan(v,u)+1;//num记录以v为根的树除去块剩余的边数
            low[u]=min(low[u],low[v]);
            if(low[v] >= dfn[u]){
            int k=2;
            while(stack[top] != v)++k,--top;--top;
                if(k<num && low[v] == dfn[u])ans2+=num;
                if(low[v]>dfn[u])++ans1;
                num=0;
            }
        } 
        else if(dfn[v]<dfn[u])num=1,low[u]=min(low[u],dfn[v]);
        else num=0;
        sum+=num;
    }
    if(dfn[u] == low[u])return 0;
    return sum;
}

int main(){
    int u,v;
    while(~scanf("%d%d",&n,&m),n+m){
        Init(n);
        for(int i=0;i<m;++i){
            scanf("%d%d",&u,&v);
            InsertEdge(u,v);
            InsertEdge(v,u);
        }
        for(int i=0;i<n;++i)tarjan(i,-1);
        printf("%d %d\n",ans1,ans2);
    }
    return 0;
}