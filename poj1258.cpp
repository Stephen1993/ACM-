#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

const int MAX=301;
int father[MAX],rank[MAX];
int sum;

typedef struct{
	int x;
	int y;
	int w;
}edge;
edge e[MAX*MAX/2];

int cmp(const void *a,const void *b){
	if((*(edge*)a).w==(*(edge*)b).w){
		if((*(edge*)a).x==(*(edge*)b).x){
			return (*(edge*)a).y-(*(edge*)b).y;
		}
		(*(edge*)a).x-(*(edge*)b).x;
	}
	return (*(edge*)a).w-(*(edge*)b).w;
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
	int n,m,k;
	while(scanf("%d",&n)!=EOF){
		k=0;
		sum=0;
		makeset(n);
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				scanf("%d",&m);
				if(i<j){
					e[k].x=i;
					e[k].y=j;
					e[k].w=m;
					k++;
				}
		    }
		}
		qsort(e,k,sizeof(edge),cmp);
		for(int i=0;i<k;++i){
           Union(e[i].x,e[i].y,e[i].w);
		}
		printf("%d\n",sum);
	}
	return 0;
}