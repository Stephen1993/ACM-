/*
����dp[i][0,1,2,3]��ʾ����Ϊi�ĺ�׺Ϊfm,ff,mf,mm�ķ��������Ĵ��ĸ���
��
dp[i+1][0]=dp[i][1]+dp[i][2];
dp[i+1][1]=dp[i][2];
dp[i+1][2]=dp[i][3];
dp[i+1][3]=dp[i][1]+dp[i][3];
���ƹ�ʽ�ҳ����Ϳ���ֱ�ӱ������߾������������� 
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

const int MAX=4;
int array[MAX][MAX],sum[MAX][MAX];

void MatrixMult(int a[MAX][MAX],int b[MAX][MAX],int &mod){
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

int MatrixPow(int k,int &mod){
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j)sum[i][j]=(i == j);
	}
	array[0][0]=array[0][1]=array[0][2]=0,array[0][3]=1;
	array[1][1]=array[1][2]=0,array[1][0]=array[1][3]=1;
	array[2][0]=array[2][3]=0,array[2][1]=array[2][2]=1;
	array[3][0]=array[3][1]=array[3][3]=0,array[3][2]=1;
	while(k){
		if(k&1)MatrixMult(sum,array,mod);
		MatrixMult(array,array,mod);
		k>>=1;
	}
	int ans=0;
	for(int i=0;i<MAX;++i)ans=(ans+sum[i][0]+sum[i][1]+sum[i][2]+sum[i][3])%mod;
	return ans;
}

int main(){
	int n,m;
	while(cin>>n>>m){
		/*for(int i=3;i<=n;++i){//�Ƴ����ƹ�ʽ�˾Ϳ����þ���������� 
			dp[i][0]=dp[i-1][3];
			dp[i][1]=(dp[i-1][0]+dp[i-1][3])%m;
			dp[i][2]=(dp[i-1][1]+dp[i-1][2])%m;
			dp[i][3]=dp[i-1][2];
		}*/
		if(n == 0)cout<<0<<endl;
		else if(n == 1)cout<<2%m<<endl;
		else if(n == 2)cout<<4%m<<endl;
		else{
			cout<<MatrixPow(n-2,m)<<endl;
			//cout<<(dp[n][0]+dp[n][1]+dp[n][2]+dp[n][3])%m<<endl;
		}
	}
	return 0;
}