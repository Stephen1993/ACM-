#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=5000+10;
int n;
int c[MAX],x[MAX];

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
		int ans=0,temp=0,sum;
		for(int i=1;i<=n;++i)c[i]=0;
		for(int i=1;i<=n;++i){
			scanf("%d",&x[i]);
			++x[i];
			sum=Query(x[i]-1);
			ans+=i-1-sum;
			Update(x[i],1);
		}
		temp=ans;
		for(int i=1;i<=n;++i){
			temp=temp+n-x[i]-x[i]+1;
			ans=min(ans,temp);
		}
		printf("%d\n",ans);
	}
	return 0;
}