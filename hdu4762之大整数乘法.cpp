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

const int MAX=10000+10;
const int Base=10;
int a[MAX],b[MAX],sum[MAX];

void Mult(int *A,int *B,int *Sum){
	int i,j,k,m=A[0],n=B[0];
	int all=m+n-1;
	memset(Sum,0,sizeof(int)*(all+3));
	for(i=1,k=1;i<=m;++i){
		k=i;
		if(A[i]){
			for(j=1;j<=n;++j,++k){
				Sum[k]+=A[i]*B[j];
				if(Sum[k]>=Base){
					Sum[k+1]+=Sum[k]/Base;
					Sum[k]=Sum[k]%Base;
				}
			}
		}
	}
	while(Sum[k]>=Base){
		Sum[k+1]+=Sum[k]/Base;
		Sum[k]=Sum[k++]%Base;
	}
	if(!Sum[k])--k;
	Sum[0]=k;
}

void Copy(int *A,int *B){
	for(int i=0;i<=B[0];++i)A[i]=B[i];
}

int main(){
	int m,n,t;
	cin>>t;
	while(t--){
		cin>>m>>n;
		sum[0]=sum[1]=1;
		b[1]=m%10,m=m/10;
		b[2]=m;
		if(b[2])b[0]=2;
		else b[0]=1;
		for(int i=0;i<n-1;++i){//求m^(n-1),要是n大的话可以用快速幂求 
			Copy(a,sum);
			Mult(a,b,sum);
		}
		int gcd=INF;
		for(int i=2;i<=n;++i){//求公约数 
			if(n%i)continue;
			int p=0;
			for(int j=sum[0];j>=1;--j){
				p=(p*10+sum[j])%i;
			}
			if(!p)gcd=i;
		}
		if(gcd != INF){//除公约数 
			for(int i=sum[0];i>=1;--i){
				if(i != 1)sum[i-1]+=(sum[i]%gcd)*10;
				sum[i]/=gcd;
			}
			while(sum[sum[0]] == 0)--sum[0];
			n/=gcd;
		}
		cout<<n<<'/';
		for(int i=sum[0];i>=1;--i)cout<<sum[i];
		cout<<endl;
	}
	return 0;
} 