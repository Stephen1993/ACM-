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

const int MAX=100002;
bool dp[MAX];//把m当做背包,dp[i]代表要买价值为i的物品是否能恰好用硬币买到.
int a[102],b[102];//a代表第i个硬币的价值,b代表个数. 

int main(){
	int n,m,k;
	while(cin>>n>>m,n||m){
		for(int i=0;i<n;++i)cin>>a[i];
		for(int i=0;i<n;++i)cin>>b[i];
		if(m<=0){cout<<"0\n";continue;}//这题很无语的会出现m为负数的情况.
		memset(dp,false,sizeof(bool)*(m+1));
		dp[0]=true;
		for(int i=0;i<n;++i){
			/*if(a[i]*b[i]>=m){//如果a[i]*b[i]>=m,则在背包容量m内,第i个硬币可以取任意n个(n*a[i]<=m)都不会超过b[i]个,所以可以看做为完全背包. 
				for(int j=a[i];j<=m;++j){
					if(dp[j-a[i]])dp[j]=true;
				}
			}*/
			//else{//如果a[i]*b[i]<m,则在背包容量m内,第i个硬币最多可以取b[i]个,即多重背包. 
				for(k=1;k*2-1<=b[i];k=k*2){//用二进制把b[i]分成1,2,4,8...2^(k-1),b[i]-2^k+1种物品,然后以01背包来做. 
					for(int j=m;j>=k*a[i];--j){
						if(dp[j-k*a[i]])dp[j]=true;
					}
				}
				for(int j=m;j>=(b[i]-k+1)*a[i];--j){
					if(dp[j-(b[i]-k+1)*a[i]])dp[j]=true;
				}
			//}
		}
		int sum=0;
		for(int i=1;i<=m;++i)if(dp[i])sum++;
		cout<<sum<<endl;
	}
	return 0;
} 