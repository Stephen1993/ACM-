/*
思路：对所有符合条件的工作队他们的结束日期从小到大排序(使前面的工作不可能在后面的工作做完之后再做) 
      然后DP[i]表示前i个工作能的到的最大工资(第i个工作做与不做),并且更新下第i个工作结束日期后的日期里能获得的最大工资 
*/

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

const int MAX=1111;
int dp[111];

struct node{
	int s,e,w;
}s[MAX];

bool cmp(node a,node b){
	return a.e<b.e;
}

int main(){
	int t,n,m,a,b,c;
	cin>>t;
	while(t--){
		scanf("%d%d",&m,&n);
		int k=1;
		for(int i=0;i<n;++i){
			scanf("%d%d%d",&a,&b,&c);
			if(a>=1 && b<=m)s[k].s=a,s[k].e=b,s[k++].w=c;
		}
		sort(s,s+k,cmp);
		memset(dp,0,sizeof dp);
		for(int i=1;i<k;++i){
			dp[s[i].e]=max(dp[s[i].e],dp[s[i].s-1]+s[i].w);
			for(int j=s[i].e+1;j<=m;++j)dp[j]=max(dp[j],dp[j-1]);
		}
		cout<<dp[m]<<endl;
	}
	return 0;
}