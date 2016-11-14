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

const int MAX=500000+10;
int n;
int hash[MAX],a[MAX],c[MAX];

int lowbit(int x){
	return x&(-x);
}

void Update(int x){
	while(x<=n){
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

int search(int x){
	int left=1,right=n;
	while(left<=right){
		int mid=left+right>>1;
		if(hash[mid] == x)return mid;
		if(hash[mid]<x)left=mid+1;
		else right=mid-1;
	}
}

int main(){
	while(~scanf("%d",&n),n){
		for(int i=1;i<=n;++i)scanf("%d",a+i),hash[i]=a[i];
		for(int i=1;i<=n;++i)c[i]=0;
		sort(hash+1,hash+1+n);
		LL sum=0;
		for(int i=1;i<=n;++i){
			int x=search(a[i]);
			sum+=i-1-Query(x);
			Update(x);
		}
		printf("%lld\n",sum);
	}
	return 0;
} 