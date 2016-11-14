/*
1,打表找规律，可以发现循环节是4018,即F[n]=F[n%4018],0~4018可以暴力算出来
2,F[n]=F[n-2]+n^3-(n-1)^3=F[n-2]+3n^2+2,有了递推公式就可以构造矩阵求解了:

|0 1 3 0 2|   | F[n]  |   | F[n+1]  |
|1 0 0 0 0| = | F[n-1]| = | F[n]    |
|0 0 1 2 1|   | n^2   |   | (n+1)^2 |
|0 0 0 1 1|   | n     |   | n+1     |
|0 0 0 0 1|   | 1     |   | 1       |

*/
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

const int MAX=5;
const int mod=2009;
int array[MAX][MAX],sum[MAX][MAX];

void MatrixMult(int a[MAX][MAX],int b[MAX][MAX]){
	int c[MAX][MAX]={0};
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j){
			for(int k=0;k<MAX;++k){
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j)a[i][j]=c[i][j]%mod;
	}
}

int MatrixPow(int k){
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j)sum[i][j]=(i == j);
	}
	array[0][0]=0,array[0][1]=array[0][4]=1,array[0][2]=3,array[0][3]=-3;
	array[1][0]=1,array[1][1]=array[1][2]=array[1][3]=array[1][4]=0;
	array[2][0]=array[2][1]=0,array[2][2]=array[2][4]=1,array[2][3]=2;
	array[3][0]=array[3][1]=array[3][2]=0,array[3][3]=array[3][4]=1;
	array[4][0]=array[4][1]=array[4][2]=array[4][3]=0,array[4][4]=1;
	while(k){
		if(k&1)MatrixMult(sum,array);
		MatrixMult(array,array);
		k>>=1;
	}
	return (sum[0][0]*7+sum[0][1]+sum[0][2]*9+sum[0][3]*3+sum[0][4])%mod;
}

int main(){
	int n;
	while(scanf("%d",&n),n){
		if(n == 1)printf("1\n");
		if(n == 2)printf("7\n");
		if(n>2)printf("%d\n",MatrixPow(n-2));
	}
	return 0;
} 