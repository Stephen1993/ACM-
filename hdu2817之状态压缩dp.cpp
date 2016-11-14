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

const int MAX=(1<<10)+10;
int n;
int dp[MAX][20];
int num[20][20];
char s[20][20];

int cal(char *a,char *b){
	int sum=0;
	int lena=strlen(a),lenb=strlen(b);
	for(int i=0;i<lena;++i){
		int x=i,y=0,ans=0;
		while(x<lena && y<lenb){
			if(a[x] == b[y])++ans;
			++x,++y;
		}
		sum=max(sum,ans);
	}
	for(int i=0;i<lenb;++i){
		int x=i,y=0,ans=0;
		while(x<lenb && y<lena){
			if(b[x] == a[y])++ans;
			++x,++y;
		}
		sum=max(sum,ans);
	}
	return sum;
}

void DP(){
	int bit=1<<n;
	memset(dp,-1,sizeof dp);
	for(int i=0;i<n;++i)dp[1<<i][i]=0;
	for(int i=1;i<bit;++i){
		for(int j=0;j<n;++j){
			if(dp[i][j] == -1)continue;
			for(int k=0;k<n;++k){
				if(i&(1<<k))continue;
				dp[i|(1<<k)][k]=max(dp[i|(1<<k)][k],dp[i][j]+num[j][k]);
			}
		}
	}
	int sum=0; 
	for(int i=0;i<n;++i)sum=max(dp[bit-1][i],sum);
	printf("%d\n",sum);
}

int main(){
	while(~scanf("%d",&n),n){
		for(int i=0;i<n;++i)scanf("%s",s[i]);
		for(int i=0;i<n;++i){
			for(int j=i+1;j<n;++j)num[i][j]=num[j][i]=cal(s[i],s[j]);
		}
		DP();
	}
	return 0;
}