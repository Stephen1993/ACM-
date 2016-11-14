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
__int64 array[2][2],sum[2][2];

void MatrixMult(__int64 a[2][2],__int64 b[2][2],__int64 mod){
	__int64 c[2][2]={0};
	for(int i=0;i<2;++i){
		for(int j=0;j<2;++j){
			for(int k=0;k<2;++k){
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	for(int i=0;i<2;++i){
		for(int j=0;j<2;++j)a[i][j]=c[i][j]%mod;
	}
}

__int64 Matrix(__int64 a,__int64 b,__int64 k,__int64 mod){
	array[0][0]=a%mod,array[0][1]=(b%mod+mod)%mod;
	array[1][0]=1,array[1][1]=0;
	sum[0][0]=sum[1][1]=1;
	sum[0][1]=sum[1][0]=0;
	while(k){
		if(k&1)MatrixMult(sum,array,mod);
		MatrixMult(array,array,mod);
		k>>=1;
	}
	return (a*sum[0][0]+2*sum[0][1])%mod;
}

int main(){
	__int64 a,b,n,m;
	while(scanf("%I64d%I64d%I64d%I64d",&a,&b,&n,&m)!=EOF){
		if(n == 0)printf("I64d\n",1%m);
		else if(n == 1)printf("%I64d\n",2*a%m);
		else printf("%I64d\n",Matrix(2*a,b-a*a,n-1,m));
	}
	return 0;
} 