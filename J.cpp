#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<iomanip>
#include<limits.h> 
using namespace std;
const int MAX=111111;
int father[MAX],rank[MAX];
int sum;
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
void Union(int x,int y,int l){
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
	sum+=l;
}
int main(){
	int p,r,l,a,b;
	while(cin>>p,p){
		cin>>r;
		sum=0;
		makeset(r);
		for(int i=0;i<r;++i){
			scanf("%d%d%d",&a,&b,&l);
			e[i].x=a;
			e[i].y=b;
			e[i].w=l;
		}
		qsort(e,r,sizeof(edge),cmp);
		for(int i=0;i<r;++i){
			Union(e[i].x,e[i].y,e[i].w);
		}
		cout<<sum<<endl;
	}
	return 0;
}