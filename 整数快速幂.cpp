#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<iomanip>
#include<cstring>
#include<string>
#include<limits.h>
#define INF 9999999
using namespace std;
const int MAX=100;
const int mod=1000;
int a,b;
int integer_fast_power(int a,int b){
	int sum=1;
	while(b){
		if(b&1){//如果b为奇数则将一个a先拿出来乘,则b相当于变成b-1(5/2==(5-1)/2)
			sum=sum*a%mod;
		}
		a=(a*a)%mod;//a^n=(a^2)^(n/2),a=a^2,n=n/2,a^n=....;
		b>>=1;
	}
	return sum;
}
int main(){
	while(cin>>a>>b,a&&b){
		cout<<integer_fast_power(a,b)<<endl;
	}
	return 0;
}
//整数快速幂证明:http://hi.baidu.com/zhucsusticpc/item/b86b8cebc96a8a3686d9dea2