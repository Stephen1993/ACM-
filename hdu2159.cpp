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
int dp[MAX][MAX];//dp表示用了i点耐力和杀了j只怪得到的最多的经验值.
int value[MAX][MAX];

int main(){
	int n,m,k,s;
	while(cin>>n>>m>>k>>s){
		memset(dp,0,sizeof dp);
		for(int i=0;i<k;++i){
			cin>>value[i][0]>>value[i][1];
		}
		int min=-1;
		//二维费用背包,以耐力和最多能杀的怪作为背包. 
		for(int i=0;i<k;++i){
			for(int j=value[i][1];j<=m;++j){
				for(int t=1;t<=s;++t){//for(int t=s;t>=1;--t)也行. 
					dp[j][t]=max(dp[j][t],dp[j-value[i][1]][t-1]+value[i][0]);
					if(dp[j][t]>=n)min=min>(m-j)?min:(m-j);//在获得的经验多于n的情况下求的剩余的最多的耐力. 
				}
			}
		}
		cout<<min<<endl;
	}
	return 0;
} 