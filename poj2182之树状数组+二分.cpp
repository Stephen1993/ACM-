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

const int MAX=8000+10;
int n;
int c[MAX],a[MAX];

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
	int left=1,right=n,mid,num;
	while(left<right){
		mid=left+right>>1;
		num=Query(mid);
		if(mid-1-num<x)left=mid+1;
		else right=mid;
	}
	return left;
}

int main(){
	while(~scanf("%d",&n)){
		a[0]=0;
		for(int i=1;i<n;++i)scanf("%d",a+i);
		for(int i=n-1;i>=0;--i){
			int x=search(a[i]);
			a[i]=x;
			Update(x);
		}
		for(int i=0;i<n;++i)printf("%d\n",a[i]);
	}
	return 0;
}