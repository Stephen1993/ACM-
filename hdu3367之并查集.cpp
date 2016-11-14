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

const int MAX=10000+10;
int father[MAX],rank[MAX],sum;
bool mark[MAX];

typedef struct{
	int x,y,l;
}edge;
edge e[MAX*10];

bool cmp(edge a,edge b){
	return a.l>b.l;
}

void makeset(int num){
	for(int i=0;i<=num;++i){
		father[i]=i;
		rank[i]=1;
		mark[i]=false;
	}
	sum=0;
}

int findset(int v){
	if(v != father[v]){
		father[v]=findset(father[v]);
	}
	return father[v];
}

void Union(int x,int y,int l){
	int a=findset(x);
	int b=findset(y);
	if(a == b){
		if(!mark[a])sum+=l,mark[a]=true;
	} 
	else{
		if(!mark[a] || !mark[b]){
			if(rank[a]>rank[b]){
				father[b]=a;
				rank[a]+=rank[b];
				mark[a]=(mark[a] || mark[b]);
			}
			else{
				father[a]=b;
				rank[b]+=rank[a];
				mark[b]=(mark[a] || mark[b]);
			}
			sum+=l;
		}
	}
}

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m),n+m){
		makeset(n);
		for(int i=0;i<m;++i){
			scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].l);
		}
		sort(e,e+m,cmp);
		for(int i=0;i<m;++i){
			Union(e[i].x,e[i].y,e[i].l);
		}
		printf("%d\n",sum);
	}
	return 0;
}