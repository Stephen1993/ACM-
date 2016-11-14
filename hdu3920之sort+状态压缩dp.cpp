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

const int MAX=(1<<20)+10;
int n,sx,sy,num;
double dp[MAX];
bool mark[MAX];

struct Node{
	int x,y;
	double dist;
	bool operator<(const Node &a)const{
		return dist<a.dist;
	}
}s[22];

double cal(int x1,int y1,int x2,int y2){
	double sum=(x1-x2)*(x1-x2)*1.0+(y1-y2)*(y1-y2)*1.0;
	return sqrt(sum);
}

/*double dfs(int i){
	if(mark[i])return dp[i];
	mark[i]=true;
	int j=0;
	while(i&(1<<j) && j<n)++j;
	for(int k=j+1;k<n;++k){
		if(i&(1<<k))continue;
		dp[i]=min(dp[i],s[j].dist+cal(s[j].x,s[j].y,s[k].x,s[k].y)+dfs(i|(1<<j)|(1<<k)));
	}
	return dp[i];
}*/

void DP(){
	int bit=1<<n;
	for(int i=1;i<bit;++i)dp[i]=INF*1.0;
	for(int i=0;i<bit;++i){
		if(dp[i] == INF*1.0)continue;
		int j=0;
		while(i&(1<<j) && j<n)++j;
		for(int k=j+1;k<n;++k){
			if(i&(1<<k))continue;
			int t=i|(1<<j)|(1<<k);
			dp[t]=min(dp[t],dp[i]+s[j].dist+cal(s[j].x,s[j].y,s[k].x,s[k].y));
		} 
	}
	printf("Case #%d: %.2lf\n",++num,dp[bit-1]);
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&sx,&sy);
		scanf("%d",&n);
		n=2*n;
		for(int i=0;i<n;++i)scanf("%d%d",&s[i].x,&s[i].y),s[i].dist=cal(sx,sy,s[i].x,s[i].y);
		sort(s,s+n);
		DP();
		//int bit=1<<n;
		//for(int i=0;i<bit;++i)dp[i]=INF*1.0;
		//dp[bit-1]=0;
		//memset(mark,false,sizeof mark);
		//printf("Case #%d: %.2lf\n",++num,dfs(0));
	}
	return 0;
}