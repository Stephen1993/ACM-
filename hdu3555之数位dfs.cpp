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

const int MAX=18+3;
__int64 dp[MAX][3];
int digit[MAX];

void init(__int64 n){
	digit[0]=0;
	while(n)digit[++digit[0]]=n%10,n=n/10;
	//memset(dp,-1,sizeof dp);
}

__int64 digit_dfs(int size,int mark,int flag){
	if(!size)return mark == 2;
	if(flag && dp[size][mark] != -1)return dp[size][mark];
	int m=flag?9:digit[size];
	__int64 sum=0;
	for(int i=0;i<=m;++i){
		int Mark=mark;
		if(mark != 2 && i != 4)Mark=0;
		if(mark != 2 && i == 4)Mark=1;
		if(mark == 1 && i == 9)Mark=2;
		sum+=digit_dfs(size-1,Mark,flag || i<m);
	}
	if(flag)dp[size][mark]=sum;
	return sum;
}

int main(){
	memset(dp,-1,sizeof dp);
	int t;
	__int64 n;
	cin>>t;
	while(t--){
	    cin>>n;
		init(n);
		cout<<digit_dfs(digit[0],0,0)<<endl;
	}
	return 0;
}