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

const int MAX=27;
int father[MAX],rank[MAX],sum;

typedef struct{
	int x;
	int y;
	int l;
}edge;
edge e[MAX*MAX];

bool cmp(edge a,edge b){
	if(a.l == b.l){
		if(a.x == b.x){
			return a.y < b.y;
		}
		return a.x < b.y;
	}
	return a.l < b.l;
}

void makeset(int num){
	for(int i=0;i<num;++i){
		father[i]=i;
		rank[i]=1;
	}
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
	if(a == b)return;
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
	int n,b,l;
	char a;
	while(cin>>n,n){
		int k=0;
		sum=0;
		makeset(n);
		for(int i=0;i<n-1;++i){
			cin>>a>>b;
			for(int j=0;j<b;++j){
				cin>>a>>l;
				e[k].x=i,e[k].y=a-'A',e[k++].l=l;
			}
		}
		sort(e,e+k,cmp);
		for(int i=0;i<k;++i){
			Union(e[i].x,e[i].y,e[i].l);
		}
		cout<<sum<<endl;
	}
	return 0;
}