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

const int MAX=11;
long long dp[MAX][90],digit[MAX],n;

void Init(){
	dp[0][0]=1;
	for(int i=1;i<=10;++i){
		for(int j=0;j<=81;++j){
			for(int k=0;k<=min(9,j);++k){
				dp[i][j]+=dp[i-1][j-k];
			}
		}
	}
}

long long digit_dp(int &m){
	int size=0,num=0;
	long long sum=0;
	while(n)digit[++size]=n%10,n=n/10;
	for(int i=size;i>0;--i){
		for(int j=0;j<digit[i];++j)sum+=dp[i-1][m-num-j];//当i=size时就算好了dp[0][m]~dp[size-1][m];
		num+=digit[i];
	}
	return sum;
}

int main(){
	Init();
	int m;
	while(cin>>m){
		n=1000000000+1;//10^9+1
		cout<<digit_dp(m)<<endl;
	}
	return 0;
}