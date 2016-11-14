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
const int mod=1000000000+7;
int digit[MAX];
__int64 p[MAX];//p[i]表示10^i 

struct node{
	__int64 n,rear,rearpow;//表示后缀的个数,后缀和,后缀平方和 
	node():n(0),rear(0),rearpow(0){};
}dp[MAX][7][7];//dp[i][j][k]表示i的前部分每位和模7余j,前部分模7余k

void init(__int64 n){
	digit[0]=0;
	while(n)digit[++digit[0]]=n%10,n=n/10;
}

node digit_dfs(int size,int j,int k,int flag){
	node sum,num;
	if(!size){sum.n=j && k;return sum;}//后缀数长度为0,j && k 表示在size前部分的数是否符合条件(整个数就是前部分) 
	if(flag && dp[size][j][k].n != -1)return dp[size][j][k];//flag == 1 表示size后部分的数可以随意取,dp[][][].n != -1表示已经寻找过
	int m=flag?9:digit[size];
	for(int i=0;i<=m;++i){
		if(i == 7)continue;
		num=digit_dfs(size-1,(j+i)%7,(k*10+i)%7,flag || i<m);
		sum.n+=num.n;//size后部分的个数
		sum.n%=mod; 
		
		sum.rear+=(p[size-1]*i%mod*num.n+num.rear);//i*10^i+x1+i*10^i+x2+.....=i*10^i*n+(x1+x2+...xn)
		sum.rear%=mod;
		
		//(i*10^i+x1)^2+(i*10^i+x2)^2+(i*10^i+x3)^2+...=(i*10^i)^2*n+2*i*10^i*(x1+x2+...xn)+(x1^2+x2^2+...xn^2)
		sum.rearpow+=(p[size-1]*p[size-1]%mod*i*i%mod*num.n+2*p[size-1]*i%mod*num.rear+num.rearpow);
		sum.rearpow%=mod;
	} 
	if(flag)dp[size][j][k]=sum;//记忆化搜索
	return sum; 
}

int main(){
	memset(dp,-1,sizeof dp);
	p[0]=1;
	for(int i=1;i<20;++i)p[i]=(p[i-1]*10)%mod;//这里注意取模 
	int t;
	__int64 l,r;
	cin>>t;
	while(t--){
		cin>>l>>r;
		init(r);
		__int64 b=digit_dfs(digit[0],0,0,0).rearpow;
		init(l-1);
		__int64 a=digit_dfs(digit[0],0,0,0).rearpow;
		cout<<(b-a+mod)%mod<<endl;
	}
	return 0;
} 