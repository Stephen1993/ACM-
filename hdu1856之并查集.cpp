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

const int MAX=10000000+10;
int father[MAX],rank[MAX],s[100000+10][2];

void makeset(int num){
	for(int i=1;i<=num;++i){
		father[s[i][0]]=s[i][0];
		father[s[i][1]]=s[i][1];
		rank[s[i][0]]=rank[s[i][1]]=1;
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
}

int main(){
	int n,a,b;
	while(scanf("%d",&n)!=EOF){
		if(n == 0){cout<<"1"<<endl;continue;}
		for(int i=0;i<n;++i){
			scanf("%d%d",&s[i][0],&s[i][1]);
		}
		makeset(n);
		for(int i=0;i<n;++i)Union(s[i][0],s[i][1]);
		int sum=0;
		for(int i=1;i<=n;++i)sum=max(sum,max(rank[s[i][0]],rank[s[i][1]]));
		printf("%d\n",sum);
	}
	return 0;
} 