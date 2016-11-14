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

const int MAX=10+5;
int dp[MAX][MAX];//dp[i][j]表示长度为i的最高位是j的满足条件的数的个数
int digit[MAX];

void init(){
	for(int i=0;i<10;++i)dp[1][i]=1;
	for(int i=2;i<MAX;++i){
		for(int j=0;j<10;++j){
			for(int k=0;k<10;++k){
				if(j-k>=2 || k-j>=2)dp[i][j]+=dp[i-1][k];
			}
		}
	}
}

int digit_dp(int n){
	int size=0,sum=0;
	while(n)digit[++size]=n%10,n=n/10;
	for(int i=size-1;i>=1;--i){
		for(int j=1;j<10;++j){
			sum+=dp[i][j];
		}
	}
	digit[size+1]=0;
	for(int i=1;i<digit[i];++i)sum+=dp[size][i];
	for(int i=size-1;i>=1;--i){
		for(int j=0;j<digit[i];++j)if(j-digit[i+1]>=2 || j-digit[i+1]<=-2)sum+=dp[i][j];
		if(!(digit[i]-digit[i+1]>=2 || digit[i]-digit[i+1]<=-2))break;
	}
	return sum;
}

int main(){
	init();
	int a,b;
	while(cin>>a>>b){
		cout<<digit_dp(b+1)-digit_dp(a)<<endl;
	}
	return 0;
}
 