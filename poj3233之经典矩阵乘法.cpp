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
//array��¼��ʼ����,sum��¼ÿ���ݳ˺�ľ���,temp��ʱ����,ans��¼������� 

void MatrixInit(__int64 a[MAX][MAX],bool flag){//��ʼ������,���Գ�ʼ��Ϊ1����A 
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(flag)a[i][j]=array[i][j];//��ʼ��Ϊ����A(A��ָ��Ŀ�е�A,Ҳ���������array) 
			else a[i][j]=(i == j);//��ʼ��Ϊ����1 
		}
	}
}

void MatrixAdd(__int64 a[MAX][MAX],__int64 b[MAX][MAX],int &mod){//�������,aΪ��Ӻ�ľ��� 
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			a[i][j]=(a[i][j]+b[i][j])%mod;
		}
	}
}

void MatrixMult(__int64 a[MAX][MAX],__int64 b[MAX][MAX],int &mod){//�������,aΪ��˺�ľ��� 
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

void MatrixPow(int k,int &mod){//��������� 
	MatrixInit(sum,0);//��ʼ��sumΪ1
	MatrixInit(temp,1);//��ʼ��tempΪA 
	while(k){
		if(k&1)MatrixMult(sum,temp,mod);
		MatrixMult(temp,temp,mod);
		k>>=1;
	}
}

void MatrixSum(int k,int &mod){//����� 
	if(k == 1){MatrixInit(ans,1);return;}
	MatrixSum(k/2,mod);
	MatrixPow((k+1)/2,mod);
	if(k&1){//kΪ������A+(A+A^m)*(A+A^2+A^3...),m=(k+1)/2
		MatrixInit(temp,1);//��ʼ��tempΪA
		MatrixAdd(sum,temp,mod);//����A+A^m,m=(k+1)/2
		MatrixMult(ans,sum,mod);//����(A+A^m)*(A^1+A^2+...)
		MatrixAdd(ans,temp,mod);//����A+(A+A^m)*(A^1+A^2...) 
	} 
	else{//kΪż����(1+A^m)*(A+A^2+A^3...),m=(k+1)/2
		MatrixInit(temp,0);//��ʼ��tempΪ1 
		MatrixAdd(temp,sum,mod);//����1+A^m,m=(k+1)/2
		MatrixMult(ans,temp,mod);//����(1+A^m)*(A^1+A^2+...) 
	}
}

int main(){
	scanf("%d%d%d",&n,&k,&m);
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			scanf("%I64d",&array[i][j]);
			ans[i][j]=0;//ans�Ǿ���� 
		}
	}
	MatrixSum(k,m);//�����:A^1+A^2+A^3+A^4+A^5+A^6=(A^1+A^2+A^3)+A^3(A^1+A^2+A^3)
	for(int i=0;i<n;++i){
		for(int j=0;j<n-1;++j)printf("%d ",ans[i][j]);
		printf("%I64d\n",ans[i][n-1]);
	} 
	return 0;
}