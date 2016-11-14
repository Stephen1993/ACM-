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

const int mod1=1000000007;//求结果的循环节 
const int mod2=222222224;//第1层的循环节,假设g(g(g(n)))=g(x),即mod2是x的循环节 
const int mod3=183120;//第2层的循环节假设g(g(g(n)))=g(g(y)),即mod3是y的循化节 

__int64 array[2][2],sum[2][2];

void MatrixMult(__int64 a[2][2],__int64 b[2][2],int mod){
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

__int64 Matrix(__int64 k,int mod){
	array[0][0]=3,array[1][1]=0;
	array[0][1]=array[1][0]=1;
	sum[0][0]=sum[1][1]=1;
	sum[0][1]=sum[1][0]=0;
	while(k){
		if(k&1)MatrixMult(sum,array,mod);
		MatrixMult(array,array,mod);
		k>>=1;
	}
	return sum[0][0];
}

int main(){
	/*__int64 a=0,b=1;
	for(int i=2;;++i){//求循环节 
		a=(b*3+a)%mod2;
		a=a^b;
		b=a^b;
		a=a^b;
		if(a == 0 && b == 1){cout<<i-1<<endl;break;}//i-1=222222224
	}*/
	__int64 n;
	while(scanf("%I64d",&n)!=EOF){
		if(n>=2)n=Matrix(n-1,mod3);
		if(n>=2)n=Matrix(n-1,mod2);
		if(n>=2)n=Matrix(n-1,mod1);
		printf("%I64d\n",n);
	}
	return 0;
}