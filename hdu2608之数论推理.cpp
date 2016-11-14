/*
分析:假设数n=2^k*p1^s1*p2^s2*p3^s3*...*pi^si;//k,s1...si>=0,p1..pi为n的素因子 
所以T[n]=(2^0+2^1+...+2^k)*(p1^0+p1^1+...+p1^s1)*...*(pi^0+pi^1+...+pi^si);
显然(2^0+2^1+...+2^k)%2=1,所以T[n]是0或1就取决于(p1^0+p1^1+...+p1^s1)*...*(pi^0+pi^1+...+pi^si)
而p1...pi都是奇数(除2之外的素数一定是奇数),所以(pi^0+pi^1+...+pi^si)只要有一个si为奇数(i=1...i) 
则(pi^0+pi^1+...+pi^si)%2=0,则T[n]%2=0//若si为奇数,则pi^si+1为偶数,pi^1+pi^2+...+pi^(si-1)为偶数(偶数个奇数和为偶数)
所以要T[n]%2=1,则所有的si为偶数，则n=2^(k%2)*m^2;//m=2^(k/2)*p1^(s1/2)*p2^(s2/2)*...*pi^(si/2)
所以只要n为某个数的平方或者某个数的平方和则T[n]%2=1,只要统计n的个数即可 
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<cmath>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=10;

int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int sum=(int)sqrt(n*1.0)+(int)sqrt(n*1.0/2);
		cout<<sum%2<<endl;
	}
	return 0;
}