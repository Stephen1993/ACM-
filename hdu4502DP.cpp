/*
˼·�������з��������Ĺ��������ǵĽ������ڴ�С��������(ʹǰ��Ĺ����������ں���Ĺ�������֮������) 
      Ȼ��DP[i]��ʾǰi�������ܵĵ��������(��i���������벻��),���Ҹ����µ�i�������������ں���������ܻ�õ������ 
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