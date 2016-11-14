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
	    int la=strlen(a);//��la��¼����,ֱ��ʹ�ûᳬʱ. 
	    int lb=strlen(b);//��lb��¼����,ֱ��ʹ�ûᳬʱ. 
		for(int i=0;i<la;++i)dp[i][0]=0;//��ʼ���ڵ�һ���ֲ�����֮ǰ��ǹһ��0��. 
		for(int i=0;i<lb;++i)dp[0][1]=0;//��ʼ������ǹһ��0��. 
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