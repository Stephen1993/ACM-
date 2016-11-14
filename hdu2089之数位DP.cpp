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

const int MAX=7+3;
int dp[MAX][3];
/*
dp[i][0]表示长度<=i的不含有62和4的数
dp[i][1]表示长度为i的不含有62和4但是含有2的数的个数
dp[i][2]表示长度<=i的含有62或2的数的个数 
*/
int digit[MAX];

void init(){
	dp[0][0]=1;
	for(int i=1;i<MAX;++i){
		dp[i][0]=dp[i-1][0]*9-dp[i-1][1];//0,1,2,3,5...+xxxxx - 6+2xxx
		dp[i][1]=dp[i-1][0];//2 + xxxxx
		dp[i][2]=dp[i-1][2]*10+dp[i-1][1]+dp[i-1][0];//0,1,2,3+(xxx62xx,xxx2xxx),6+2xxx,2+xxxxx
	}
}

int digit_dp(int n){
	int sum=0,size=0,mark=0;
	while(n)digit[++size]=n%10,n=n/10;
	digit[size+1]=0;
	for(int i=size;i>=1;--i){
		sum+=dp[i-1][2]*digit[i];
		if(mark)sum+=dp[i-1][0]*digit[i];
		if(!mark && digit[i]>6)sum+=dp[i-1][1];
		if(!mark && digit[i+1] == 6 && digit[i]>2)sum+=dp[i][1];
		if(!mark && digit[i]>4)sum+=dp[i-1][0];
		if((digit[i+1] == 6 && digit[i] == 2) || digit[i] == 4)mark=true;
	}
	return sum;
}

int main(){
	init();
	int a,b;
	while(cin>>a>>b,a+b){
		cout<<b-digit_dp(b+1)-a+digit_dp(a)+1<<endl;
	}
	return 0;
}