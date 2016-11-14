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

const int MAX=25;
int dp[MAX][MAX*3];//dp表示进攻i次得到j分的最多方案数

int main(){
	int a,b,t;
	dp[0][0]=dp[1][1]=dp[1][2]=dp[1][3]=1;
	for(int i=2;i<MAX;++i){//预编译省时间 
		for(int j=0;j<MAX*3;++j){
			dp[i][j]=dp[i-1][j-1];//表示本次进攻罚分得1分
			if(j>=2)dp[i][j]+=dp[i-1][j-2];//表示本次进攻中距投篮得2分
			if(j>=3)dp[i][j]+=dp[i-1][j-3];//表示本次进攻三分球得3分 
		}
	}
	while(cin>>a>>b>>t){
		int k=(t/15)/2,p=((t/15)%2 ? 1:0),num=(b+k-a+1)>(k+p)?(b+k-a+1):(k+p);//num表示至少要得多少分,可以为0分,k+p表示可以进攻多少次 
		__int64 sum=0;
		for(int i=num;i<=(k+p)*3;++i)sum+=dp[k+p][i];
		cout<<sum<<endl;
	}
	return 0;
} 
