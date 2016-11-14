/*f(g(i))=f(k*i+b)
��f[n]=A;//A�Ǿ���,A��ĳ��Ԫ����F[n]
��i=0~n-1,��sum(f(k*i+b))
=A^b+A^(k+b)+A^(2k+b)+A^(3k+b)+...+A^((n-1)k+b)
=A^b+A^b(A^k+A^2k+A^3k+A^4k+...+A^(n-1)k)
��A^k����һ���µľ���B,��ԭʽ:
=A^b+A^b(B^1+B^2+B^3+...+B^(n-1));//A^b,A^k�þ�����������,�����е��ö��־������
��ν���־���:A^1+A^2+A^3+A^4+A^5+A^6=(A^1+A^2+A^3)+A^3(A^1+A^2+A^3)
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

const int MAX=2;
__int64 array[MAX][MAX],sum[MAX][MAX],temp[MAX][MAX],ans[MAX][MAX];
//array�൱��A,sum��¼ÿ���ݳ˺�ľ���,temp����ʱ����,ans��B^1+B^2+B^3+...+B^n 

void MatrixInit(__int64 a[MAX][MAX],__int64 b[MAX][MAX],int flag){//��ʼ������ 
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j){
			if(flag == 2)a[i][j]=b[i][j];//a=A
			else if(flag == 0)a[i][j]=(i == j);//a=1
			else a[i][j]=(i+j != 2);
		}
	}
}

void MatrixAdd(__int64 a[MAX][MAX],__int64 b[MAX][MAX],int &mod){//������� 
	for(int i=0;i<MAX;++i){//a=a+b
		for(int j=0;j<MAX;++j){
			a[i][j]=(a[i][j]+b[i][j])%mod;
		}
	}
}

void MatrixMult(__int64 a[MAX][MAX],__int64 b[MAX][MAX],int &mod){//������� 
	__int64 c[MAX][MAX]={0};
	for(int i=0;i<MAX;++i){//a=a*b
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

void MatrixPow(int k,int &mod){//�����ݳ�,sum=A^k 
	MatrixInit(sum,sum,0);//sum=1
	MatrixInit(temp,array,2);//temp=A
	while(k){
		if(k&1)MatrixMult(sum,temp,mod);
		MatrixMult(temp,temp,mod);
		k>>=1;
	}
}

void MatrixSum(int k,int &mod){//������� 
	if(k == 1){MatrixInit(ans,array,2);return;}
	MatrixSum(k/2,mod);
	MatrixPow((k+1)/2,mod);
	//kΪż����(1+A^m)*(A+A^2+A^3...),m=(k+1)/2 
	MatrixInit(temp,temp,0);//temp=1
	MatrixAdd(temp,sum,mod);//temp=1+A^m
	MatrixMult(ans,temp,mod);//ans=ans*temp;
	//kΪ������A^m+(1+A^m)*(A+A^2+A^3...),m=(k+1)/2 
	if(k&1)MatrixAdd(ans,sum,mod);//ans=A^m+ans;
}

int main(){
	int k,b,n,m;
	while(scanf("%d%d%d%d",&k,&b,&n,&m)!=EOF){
		MatrixInit(array,array,1);
		MatrixPow(k,m);//��A^k
		MatrixInit(array,sum,2);//��array�����B,��A^k
		MatrixSum(n-1,m);//������
		MatrixInit(array,array,1);
		MatrixPow(b,m);//��A^b;
		MatrixMult(ans,sum,m);//��A^b*ans
		MatrixAdd(ans,sum,m);//��A^b+ans
		printf("%I64d\n",ans[1][0]); 
	}
	return 0;
}