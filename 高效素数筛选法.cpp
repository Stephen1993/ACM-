#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<time.h>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>
#define INF 999999 
using namespace std;
const int MAX=10000000;
bool prime[MAX+1];
void Prime(){
	for(int i=2;i<=MAX/2;++i)prime[i*2]=true;//把偶数排除 
	for(int i=3;i<=(int)sqrt(MAX*1.0);i+=2){//剩下的数只可能是奇数的倍数，偶数的倍数已被排除. 
		if(!prime[i]){
			for(int j=i*i;j<=MAX;j+=2*i){//j从i*i开始是为了所有的数都只被判断一次,如i=5;则15无需判断 
			    prime[j]=true;          //因为15已被i=3时判断,j+=i*2是保证j为奇数(偶数早已被判断过)(j+=2*i是因为:奇数+奇数+奇数=奇数). 
		    }                          //j=i*i是因为j=i*k(k<i且为奇数)时早被当i=k时筛选掉了,所以j从i*i开始不重复. 
		}
	}
}
int main(){
	Prime();
	cout<<"时间:"<<(double)clock()<<"ms"<<endl;
	return 0;
}