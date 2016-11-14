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
const int MAX=13000;
int sum[2*MAX],c[MAX],d[MAX];
char a[5*MAX+1],b[5*MAX+1];
const int Base=10000,seg=4;
void trans(char *ch,int *s){
	int i,k=1;
	int L=strlen(ch)-seg;
	for(i=L;i>=0;i-=seg,k++){
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
	if(s[k])s[0]=k;
	else s[0]=k-1;
}
void mult(int *A,int *B,int *sum){
	int i,j,k,m=A[0],n=B[0];
	int all=m+n-1;
	memset(sum,0,sizeof(int)*(all+3));
	for(i=1,k=1;i<=m;++i){
		k=i;
		if(A[i]){
			for(j=1;j<=n;++j,++k){
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
		sum[k++]=sum[k]%Base;
	}
	if(!sum[k])k--;//k=m+n,需要判断第m+n位,比如20*20，40*40 
	sum[0]=k;
	cout<<sum[k];
	for(i=sum[0]-1;i>=1;--i){
		printf("%04d",sum[i]);
	}
	cout<<endl;
}
int main(){
	while(scanf("%s%s",a,b)!=EOF){
		trans(a,c);
		trans(b,d);
		mult(c,d,sum);
	}
}