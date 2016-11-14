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
dp[i][0]表示长度<=i的不含有62或4的数的个数
dp[i][1]表示长度为i的不含有62但是最高位是2的数的个数
dp[i][2]表示长度<=i的含有62或者4的数的个数 
*/ 
int digit[MAX];//记录数的每一位

void init(){//预编译好前i的dp[i][0],dp[i][1],dp[i][2] 
	dp[0][0]=1;
	for(int i=1;i<MAX;++i){
		dp[i][0]=dp[i-1][0]*9-dp[i-1][1];//0,1,2,3,4,5...9 + xxxxxxx ==>0xxxx,1xxxxx.....但是4xxxxx和6 + 2xxxx不符合
		dp[i][1]=dp[i-1][0];//2 + xxxxx ==> 2xxxxx 
		dp[i][2]=dp[i-1][2]*10+dp[i-1][0]+dp[i-1][1];//0,1,2,3...9 + xxx62xx/xxx4xxx , 4 + xxxx , 6 + 2xxxxxx
	}
}

int digit_dp(int n){
	int size=0,mark=0,sum=0;
	while(n)digit[++size]=n%10,n=n/10;
	digit[size+1]=0;
	for(int i=size;i>=1;--i){
		sum+=dp[i-1][2]*digit[i];//低位中含有不吉利数 
		if(mark)sum+=dp[i-1][0]*digit[i];//高位中已含有不吉利数但低位中不含有不吉利数 
		else{
			if(digit[i]>4)sum+=dp[i-1][0];//当前这一位可以组成不吉利数:4
			if(digit[i]>6)sum+=dp[i-1][1];//当前这一位与下一位可以组成不吉利数:62
			if(digit[i+1] == 6 && digit[i]>2)sum+=dp[i][1];//当前这一位和上一位可以组成不吉利数:62 
		} 
		if(digit[i+1] == 6 && digit[i] == 2 || digit[i] == 4)mark=true;
	}
	return sum;
}

int main(){
	init();
	int a,b;
	while(cin>>a>>b,a+b){
		cout<<b-a+1-digit_dp(b+1)+digit_dp(a)<<endl;
	}
	return 0;
} 