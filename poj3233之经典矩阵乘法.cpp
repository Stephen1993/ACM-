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

const int MAX=30+10;
__int64 array[MAX][MAX],sum[MAX][MAX],temp[MAX][MAX],ans[MAX][MAX];
int n,m,k;
//array记录初始矩阵,sum记录每次幂乘后的矩阵,temp临时矩阵,ans记录结果矩阵 

void MatrixInit(__int64 a[MAX][MAX],bool flag){//初始化矩阵,可以初始化为1或者A 
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(flag)a[i][j]=array[i][j];//初始化为矩阵A(A是指题目中的A,也就是这里的array) 
			else a[i][j]=(i == j);//初始化为矩阵1 
		}
	}
}

void MatrixAdd(__int64 a[MAX][MAX],__int64 b[MAX][MAX],int &mod){//矩阵相加,a为相加后的矩阵 
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			a[i][j]=(a[i][j]+b[i][j])%mod;
		}
	}
}

void MatrixMult(__int64 a[MAX][MAX],__int64 b[MAX][MAX],int &mod){//矩阵相乘,a为相乘后的矩阵 
	__int64 c[MAX][MAX]={0};
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			for(int k=0;k<n;++k){
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j)a[i][j]=c[i][j]%mod;
	}
}

void MatrixPow(int k,int &mod){//矩阵快速幂 
	MatrixInit(sum,0);//初始化sum为1
	MatrixInit(temp,1);//初始化temp为A 
	while(k){
		if(k&1)MatrixMult(sum,temp,mod);
		MatrixMult(temp,temp,mod);
		k>>=1;
	}
}

void MatrixSum(int k,int &mod){//矩阵和 
	if(k == 1){MatrixInit(ans,1);return;}
	MatrixSum(k/2,mod);
	MatrixPow((k+1)/2,mod);
	if(k&1){//k为奇数则A+(A+A^m)*(A+A^2+A^3...),m=(k+1)/2
		MatrixInit(temp,1);//初始化temp为A
		MatrixAdd(sum,temp,mod);//计算A+A^m,m=(k+1)/2
		MatrixMult(ans,sum,mod);//计算(A+A^m)*(A^1+A^2+...)
		MatrixAdd(ans,temp,mod);//计算A+(A+A^m)*(A^1+A^2...) 
	} 
	else{//k为偶数则(1+A^m)*(A+A^2+A^3...),m=(k+1)/2
		MatrixInit(temp,0);//初始化temp为1 
		MatrixAdd(temp,sum,mod);//计算1+A^m,m=(k+1)/2
		MatrixMult(ans,temp,mod);//计算(1+A^m)*(A^1+A^2+...) 
	}
}

int main(){
	scanf("%d%d%d",&n,&k,&m);
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			scanf("%I64d",&array[i][j]);
			ans[i][j]=0;//ans是矩阵和 
		}
	}
	MatrixSum(k,m);//矩阵和:A^1+A^2+A^3+A^4+A^5+A^6=(A^1+A^2+A^3)+A^3(A^1+A^2+A^3)
	for(int i=0;i<n;++i){
		for(int j=0;j<n-1;++j)printf("%d ",ans[i][j]);
		printf("%I64d\n",ans[i][n-1]);
	} 
	return 0;
}