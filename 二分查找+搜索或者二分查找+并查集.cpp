//http://codeforces.com/contest/366/problem/D 
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
using namespace std;

const int MAX=1000+10;
int head[MAX],size,n,m;
bool mark[MAX];

struct Node{
    int l,r;
    bool operator<(const Node &a)const{
        if(l == a.l)return r>a.r;
        return l<a.l;
    }
}s[3*MAX];

struct Edge{
    int v,next,l,r;
    Edge(){}
    Edge(int V,int NEXT,int L,int R):v(V),next(NEXT),l(L),r(R){}
}edge[6*MAX];

void Init(int num){
    for(int i=1;i<=num;++i)head[i]=-1;
    size=0;
}

void InsertEdge(int u,int v,int l,int r){
    edge[size]=Edge(v,head[u],l,r);
    head[u]=size++;
}

bool dfs(int u,int l,int r){
    if(u == n)return true;
    mark[u]=true;
    for(int i=head[u];i != -1;i=edge[i].next){
        if(mark[edge[i].v])continue;
        if(edge[i].l>l || edge[i].r<r)continue;
        if(dfs(edge[i].v,l,r))return true;
    }
    return false;
}

int main(){
    int u,v,l,r;
    while(cin>>n>>m){
        Init(n);
        for(int i=1;i<=m;++i){
            scanf("%d%d%d%d",&u,&v,&l,&r);
            s[i].l=l,s[i].r=r;
            InsertEdge(u,v,l,r);
            InsertEdge(v,u,l,r);
        }
        sort(s+1,s+1+m);
        int sum=0,mid=0;
        for(int i=1;i<=m;++i){
            l=s[i].l+sum,r=s[i].r;
            if(r<l || s[i].l == s[i-1].l)continue;
            while(l<=r){
                mid=l+r>>1;
                memset(mark,false,sizeof mark);
                if(dfs(1,s[i].l,mid))l=mid+1;
                else r=mid-1;
            }
            if(r-s[i].l+1>sum)sum=r-s[i].l+1;
        } 
        if(sum)cout<<sum<<endl;
        else cout<<"Nice work, Dima!"<<endl;
    }
    return 0;
}
/*
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
using namespace std;

const int MAX=1000+10;
int father[MAX],rank[MAX];

struct Edge{
	int u,v,l,r;
	bool operator<(const Edge &a)const{
		return l<a.l;
	}
}edge[3*MAX];

void makeset(int num){
	for(int i=1;i<=num;++i)father[i]=i,rank[i]=1;
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
	}else{
		father[a]=b;
		rank[b]+=rank[a];
	}
}

int main(){
	int n,m;
	while(cin>>n>>m){
		for(int i=0;i<m;++i){
			cin>>edge[i].u>>edge[i].v>>edge[i].l>>edge[i].r;
		}
		sort(edge,edge+m);
		int sum=0;
		for(int i=0;i<m;++i){
			makeset(n);
			for(int j=0;j<m;++j)if(edge[j].r>=edge[i].r){
				Union(edge[j].u,edge[j].v);
				if(findset(1) == findset(n)){sum=max(sum,edge[i].r-edge[j].l+1);break;}
			}
		}
		if(sum)cout<<sum<<endl;
		else cout<<"Nice work, Dima!"<<endl;
	}
	return 0;
}
*/ 