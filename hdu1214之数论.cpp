#include<iostream>
#include<cstdio>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<map>
#include<queue>
#include<string>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=10;
int main(){
	int n;
	while(cin>>n){
		int a=n/2;
		cout<<a*(a-1)/2+(n-a)*(n-a-1)/2<<endl;
	}
	return 0;
} 
/*
求最少的时间使得原来的顺序刚好相反,其实相当于冒泡:1 2 3 4 5 6 7 8 9
冒泡后:9 8 7 6 5 4 3 2 1,变成一个圈后，其实可以分成两段冒泡可以节省时间
设分成两段后其中一段长度为a,则另一段为n-a;
所以时间为time=(a*(a-1)+(n-a)*(n-a-1))/2=(2a^2-2na+n^2-n)/2;
二元一次函数，开口向上，变量为a,所以最小时间time当a=-2n/-2*2=n/2取到;
*/