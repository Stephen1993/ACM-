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
const int mod=1000000007;
int father[MAX],n,m;

void makeset(int num){
	for(int i=0;i<=num;++i){
		father[i]=i;
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
	father[b]=a;
	--n;
}

__int64 fastpow(__int64 a,int b){
	__int64 sum=1;
	while(b){
		if(b&1)sum=(sum*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return sum;
}

int main(){
	int a,b;
	while(scanf("%d%d",&n,&m)!=EOF){
		makeset(n+1);
		for(int i=0;i<m;++i){
			scanf("%d%d",&a,&b);
			Union(a,b+1);
		}
		printf("%I64d\n",fastpow((__int64)26,n));
	}
	return 0;
} 