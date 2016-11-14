#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=(1<<12)+10;
const int mod=100000000;
int n,m;
int temp[MAX],dp[MAX],s[15][15],bin[15];

bool check(int k,int i){
	for(int j=0;j<m;++j){
		if(i&1){
			if(s[k][j] == 0)return false;
			i>>=1;
			if(i&1)return false;
		}else i>>=1;
	}
	return true;
}

void dfs(int id,int k,int i,int j){
	if(k >= m){dp[i]=(dp[i]+temp[j])%mod;return;}
	dfs(id,k+1,i,j);
	if(s[id-1][k] == 1 && !((i>>k)&1))dfs(id,k+2,i,j|(1<<k));
}

void DP(){
	for(int k=1;k<=n;++k){
		for(int i=0;i<bin[m];++i)dp[i]=0;
		for(int i=0;i<bin[m];++i){//这里还可以继续优化，可以先搜索出可能的状态i再来枚举 
			if(!check(k,i))continue;
			dfs(k,0,i,0);
		}
		for(int i=0;i<bin[m];++i)temp[i]=dp[i];
	}
}

void Init(){
	memset(temp,0,sizeof temp);
	temp[0]=1;
}

int main(){
	bin[0]=1;
	for(int i=1;i<13;++i)bin[i]=bin[i-1]<<1;
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=n;++i){
			for(int j=0;j<m;++j)scanf("%d",&s[i][j]);
		}
		Init();
		DP();
		int sum=0;
		for(int i=0;i<bin[m];++i)sum=(sum+temp[i])%mod;
		printf("%d\n",sum);
	}
	return 0;
}