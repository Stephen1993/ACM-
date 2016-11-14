#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#define INF 999999999
using namespace std;
const int MAX=2001;
int dp[MAX][MAX];
int s[26];
char p[26],a[MAX],b[MAX];
int main(){
	int n;
	while(cin>>n){
		scanf("%s",p);
		for(int i=0;i<n;++i){
			cin>>s[p[i]-'a'];
		}
	    scanf("%s%s",a,b);
	    int la=strlen(a);//用la记录长度,直接使用会超时. 
	    int lb=strlen(b);//用lb记录长度,直接使用会超时. 
		for(int i=0;i<la;++i)dp[i][0]=0;//初始化在第一个恐怖分子之前开枪一定0分. 
		for(int i=0;i<lb;++i)dp[0][1]=0;//初始化不开枪一定0分. 
		for(int i=1;i<=la;++i){
			for(int j=1;j<=lb;++j){
				if(a[i-1]==b[j-1]){
					dp[i][j]=dp[i-1][j-1]+s[a[i-1]-'a'];
				}
				else{
					dp[i][j]=max(dp[i-1][j-1],max(dp[i-1][j],dp[i][j-1]));
				}
			}
		}
		cout<<dp[la][lb]<<endl;
	}
	return 0;
}