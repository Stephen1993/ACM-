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

const int MAX=4;
const int mod=10007;
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
	while(k){
		if(k&1)MatrixMult(sum,array);
		MatrixMult(array,array);
		k>>=1;
	}
	return (sum[0][0]+sum[0][1]+sum[0][2]+sum[0][3])%mod;//s[0]=,A[0]^2=1
}

int main(){
	int n,x,y;
	while(scanf("%d%d%d",&n,&x,&y)!=EOF){
		x=x%mod,y=y%mod;
		array[0][0]=array[0][1]=1,array[0][2]=array[0][3]=0;
		array[1][0]=0,array[1][1]=(x*x)%mod,array[1][2]=(y*y)%mod,array[1][3]=(2*x*y)%mod;
		array[2][0]=array[2][2]=array[2][3]=0,array[2][1]=1;
		array[3][0]=array[3][2]=0,array[3][1]=x,array[3][3]=y;
		cout<<MatrixPow(n)<<endl;
	}
	return 0;
}
 