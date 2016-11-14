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
const int N=10+5;
int n,m;
int dp[MAX],temp[MAX],p[N],v[N][N],b[N][N],s[N];

int calw(int k,int c){
	int size=0,sum=0;
	for(int i=0;i<n;++i){
		if(k&(1<<i))s[++size]=i;
	}
	for(int i=1;i<=size;++i){
		sum+=v[s[i]][c];
		for(int j=i+1;j<=size;++j){
			sum+=b[s[i]][s[j]];
		}
	}
	return sum-size*p[c];
}

void DP(){
	int bit=1<<n,sum=-INF;
	for(int i=0;i<bit;++i)temp[i]=0;
	for(int i=1;i<=m;++i){
		for(int j=0;j<bit;++j)dp[j]=-INF;//这里必须是赋无穷而不能是-1 
		for(int j=0;j<bit;++j){
			int w=calw(j,i);
			for(int k=j;k<bit;k=(k+1)|j){
				dp[j]=max(dp[j],temp[k]+w);
			}
		}
		for(int j=0;j<bit;++j)temp[j]=dp[j];//采用滚动数组的思想节省内存,当然也可以开数组dp[i][2] 
	}
	for(int i=0;i<bit;++i)sum=max(sum,temp[i]);
	if(sum<=0)printf("STAY HOME\n");
	else printf("%d\n",sum);
}

int main(){
	while(~scanf("%d%d",&n,&m),n+m){
		for(int i=1;i<=m;++i)scanf("%d",p+i);
		for(int i=0;i<n;++i){
			for(int j=1;j<=m;++j)scanf("%d",&v[i][j]);
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				scanf("%d",&b[i][j]);
			}
		}
		DP();
	}
	return 0;
}
/*
1 2
1000 1
0 1000
0
STAY HOME
*/