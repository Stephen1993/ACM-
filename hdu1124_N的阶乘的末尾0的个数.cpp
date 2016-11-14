/*
N! = 1 * 2 * 3 * (2*2) * 5 * (2*3) * 7... 

产生10的原因是有2,5的因子，显然在N!中2的个数大于5的个数，所以只需求出5的个数即可 

求 N! (1*2*3*4*5*...*N)里有多少个5其实可以转化成： 
N!中：是5的倍数的数+是5^2的倍数的数+5^3..... 

如50!： 
含有10个5的倍数的数：5,15,20,25,30,35,40,45,50 【50/5=10】 
含有2个5^2的倍数的数：25,50【50/(5^2)=2】 
可见N!中一共有12个5相乘，那么尾0也必有12个 
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
#define INF 99999999
using namespace std;
const int MAX=10;
int n;
int main(){
	int t;
	cin>>t;
	while(t--){
		int sum=0;
		scanf("%d",&n);
		for(int i=1;n;++i){
			sum+=n/5;
			n=n/5;
		}
		printf("%d\n",sum);
	}
	return 0;
} 