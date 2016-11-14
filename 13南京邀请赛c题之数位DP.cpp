//http://icpc.njust.edu.cn/Local/1739
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 1000000
using namespace std;

const int MAX=70;
long long sum[MAX],num[MAX];//每位1的个数 
int digit[MAX];

long long Pow(long long a,int b){
	long long sum=1;
	while(b){
		if(b&1)sum=sum*a;
		a=a*a;
		b>>=1;
	}
	return sum;
}

long long dfs(int size){
	if(!size)return (long long)1;
	long long ans=0;
	if(digit[size] == 1){
		ans=dfs(size-1);
		sum[size]+=ans;
		ans+=Pow(2,size-1);
		for(int i=size-1;i>=1;--i)sum[i]+=Pow(2,size-2);
	}else ans=dfs(size-1);
	return ans;
}

int calculate(int n){
	memset(sum,0,sizeof sum);
	if(n<=0)return 0;
	int size=0;
	while(n)digit[++size]=n%2,n=n/2;
	for(int i=size-1;i>=1;--i){
		sum[i]+=Pow(2,size-2);//当最高位为0时,其他每位的1是2^(size-1); 
	}
	sum[size]+=dfs(size-1);//当最高位为1时统计最高位的1和其他位的1 
	return size;
}

void Copy(long long* a,long long *b,int n){
	for(int i=0;i<=n;++i)a[i]=b[i];
}

int main(){
	int A,B;
	while(scanf("%d%d",&A,&B)!=EOF){
		memset(num,0,sizeof num);
		memset(sum,0,sizeof sum);
		int n=calculate(B);
		Copy(num,sum,n);
		calculate(A-1);
		for(int i=1;i<=n;++i)sum[i]=num[i]-sum[i];
		long long ans=0;
		for(int i=1;i<=n;++i){
			ans+=(sum[i]/2);
			sum[i+1]+=(sum[i]/2);
		}
		while(sum[++n])ans+=sum[n]/2,sum[n+1]=sum[n]/2;
		printf("%lld\n",ans);
	}
	return 0;
}