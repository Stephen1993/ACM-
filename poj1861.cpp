#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int MAX=15001;
int father[MAX],rank[MAX];
int max_w,k;
typedef struct{
	int x;
	int y;
	int w;
}edge;
edge e[MAX],jiru[MAX];
bool cmp(edge a,edge b){
	if(a.w==b.w){
		if(a.x==b.x){
			return a.y<b.y;
		}
		return a.x<b.x;
	}
	return a.w<b.w;
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
	if(max_w<L)max_w=L;
	jiru[k].x=x;
	jiru[k++].y=y;
}
int main(){
	int n,m;
    	scanf("%d%d",&n,&m);
		makeset(n);
		max_w=k=0;
		for(int i=0;i<m;++i){
			scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].w);
		}
		sort(e,e+m,cmp);
		for(int i=0;i<m;++i){
			Union(e[i].x,e[i].y,e[i].w);
		}
		printf("%d\n%d\n",max_w,k);
		for(int i=0;i<k;++i){
			printf("%d %d\n",jiru[i].x,jiru[i].y);
		}
	return 0;
}