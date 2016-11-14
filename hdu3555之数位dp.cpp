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

const int MAX=20;
__int64 dp[MAX][3];
/*
dp[i][0]表示长度<=i的不含有49的数的个数,
dp[i][1]表示长度为i的不含有49但是含有9的数的个数,
dp[i][2]表示长度<=i含有49的数的个数
*/
int digit[MAX],size;

void init(){
	dp[0][0]=1;
	for(int i=1;i<MAX;++i){
		dp[i][0]=dp[i-1][0]*10-dp[i-1][1];//含有i位的数可以在只有i-1位的数前面+0,1,2,3...9,但是要除去4+9xxx ==>49xxx
		dp[i][1]=dp[i-1][0];//只需要在不含有49的数前面加一位9就行了
		dp[i][2]=dp[i-1][2]*10+dp[i-1][1];//i位数的前i位含有49或者前i位不含有49但是第i位是4,第i-1位是9 
	}
}

int main(){
	init();
	int last,flag,t;
	unsigned __int64 n,sum;
	cin>>t;
	while(t--){
		last=size=flag=0,sum=0; 
		cin>>n;
		++n;//n+1是为了消除n本身含有49但是无法统计它本身
		while(n)digit[++size]=n%10,n=n/10;
		for(int i=size;i>=1;--i){
			sum+=dp[i-1][2]*digit[i];//当i=size时就计算了前<i位的数和 ==i位但是第i位小于digit[i]的含有49的数的个数,所以接下来只要计算当第size位是digit[size]...
			if(flag)sum+=dp[i-1][0]*digit[i];//此处增加的一定是i位数含有49的
			if(!flag && digit[i]>4)sum+=dp[i-1][1]; 
			if(last == 4 && digit[i] == 9)flag=1;
			last=digit[i];
		} 
		cout<<sum<<endl;
	}
	return 0;
} 
 