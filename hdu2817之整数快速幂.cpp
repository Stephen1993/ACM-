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

const int MAX=10;
const int mod=200907;

__int64 pow(__int64 a,__int64 k){
	__int64 sum=1;
	while(k){
		if(k&1)sum=(sum*a)%mod;
		a=(a*a)%mod;
		k>>=1;
	}
	return sum;
}

int main(){
	__int64 n,a,b,c,k;
	cin>>n;
	while(n--){
		cin>>a>>b>>c>>k;
		if(b-a+b == c)printf("%I64d\n",((k-1)%mod*((b-a)%mod)+a%mod)%mod);
		else{
			__int64 q=b/a;
			printf("%I64d\n",(pow(q,k-1)*(a%mod))%mod);
		}
	}
	return 0;
} 