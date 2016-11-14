#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=70000;
int dp[MAX];
int main(){
	int n[7],sum,num=1,k;
	while(cin>>n[1]>>n[2]>>n[3]>>n[4]>>n[5]>>n[6],n[1]||n[2]||n[3]||n[4]||n[5]||n[6]){
		memset(dp,0,sizeof dp);
		int all=0;
		for(int i=1;i<=6;++i){
			if((n[i]*i)&1)all++;
			n[i]=n[i]%10;
		}
		sum=n[1]+n[2]*2+n[3]*3+n[4]*4+n[5]*5+n[6]*6;
		if(sum&1||all&1){
			cout<<"Collection #"<<num++<<":\n"<<"Can't be divided.\n\n"; 
			continue;
		}
		sum>>=1;
		for(int i=1;i<=6;++i){
			for(k=1;k*2-1<=n[i];k*=2){
				for(int j=sum;j>=k*i;--j){
					dp[j]=max(dp[j],dp[j-k*i]+k*i);
				}
			}
			for(int j=sum;j>=(k-1)*i;--j){
			   dp[j]=max(dp[j],dp[j-i*(n[i]-k+1)]+i*(n[i]-k+1));
            }
		}
		if(dp[sum]==sum){
			cout<<"Collection #"<<num++<<":\n"<<"Can be divided.\n\n";  
		}
		else{
			cout<<"Collection #"<<num++<<":\n"<<"Can't be divided.\n\n"; 
		}
	}
	return 0;
}