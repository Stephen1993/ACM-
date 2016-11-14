#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#include<cmath>
#define INF 99999999
using namespace std;

__int64 lcm(int a,int b,int c){
	return (__int64)a*b/__gcd(a,b)*c/__gcd((__int64)a*b/__gcd(a,b),(__int64)c);
}

int calculate(int n){
	int sum=n;
	for(int i=n;i>=3;--i){
		for(int j=i-1;j>=2;--j){
			for(int k=j-1;k>=1;--k){
				sum=max(sum,(int)lcm(i,j,k));
			}
		}
	}
	return sum;
}

__int64 LCM(int n){
	if(n<=5)return (__int64)calculate(n);
	__int64 sum=lcm(n,n-1,n-2);
	if(n%2==0){//如果n是奇数,则n,n-1,n-2一定互质(相邻两个奇数互质,相邻两个数互质) 
		sum=max(sum,LCM(n-1));
		sum=max(sum,lcm(n,n-1,n-3));//由于n*(n-1)*(n-5)>(n-1)*(n-2)*(n-3)==>n<1,所以n>=1时lcm(n,n-1,n-5),lcm(n,n-1,n-7)...等不用考虑. 
	}                              //n*(n-1)*(n-3)>(n-5)>(n-1)*(n-2)*(n-3)==>n>9所以要考虑. 
	return sum;                   //n-4,n-6...不用考虑,因为n-4等为偶数,肯定比n-2小(n*(n-1)*(n-2)). 
}

int main(){
	int n;
	while(cin>>n){
		cout<<LCM(n)<<endl;
	}
	return 0;
}
/*
if(n<=3)cout<<3<<endl;
else if(n%2==1)cout<<n*(n-1)*(n-2)<<endl;
else if(n%3==0)cout<<(n-1)*(n-2)*(n-3)<<endl;
else cout<<n*(n-1)*(n-3)<<endl;
*/