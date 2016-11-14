#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<cstdlib>
#include<iomanip>
#define INF 99999999
using namespace std;

//******************************************************************************
const int MAX=13000;
int sum[2*MAX],c[MAX],d[MAX];
char a[5*MAX+1],b[5*MAX+1];
const int Base=10000,seg=4;
bool flag;
//******************************************************************************

void trans(char *ch,int *s){//将字符串转化为数字 
	int i,k=1;
	int L=strlen(ch)-seg; 
	for(i=L;i>=0;i-=seg,k++){//从字符串后面开始,依次四位四位存入整型数组.
		s[k]=ch[i]-'0';
		for(int j=i+1;j<i+seg;++j){
			s[k]=s[k]*10+ch[j]-'0';
		}
	}
	i+=seg;
	s[k]=0;
	for(int j=0;j<i;++j){
		s[k]=s[k]*10+ch[j]-'0';
	}
	if(s[k])s[0]=k;//s[0]储存该数组的位数. 
	else s[0]=k-1;
}
//******************************************************************************

void add(int *A,int *B,int *sum){//大整数相加 
    int la=max(A[0],B[0]),i,c=0;
    for(int i=A[0]+1;i<=la;++i)A[i]=0;
    for(int i=B[0]+1;i<=la;++i)B[i]=0;
	for(i=1;i<=la;++i){
		sum[i]=A[i]+B[i]+c;
		if(sum[i]>=Base){
			c=sum[i]/Base;
			sum[i]%=Base;
		}else c=0;
	}
    if(c>0){
    	sum[i]=c;
    	sum[0]=i;
    }
    else sum[0]=i-1;
    cout<<sum[sum[0]];
    for(int j=sum[0]-1;j>=1;--j){
    	cout<<setw(4)<<setfill('0')<<sum[j];
    }
    cout<<endl;
}
//******************************************************************************

void sub_s(int *A,int *B,int *sum){
	int c=0;
	for(int i=B[0]+1;i<=A[0];++i)B[i]=0;
	for(int i=1;i<=A[0];++i){
		sum[i]=A[i]-B[i]+c;
		if(sum[i]<0){
			sum[i]+=Base;
			c=-1;
		}else c=0;
	}
	sum[0]=1;
	for(int i=A[0];i>=1;--i){
		if(sum[i]){
			sum[0]=i;
			break;
		}
	}
}

void sub(int *A,int *B,int *sum){//大整数相减 
    int p=1;
	if(flag){
		sub_s(A,B,sum);
	} 
	else {sub_s(B,A,sum),p=-1;}
	cout<<sum[sum[0]]*p;
	for(int i=sum[0]-1;i>=1;--i){
		cout<<setfill('0')<<setw(4)<<sum[i];
	}
	cout<<endl;
}
//******************************************************************************

void mult(int *A,int *B,int *sum){//大整数相乘 
	int i,j,k;
	int all=A[0]+B[0]-1;
	memset(sum,0,sizeof(int)*(all+3));
	for(i=1,k=1;i<=A[0];++i){
		k=i;
		if(A[i]){
			for(j=1;j<=B[0];++j,++k){
				sum[k]+=A[i]*B[j];
				if(sum[k]>=Base){
				   sum[k+1]+=sum[k]/Base;
				   sum[k]=sum[k]%Base;	
				}
			}
		}
	}
	while(sum[k]>=Base){
		sum[k+1]+=sum[k]/Base;
		sum[k]=sum[k++]%Base;
	}
	if(!sum[k])k--;//k=m+n,需要判断第m+n位,比如20*20，40*40 
	sum[0]=k;
	cout<<sum[k];
	for(i=sum[0]-1;i>=1;--i){
		printf("%04d",sum[i]);
	}
	cout<<endl;
}
//******************************************************************************

int main(){
	while(scanf("%s%s",a,b)!=EOF){
		flag=false;
		trans(a,c);
		trans(b,d);
		//mult(c,d,sum);
		//add(c,d,sum);
		if(strlen(a)>strlen(b)||(strlen(a)==strlen(b)&&strcmp(a,b)>=0))flag=true;
		sub(c,d,sum);
	}
}