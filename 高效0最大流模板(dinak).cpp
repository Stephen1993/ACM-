#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int oo=2e9;
const int mm=222222;
const int mn=111111;
int node,src,dest,edge;
int ver[mm],flow[mm],next[mm];
int head[mn],work[mn],h[mn],q[mn],gap[mn],p[mn],x[mn],y[mn];
void prepare(int _node,int _src,int _dest)
{
    node=_node,src=_src,dest=_dest;
    for(int i=0;i<node;++i)head[i]=-1;
    edge=0;
}
void addedge(int u,int v,int c)
{
    ver[edge]=v,flow[edge]=c,next[edge]=head[u],head[u]=edge++;
    ver[edge]=u,flow[edge]=c,next[edge]=head[v],head[v]=edge++;
}
void Isap_Pre()
{
    int i,u,v,l,r=0;
    for(i=0; i<node; ++i)h[i]=-1,gap[i]=0;
    gap[h[q[r++]=dest]=0]=1;
    for(l=0; l<r; ++l)
        for(i=head[u=q[l]]; i>=0; i=next[i])
            if(flow[i^1]&&h[v=ver[i]]<0)
                ++gap[h[q[r++]=v]=h[u]+1];
}
int Isap_flow()
{
    int i,u,ret=0,tmp,minh;
    Isap_Pre();
    for(i=0; i<node; ++i)work[i]=head[i];
    u=src;
    while(h[src]<node)
    {
        if(u==dest)
        {
            for(i=src,tmp=oo;i!=dest;i=ver[work[i]])
                tmp=min(tmp,flow[work[i]]);
            for(i=src;i!=dest;i=ver[work[i]])
                flow[work[i]]-=tmp,flow[work[i]^1]+= tmp;
            ret+=tmp,u=src;
        }
        int &e=work[u];
        for(;e>=0;e=next[e])
            if(flow[e]&&h[u]==h[ver[e]]+1)break;
        if(e>=0)p[u=ver[e]]=e^1;
        else
        {
            if(--gap[h[u]]==0)break;
            work[u]=head[u],minh=node;
            for(i=head[u];i>=0;i=next[i])
                if(flow[i])minh=min(minh,h[ver[i]]);
            ++gap[h[u]=minh+1];
            if(u!=src)u=ver[p[u]];
        }
    }
    return ret;
}
int main()
{
    int i,t,n,m,u,v,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;++i)
            scanf("%d%d",&x[i],&y[i]);
        u=v=1;
        for(i=2;i<=n;++i)
        {
            if(x[i]<x[u])u=i;
            if(x[i]>x[v])v=i;
        }
        prepare(n+1,u,v);
        while(m--)
        {
            scanf("%d%d%d",&u,&v,&c);
            addedge(u,v,c);
        }
        printf("%d\n",Isap_flow());
    }
    return 0;
}