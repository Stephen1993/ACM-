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

const int MAX=19+3;
__int64 dp[MAX][3];
/*
dp[i][0]表示长度<=i的不含有0/1/2/3.../9的数的个数
dp[i][1]表示长度<=i的含有0/1/2/3.../9的数的个数
dp[i][2]表示长度<=i的数中总共含有0/1/2/3.../9的个数 
*/ 
int digit[MAX];

void init(){
	dp[0][0]=1;dp[1][0]=9;dp[1][1]=1;dp[1][2]=1;
	for(int i=2;i<MAX;++i){
		dp[i][0]=dp[i-1][0]*9; 
		dp[i][1]=dp[i-1][1]*10+dp[i-1][0];
		dp[i][2]=dp[i-1][2]*10+dp[i-1][1]+dp[i-1][0];                                                                                               
	}
}

__int64 digit_dp(__int64 n,int m){
	int size=0;
	__int64 sum=0,last=0;
	while(n)digit[++size]=n%10,n=n/10;
	for(int i=size;i>=1;--i){
		sum+=dp[i-1][2]*digit[i]+last*(digit[i]*(dp[i-1][0]+dp[i-1][1]));
		if(digit[i] == m)++last;
		if(digit[i]>m)sum+=dp[i-1][1]+dp[i-1][0];
	} 
	return sum+last;
}

int main(){
	init();
	__int64 a,b;
	while(scanf("%I64d%I64d",&a,&b)!=EOF){
		if(a>b)a=a+b,b=a-b,a=a-b;
		//for(int i=0;i<9;++i)printf("%d ",digit_dp(b,i)-digit_dp(a-1,i));
		printf("%I64d\n",digit_dp(b,1)-digit_dp(a-1,1));
	}
	return 0;
}