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

const int MAX=200000+10;
int father[MAX],dist[MAX],sum=0;//dist表示离父节点的距离 

void makeset(int num){
	for(int i=1;i<=num;++i){
		father[i]=i,dist[i]=0;
	}
}

int findset(int v){
	if(v == father[v])return father[v];
	int temp=findset(father[v]);
	dist[v]+=dist[father[v]];//更新到父节点的距离,因为父节点会更新 
	father[v]=temp;//更新父节点 
	return father[v];
}

void Union(int x,int y,int l){
	int a=findset(x);
	int b=findset(y);
	if(a == b){
		if(dist[y]-dist[x] != l)++sum;
		return;
	}
	dist[b]=dist[x]+l-dist[y];
	father[b]=a;
}

int main(){
	int n,m,a,b,c;
	while(cin>>n>>m){
		sum=0;
		makeset(n);
		for(int i=0;i<m;++i){
			scanf("%d%d%d",&a,&b,&c);
			Union(a-1,b,c);
		}
		printf("%d\n",sum);
	}
	return 0;
}