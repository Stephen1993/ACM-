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

const int MAX=3;
const int mod=10000;
int array[MAX][MAX],sum[MAX][MAX];

void MatrixMult(int a[3][3],int b[3][3]){
	int c[3][3]={0};
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j){
			for(int k=0;k<3;++k){
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	for(int i=0;i<3;++i){
		for(int j=0;j<3;++j)a[i][j]=c[i][j]%mod;
	}
}

int Matrix(int k){
	array[0][0]=array[1][1]=array[2][2]=0;
	array[0][1]=array[0][2]=array[1][0]=array[1][2]=1;
	array[2][0]=array[2][1]=1;
	memset(sum,0,sizeof sum);
	sum[0][0]=sum[1][1]=sum[2][2]=1;
	while(k){
		if(k&1)MatrixMult(sum,array);
		MatrixMult(array,array);
		k>>=1;
	}
	return sum[0][0];
}

int main(){
	int n;
	while(scanf("%d",&n),n){
		printf("%d\n",Matrix(n));
	}
	return 0;
}