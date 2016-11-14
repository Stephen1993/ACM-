//http://acm.hdu.edu.cn/showproblem.php?pid=3371
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

const int MAX=500+10;
int father[MAX],rank[MAX];
int sum,num;

struct Edge{
	int u,v,w;
}edge[MAX*MAX/10];

bool cmp(Edge a,Edge b){
	return a.w<b.w;
}

void makeset(int num){
	for(int i=1;i<=num;++i){
		father[i]=i;
		rank[i]=1;
	}
}

int findset(int v){
	if(v != father[v])father[v]=findset(father[v]);
	return father[v];
}

void Union(int x,int y,int l){
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
	sum+=l;
	--num;
}

int main(){
	int n,m,k,t,d,a,b;
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		makeset(n);
		for(int i=0;i<m;++i){
			scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);
		}
		sum=0;
		num=n;
		for(int i=0;i<k;++i){
			scanf("%d%d",&d,&a);
			for(int j=0;j<d-1;++j){
				scanf("%d",&b);
				Union(a,b,0);
			}
		}
		if(num != 1){
			sort(edge,edge+m,cmp);
			for(int i=0;i<m;++i){
				Union(edge[i].u,edge[i].v,edge[i].w);
			}
		}
		if(num == 1)cout<<sum<<endl;
		else cout<<"-1"<<endl;
	}
	return 0;
}