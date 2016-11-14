
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

const int MAX=200+10;
int father[MAX],rank[MAX];

typedef struct{
    int x,y,l;
}edge;
edge e[1000+10];

bool cmp(edge a,edge b){
    return a.l>b.l;
}

void makeset(int num){
    for(int i=0;i<=num;++i){
        father[i]=i;
        rank[i]=1;
    }
}

int findset(int v){
    if(v != father[v])father[v]=findset(father[v]);
    return father[v];
}

void Union(int x,int y){
    int a=findset(x);
    int b=findset(y);
    if(a == b)return;
    if(rank[a]>rank[b]){
        father[b]=a;
        rank[a]+=rank[b];
    }
    else{
        father[a]=b;
        rank[b]+=rank[a];
    }
}

int main(){
    int n,m,Q,s,t,k;
    while(cin>>n>>m){
        for(int i=0;i<m;++i){
            scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].l);
        }
        sort(e,e+m,cmp);//对这些树根进行从大到小排序/或从小到大 
        scanf("%d",&Q);
        for(int i=0;i<Q;++i){
            scanf("%d%d",&s,&t);
            int Min=INF;
            for(int j=0;j<m;++j){//从第j个树根开始合并一条路是否s -> t 
                makeset(n);
                for(k=j;k<m;++k){
                    Union(e[k].x,e[k].y);
                    if(findset(s) == findset(t))break;
                } 
                if(k != m)Min=Min<e[j].l-e[k].l?Min:e[j].l-e[k].l;
                else break;
            }
            if(Min == INF)cout<<"-1\n";
            else cout<<Min<<endl;
        }
    }
    return 0;
}
 



