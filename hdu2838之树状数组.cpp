#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#define INF 99999999
typedef __int64 LL;
using namespace std;

const int MAX=100000+10;
int n;
LL c[MAX],a[MAX];

int lowbit(int x){
	return x&(-x);
}

void Update(int x,int d){
	while(x<=n){
		c[x]+=d;
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
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;++i)scanf("%d",a+i);
		memset(c,0,sizeof c);
		LL sum=0;
		for(int i=1;i<=n;++i){//i需要与前面多少个数交换 
			LL num=Query(a[i]);
			sum+=(i-1-num)*a[i];
			Update(a[i],1);
		}
		memset(c,0,sizeof c);
		for(int i=n;i>=1;--i){//i需要与后面多少个数交换 
			LL num=Query(a[i]-1);
			sum+=num*a[i];
			Update(a[i],1);
		}
		printf("%I64d\n",sum);
	}
	return 0;
}