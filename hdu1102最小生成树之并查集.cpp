#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=10001;
int father[MAX],rank[MAX];
int n,sum,road[MAX][MAX];
typedef struct{
	int x;
	int y;
	int l;
}edge;
edge e[MAX];
bool cmp(edge a,edge b){
	if(a.l==b.l){
		if(a.x==b.x)return a.y<b.y;
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
	if(father[v]!=v){
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
	int a,b,m;
	while(cin>>n){
		sum=0;
		int k=0;
		makeset(n);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				road[i][j]=k;
				cin>>a;
				e[k].x=i;
				e[k].y=j;
				e[k++].l=a;
			}
		}
		cin>>m;
		for(int i=0;i<m;++i){
			cin>>a>>b;
			e[road[a][b]].l=e[road[b][a]].l=0;
		}
		sort(e,e+k,cmp);
		for(int i=0;i<k;++i){
			if(e[i].x!=e[i].y)
			Union(e[i].x,e[i].y,e[i].l);
		}
		cout<<sum<<endl;
	}
	return 0;
}