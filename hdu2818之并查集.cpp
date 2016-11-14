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

const int MAX=30000+10;
int father[MAX],rank[MAX],sum[MAX];//sum[i]表示i下面的积木个数 

void makeset(int num){
	for(int i=0;i<=num;++i){
		father[i]=i;
		rank[i]=1;
		sum[i]=0;
	}
}

int findset(int v){
	if(v == father[v])return father[v];
	int temp=findset(father[v]);
	sum[v]+=sum[father[v]];
	father[v]=temp;
	return father[v];
}

void Union(int x,int y){
	int a=findset(x);
	int b=findset(y);
	if(a == b)return;
	father[a]=b;
	sum[a]+=rank[b];
	rank[b]+=rank[a];
}

int main(){
	int n,a,b;
	char s;
	makeset(MAX-10);
	scanf("%d",&n);
	while(n--){
		getchar();scanf("%c",&s);
		if(s == 'M'){
			scanf("%d%d",&a,&b);
			Union(a,b);
		}
		else{
			scanf("%d",&a);
			findset(a);
			printf("%d\n",sum[a]);
		}
	}
	return 0;
}