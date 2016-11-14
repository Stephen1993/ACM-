#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<math.h>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=2;
const int mod=10000;
int array[MAX][MAX],sum[MAX][MAX];
int F[40];

void MatrixMult(int a[2][2],int b[2][2]){
	int c[2][2]={0};
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

int Matrix(int k){
	array[0][0]=array[0][1]=array[1][0]=1;
	array[1][1]=0;
	sum[0][0]=sum[1][1]=1;
	sum[0][1]=sum[1][0]=0;
	while(k){
		if(k&1)MatrixMult(sum,array);
		MatrixMult(array,array);
		k>>=1;
	}
	return sum[0][0];
}

int pre(int n){
	double a=sqrt(5.0);
	double b=(1+a)/2;
	a=1/a;
	double s=log10(a)+n*log10(b);
	s=s-(int)s;
	double d=pow(10.0,s);
	return int(d*1000);
}

void Init(){//经计算发现n>=40时F[n]>=100000000 
	F[0]=0,F[1]=1;
	for(int i=2;i<40;++i)F[i]=F[i-1]+F[i-2];
}

int main(){
	Init();
	int n;
	while(cin>>n){
		if(n<40)cout<<F[n]<<endl;
		else{
			cout<<pre(n);//输出前4位,前4位用F[n]的通项公式求 
			cout<<"...";
			cout<<setfill('0')<<setw(4)<<Matrix(n-1)<<endl;//输出后4位,后四位用矩阵快速幂求 
		}
	}
	return 0;
}