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

const int MAX=33;
int mod=2008;
__int64 array[MAX][MAX],sum[MAX][MAX],temp[MAX][MAX],ans[MAX][MAX];
int n,a,b,v1,v2,t1,t2,m;
map<__int64,int>hash;

void MatrixInit(__int64 a[MAX][MAX],bool flag){
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j){
			if(flag)a[i][j]=array[i][j];
			else a[i][j]=(i == j);
		}
	}
}

void MatrixAdd(__int64 a[MAX][MAX],__int64 b[MAX][MAX],int &mod){
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j){
			a[i][j]=(a[i][j]+b[i][j])%mod;
		}
	}
}

void MatrixMult(__int64 a[MAX][MAX],__int64 b[MAX][MAX],int &mod){
	__int64 c[MAX][MAX]={0};
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

void MatrixPow(int k,int &mod){
	MatrixInit(sum,0);
	MatrixInit(temp,1);
	while(k){
		if(k&1)MatrixMult(sum,temp,mod);
		MatrixMult(temp,temp,mod);
		k>>=1;
	}
}

void MatrixSum(int k,int &mod){
	if(k == 1){MatrixInit(ans,1);return;}
	MatrixSum(k/2,mod);
	MatrixPow((k+1)/2,mod);
	if(k&1){//A+(A+A^m)*(A+A^2+...),m=(k+1)/2
		MatrixInit(temp,1);//temp=A
		MatrixAdd(sum,temp,mod);//sum=A+A^m
		MatrixMult(ans,sum,mod);//ans=(A+A^m)*(A+A^2+...),m=(k+1)/2
		MatrixAdd(ans,temp,mod);//ans=A+ans
	}
	else{//(1+A^m)*(A+A^2+...),m=(k+1)/2
		MatrixInit(temp,0);//temp=1
		MatrixAdd(temp,sum,mod);//temp=1+A^m
		MatrixMult(ans,temp,mod);//ans=(1+A^m)*(A+A^2+...),m=(k+1)/2
	}
}

int main(){
	while(scanf("%d",&n)!=EOF){
		memset(array,0,sizeof array);
		int size=0;
		hash.clear();//用map对a,b进行离散化 
		for(int i=0;i<n;++i){
			scanf("%d%d",&a,&b);
			if(!hash[a])hash[a]=++size;
			if(!hash[b])hash[b]=++size;
			++array[hash[a]][hash[b]];
		}
		cin>>m;
		for(int i=0;i<m;++i){
			scanf("%d%d%d%d",&v1,&v2,&t1,&t2);
			v1=hash[v1],v2=hash[v2];
			__int64 num=0;
			if(!t1)++t1;
			if(t1<=t2){//A^(t1-1)*(A^1+A^2+..+A^(t2-t1+1))
				MatrixSum(t2-t1+1,mod);//A^1+A^2+..+A^(t2-t1+1)
				MatrixPow(t1-1,mod);//A^(t1-1)
				MatrixMult(ans,sum,mod);
				num=ans[v1][v2];
			}
			printf("%I64d\n",num);
		}
	}
	return 0;
}