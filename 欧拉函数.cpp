//所谓欧拉函数就是[1,n-1]内与n的最大公约数 == 1的数的个数;
/*
简单推导:若n是质数p的k次幂即n=p^k,所以除了p的倍数外,其他数都跟n互质, 
而在n之内p的倍数最大为p^(k-1)-1倍,所以s[n]=s[p^k]=p^k-1-(p^(k-1)-1)=(p-1)*p^(k-1),s[n]代表n的欧拉值.
欧拉函数是积性函数,即是说若m,n互质,s(mn)=s(m)*s(n),所以若n不为质素,n=a1^p1*a2^p2...*an^pn(a1..an为质素).
则s(n)=s(a1^p1)...*s(an^pn)=(a1-1)*a1^(p1-1)*...(an-1)*an^(pn-1)=(a1^p1-a1^（p1-1))...
=a1^p1(1-1/a1)*a2^p2(1-1/a2)...=n(1-1/a1)...
求欧拉值,1:用公式s(n)=s(a1^p1)...*s(an^pn)=(a1-1)*a1^(p1-1)*...(an-1)*an^(pn-1)求,求出整数素因子及其幂即可.
2:用公式s[n]=n*(1-1/a1)*(1-1/a2)*....求. 
*/ 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#define INF 999999
using namespace std;
const int MAX=100;
int Euler(int x){
	int sum=x;
	for(int i=2;i*i<=x;++i){//求x的素因子. 
		if(x%i==0){
			sum-=sum/i;
			while(x%i==0){
				x=x/i;
			}
		}
	}
	if(x!=1){
		sum-=sum/x;
	}
	return sum;
}
int main(){
	int n;
	while(cin>>n){
		cout<<"欧拉值为:"<<Euler(n)<<endl;//欧拉值=n*(1-1/a1)*(1-1/a2)*....,a1,a2为n的不重复的素因子. 
	}
	return 0;
}
/*当然如果先预处理出素数的话，也可以求欧拉函数，会更快！
int Euler(int x){
   int i,tmp=x; 
   for(i=1; i<=prime[0] && prime[i]*prime[i]<=tmp; i++){//prime[0]代表素数的个数. 
       if( tmp%prime[i]==0 ) {
           x-= (x/prime[i]);
       while( tmp%prime[i] == 0 ) tmp/= prime[i];
       }
   }
   if(tmp>1) x-= x/tmp;
   return x;
}*/
//******************************************************************************//
