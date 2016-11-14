#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
const int MAX=300;
int sum;
int father[MAX],rank[MAX];
typedef struct{
	int x;
	int y;
	int w;
}edge;
edge e[MAX*MAX];
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
	for(int i=0;i<num;++i){
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
	sum+=L;
}
int main(){
	int n,m,b;
	char a;
	while(cin>>n,n){
		makeset(n);
		int k=0;
		sum=0;
		for(int i=0;i<n-1;++i){
			cin>>a>>m;
			for(int j=0;j<m;++j){
				cin>>a>>b;
				e[k].x=i;
				e[k].y=a-'A';
				e[k++].w=b;
			}
		}
		qsort(e,k,sizeof(edge),cmp);
		for(int i=0;i<k;++i){
			Union(e[i].x,e[i].y,e[i].w);
		}
		cout<<sum<<endl;
	}
	return 0;
}