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
int dp[MAX][13][3],digit[MAX];
/*
size表示输入的数的长度,则: 
dp[i][j][0]表示从size到i+1位不含有13且接下去长度<=i的模13为j的数的个数
dp[i][j][1]表示从size到i+1位不含有13但是第i+1位是1且接下去长度<=i的模13为j的数的个数
dp[i][j][2]表示从size到i+1位含有13且接下去长度<=i的模13为j的数的个数 
*/

void init(int n){
	digit[0]=0;
	while(n)digit[++digit[0]]=n%10,n=n/10;
	//memset(dp,-1,sizeof dp);
}

//size代表后面几位数,mod代表当前总的余数,mark表示3种情况,flag标记的作用 
int digit_dfs(int size,int mod,int mark,bool flag){//记忆化搜索 
	if(!size)return !mod && mark == 2;//表示所有数搜完
	if(flag && dp[size][mod][mark] != -1)return dp[size][mod][mark];//表示后面长度可以任意数且已经搜索过
	int m=flag?9:digit[size];//判断当前这个数的范围
	int sum=0;
	for(int i=0;i<=m;++i){
		int Mod=(mod*10+i)%13;
		int Mark=mark;
		if(mark != 2 && i != 1)Mark=0;//第一种情况 
		if(mark != 2 && i == 1)Mark=1;//第二种情况 
		if(mark == 1 && i == 3)Mark=2;//第三种情况 
		sum+=digit_dfs(size-1,Mod,Mark,flag || i<m); 
	} 
	if(flag)dp[size][mod][mark]=sum;//记忆好,下次不用再搜索
	return sum; 
}

int main(){
	memset(dp,-1,sizeof dp);
	int n;
	while(cin>>n){
		init(n);
		cout<<digit_dfs(digit[0],0,0,0)<<endl;
	}
	return 0;
}