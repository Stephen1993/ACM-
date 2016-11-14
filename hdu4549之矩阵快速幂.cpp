#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<vector>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=10;
const int mod=1000000007;
__int64 sum[2][2],array[2][2]; 

void MatrixMult(__int64 a[2][2],__int64 b[2][2]){
	__int64 c[2][2];
	c[0][0]=a[0][0]*b[0][0]+a[0][1]*b[1][0];
	c[0][1]=a[0][0]*b[0][1]+a[0][1]*b[1][1];
	c[1][0]=a[1][0]*b[0][0]+a[1][1]*b[1][0];
	c[1][1]=a[1][0]*b[0][1]+a[1][1]*b[1][1];
	for(int i=0;i<2;++i){
		for(int j=0;j<2;++j)a[i][j]=c[i][j]%(mod-1);
	}
}

int Matrix(int k){
	array[0][0]=0;
	array[0][1]=array[1][0]=array[1][1]=1;
	while(k){
		if(k&1)MatrixMult(sum,array);
		MatrixMult(array,array);
		k>>=1;
	}
	return (sum[0][0]+sum[0][1])%(mod-1);
}

__int64 FastPower(__int64 a,int k){
	__int64 ans=1;
	while(k){
		if(k&1)ans=(ans*a)%mod;
		a=(a*a)%mod;
		k>>=1;
	}
	return ans;
}

int main(){
	__int64 a,b,n;
	while(cin>>a>>b>>n){
		if(n<2){printf("%I64d\n",n?b:a);continue;}
		sum[0][0]=sum[1][1]=1;
		sum[0][1]=sum[1][0]=0;
		int i=Matrix(n-2);
		int j=Matrix(1);
		printf("%I64d\n",(FastPower(a,i)*FastPower(b,j))%mod);
	}
	return 0;
}