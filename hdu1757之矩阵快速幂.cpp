#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=10+10;
int n,mod,a[MAX];
LL s[MAX][MAX],sum[MAX][MAX];

void Init(){
	memset(s,0,sizeof s);
	memset(sum,0,sizeof sum);
	for(int i=0;i<10;++i)s[0][i]=a[i];
	for(int i=1;i<10;++i)s[i][i-1]=1;
	for(int i=0;i<10;++i)sum[i][0]=9-i;
}

void MatrixSub(LL a[MAX][MAX],LL b[MAX][MAX]){
	LL c[MAX][MAX]={0};
	for(int i=0;i<10;++i){
		for(int j=0;j<10;++j){
			for(int k=0;k<10;++k){
				c[i][j]+=b[i][k]*a[k][j];
				c[i][j]%=mod;
			}
		}
	}
	for(int i=0;i<10;++i)for(int j=0;j<10;++j)a[i][j]=c[i][j];
}

LL MatrixPow(int k){
	while(k){
		if(k&1)MatrixSub(sum,s);
		MatrixSub(s,s);
		k>>=1;
	}
	return sum[0][0];
}

int main(){
	while(cin>>n>>mod){
		for(int i=0;i<10;++i)cin>>a[i];
		Init();
		if(n<10)cout<<n<<endl;
		else cout<<MatrixPow(n-9)<<endl;
	}
	return 0;
} 