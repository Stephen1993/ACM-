#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#include<vector>
#define INF 99999999
using namespace std;

const int MAX=1001;
int n,m,father[MAX],rank[MAX];
int degree[MAX],sum;

void makeset(int num){
	for(int i=1;i<=num;++i){
		father[i]=i;
		rank[i]=1;
	}
}

int findset(int v){
	if(v != father[v])father[v]=findset(father[v]);
	return father[v];
}

void Union(int a,int b){
	int x=findset(a);
	int y=findset(b);
	if(x == y)return;
	if(rank[x]<rank[y]){
		father[x]=y;
		rank[y]+=rank[x];
	}
	else{
		father[y]=x;
		rank[x]+=rank[y];
	}
	--sum;
}

int main(){
	int a,b;
	while(cin>>n,n){
		cin>>m;
		memset(degree,0,sizeof degree);
		makeset(n);
		sum=n;
		for(int i=0;i<m;++i){
			scanf("%d%d",&a,&b);
			++degree[a];
			++degree[b];
			Union(a,b);
		}
		if(sum == 1){
			while(n){
				if(degree[n]&1){cout<<"0"<<endl;break;}
				--n;
			}
			if(!n)cout<<"1"<<endl;
		}else cout<<"0"<<endl;
	}
	return 0;
}