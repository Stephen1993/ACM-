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

const int MAX=101;
int father[MAX],rank[MAX],sum;

typedef struct{
	int x;
	int y;
	int val;
}node;
node s[MAX*MAX/2];

bool cmp(node a,node b){
	return a.val<b.val;
}

void makeset(int num){
	for(int i=1;i<=num;++i){
		father[i]=i;
		rank[i]=1;
	}
}

int findset(int v){
	if(v!=father[v])father[v]=findset(father[v]);
	return father[v];
}

void Union(int x,int y,int val){
	int a=findset(x);
	int b=findset(y);
	if(a == b)return;
	if(rank[a]>rank[b]){
		rank[a]+=rank[b];
		father[b]=father[a];
	}
	else{
		rank[b]+=rank[a];
		father[a]=father[b];
	}
	sum+=val;
}

int main(){
	int n,a,b,c,d;
	while(scanf("%d",&n),n){
		sum=0;
		int k=0;
		makeset(n);
		for(int i=0;i<n*(n-1)/2;++i){
			scanf("%d%d%d%d",&a,&b,&c,&d);
			if(d == 1)father[findset(a)]=father[findset(b)];
			else{
				s[k].x=a;
				s[k].y=b;
				s[k++].val=c;
			}
		}
		sort(s,s+k,cmp);
		for(int i=0;i<k;++i)Union(s[i].x,s[i].y,s[i].val);
		cout<<sum<<endl;
	}
	return 0;
}