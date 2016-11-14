#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=101;
int father[MAX],rank[MAX];
typedef struct{
	int x;
	int y;
	int l;
}edge;
edge e[MAX*(MAX+1)/2];
int n,sum;
bool cmp(edge a,edge b){
	if(a.l==b.l){
		if(a.x==b.x){
			return a.y<b.y;
		}
		return a.x<b.y;
	}
	return a.l<b.l;
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
	while(cin>>n,n){
		sum=0;
		makeset(n);
		for(int i=0;i<n*(n-1)/2;++i){
			scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].l);
		}
		sort(e,e+n*(n-1)/2,cmp);
		for(int i=0;i<n*(n-1)/2;++i){
			Union(e[i].x,e[i].y,e[i].l);
		}
		cout<<sum<<endl;
	}
	return 0;
}