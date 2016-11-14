#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
#include <iomanip>
#define INF 99999999
typedef __int64 LL;
using namespace std;

const int MAX=20000+10;
const int N=100000+10;
int n,a[MAX];
int c[N],pre1[MAX],pre2[MAX],tail1[MAX],tail2[MAX];

int lowbit(int x){
	return x&(-x);
}

void Update(int x){
	while(x<N){
		c[x]+=1;
		x+=lowbit(x);
	}
}

int Query(int x){
	int sum=0;
	while(x>0){
		sum+=c[x];
		x-=lowbit(x);
	}
	return sum;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",a+i);
		memset(c,0,sizeof c);
		for(int i=1;i<=n;++i){
			int num=Query(a[i]-1);
			int ans=Query(a[i]);
			pre1[i]=ans,pre2[i]=i-1-num;//pre1记录比a[i]小或等的个数,pre2记录比a[i]大或等的个数
			Update(a[i]); 
		}
		memset(c,0,sizeof c);
		for(int i=n;i>=1;--i){
			int num=Query(a[i]-1);
			int ans=Query(a[i]);
			tail1[i]=ans,tail2[i]=n-i-num;
			Update(a[i]);
		}
		LL sum=0;
		for(int i=1;i<=n;++i)sum+=pre1[i]*tail2[i]+pre2[i]*tail1[i];
		printf("%I64d\n",sum);
	}
	return 0;
} 