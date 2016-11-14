//http://poj.org/problem?id=3070 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<iomanip>
#define INF 9999999
using namespace std;
const int MAX=100;
const int mod= 10000;
typedef struct{
	int s[2][2];
}matrix;
/*
两个矩阵x，y相乘，返回z;
Matrix mult(Matrix x, Matrix y){
    Matrix z;
    for(int i=0;i<size;++i)
        for(int j=0;j<size;++j){
            z.a[i][j]= 0;
            for(int k=0;k<size;++k){
                z.a[i][j] += ( x.a[i][k]*y.a[k][j] )%mod;
                if( z.a[i][j]>=mod ) z.a[i][j]-= mod;
            }
        }
    return z;
}
*/
matrix matrix_mult(matrix a,matrix b){
	matrix c;
	c.s[0][0]=(a.s[0][0]*b.s[0][0]+a.s[0][1]*b.s[1][0])%mod;
	c.s[0][1]=(a.s[0][0]*b.s[0][1]+a.s[0][1]*b.s[1][1])%mod;
	c.s[1][0]=(a.s[1][0]*b.s[0][0]+a.s[1][1]*b.s[1][0])%mod;
	c.s[1][1]=(a.s[1][0]*b.s[0][1]+a.s[1][1]*b.s[1][1])%mod;
	return c;
}
int matrix_fast_power(int n){
	matrix sum,start;
	for(int i=0;i<2;++i){//构造sum矩阵[1,0],使sum*a=a. 
		for(int j=0;j<2;++j){       //[0,1]
			sum.s[i][j]=(i==j);
		}
	}
	start.s[0][0]=0;//构造矩阵{0,1,1,1}; 
	start.s[0][1]=start.s[1][0]=start.s[1][1]=1;
	while(n){
		if(n&1){
			sum=matrix_mult(sum,start);//如果n为奇数则将一个start先拿出来乘,则n相当于变成n-1(5/2==(5-1)/2). 
		}
		start=matrix_mult(start,start);//a^n=(a^2)^(n/2),a=a^2,n=n/2,a^n=....;
		n>>=1;
	}
	return sum.s[0][1];
}
int main(){
	int n;
	while(scanf("%d",&n),n!=-1){
		cout<<matrix_fast_power(n)<<endl;
	}
	return 0;
} 
 