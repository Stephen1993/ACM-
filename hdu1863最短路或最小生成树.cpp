#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<iomanip>
#include<algorithm>
#include<limits.h>
using namespace std;
const int MAX=111;
int father[MAX],rank[MAX],sum,all;
typedef struct{
	int x;
	int y;
	int w;
}edge;
edge e[MAX];
int cmp(const void *a,const void *b){
	edge *c=(edge*)a;
	edge *d=(edge*)b;
	if((*c).w==(*d).w){
		if((*c).x==(*d).x){
			return (*c).y-(*d).y;
		}
		return (*c).x-(*d).x;
	}
	return (*c).w-(*d).w;
}
void makeset(int num){
	for(int i=1;i<=num;++i){
		father[i]=i;
		rank[i]=1;
	}
}
int findset(int v){
	if(v!=father[v]){
		father[v]=findset(father[v]);
	}
	return father[v];
}
void Union(int x,int y,int L){
	int a=findset(x);
	int b=findset(y);
	if(a==b)return;
	if(rank[a]>rank[b]){
		father[b]=a;
		rank[a]+=rank[b];
	}
	else{
		father[a]=b;
		rank[b]+=rank[a];
	}
	all+=L;
	sum--;
}
int main(){
	int n,m;
	while(cin>>n>>m,n){
		sum=m;
		all=0;
		int a,b,l;
		makeset(m);
		for(int i=0;i<n;++i){
			scanf("%d%d%d",&a,&b,&l);
			e[i].x=a;
			e[i].y=b;
			e[i].w=l;
		}
		qsort(e,n,sizeof(edge),cmp);
		for(int i=0;i<n;++i){
			Union(e[i].x,e[i].y,e[i].w);
		}
		if(sum!=1){
			cout<<'?'<<endl;
		}
		else cout<<all<<endl;
	}
}