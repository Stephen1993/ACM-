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

const int MAX=100000+10;
int father[MAX+MAX*10],rank[MAX+MAX*10],node[MAX],sum;

void makeset(int num){
	for(int i=0;i<=num;++i){
		father[i]=i;
		rank[i]=1;
	}
}

int findset(int v){
	if(v != father[v])father[v]=findset(father[v]);
	return father[v];
}

void Union(int x,int y){
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
	--sum;
}

bool Delete(int x){
	int a=findset(x);
	if(rank[a]>1){
		++sum;
		--rank[a];
		return true;
	}
	return false;
} 

int main(){
	int n,m,a,b,num=0;
	char s;
	while(scanf("%d%d",&n,&m),n+m){
		makeset(n+m);
		for(int i=0;i<=n;++i)node[i]=i;
		sum=n;
		for(int i=0;i<m;++i){
			getchar();scanf("%c",&s);
			if(s == 'M'){
				scanf("%d%d",&a,&b);
				Union(node[a],node[b]);
			}
			else{
				scanf("%d",&a);
				if(Delete(node[a]))node[a]=++n;//开辟新点作为a对应的点 
			}
		} 
		printf("Case #%d: %d\n",++num,sum);
	}
	return 0;
} 