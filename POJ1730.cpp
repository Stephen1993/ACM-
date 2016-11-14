#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#include<limits.h>
using namespace std;
const int MAX=100;
const int INF=110000;
int factor_pow[MAX];
bool prime[INF+1];
int s[INF+1],k=0;
void Prime(){
	for(int i=2;i<=INF/2;++i)prime[i*2]=true;
	for(int i=3;i*i<=INF;i+=2){
		if(!prime[i]){
			for(int j=i*i;j<=INF;j+=2*i){
				prime[j]=true;
			}
		}
	}
	for(int i=2;i<=INF;++i){
		if(!prime[i])s[k++]=i;
	}
}
int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}
int factor(long long x){
	bool flag=false;
	if(x<0){
		x=-x;
		flag=true;
	}
	if(x==1){return 1;}
	int j=0,num;
	for(int i=0;i<k&&s[i]*s[i]<=x;++i){
		if(x%s[i]==0){
			num=0;
			for(;x%s[i]==0;x=x/s[i],num++);
			factor_pow[j++]=num;
		}
	}
	if(x!=1){
		factor_pow[j++]=1;
	}
	int sum=factor_pow[0];
	for(int i=1;i<j;++i){
       sum=gcd(sum,factor_pow[i]);
	}
	if(flag){
		for(;sum%2==0;sum=sum/2);
	}
	return sum;
}
int main(){
	Prime();
	long long n;
	while(scanf("%lld",&n),n){
		cout<<factor(n)<<endl;
	}
	return 0;
}