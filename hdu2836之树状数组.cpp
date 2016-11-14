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

const int MAX=100000+10;
const int mod=9901;
int n,m,size;
int a[MAX],hash[MAX],c[MAX];

void Init(int num){
	for(int i=0;i<=num;++i)c[i]=0;
	size=1;
}

int search1(int x){//寻找>=x的第一个数 
	int left=1,right=size,mid;
	while(left<=right){
		mid=left+right>>1;
		if(hash[mid]>=x)right=mid-1;
		else left=mid+1;
	}
	return right+1;
}

int search2(int x){//寻找<=x最后的一个数 
	int left=1,right=size,mid;
	while(left<=right){
		mid=left+right>>1;
		if(hash[mid]<=x)left=mid+1;
		else right=mid-1;
	}
	return left-1;
}

int lowbit(int x){
	return x&(-x);
}

void Update(int x,int d){
	while(x<=size){
		c[x]=(c[x]+d)%mod;
		x+=lowbit(x);
	}
}

int Query(int x){
	LL sum=0;
	while(x>0){
		sum+=c[x];
		x-=lowbit(x);
	}
	return sum%mod;
}

int main(){
	while(~scanf("%d%d",&n,&m)){
		Init(n);
		for(int i=1;i<=n;++i)scanf("%d",a+i),hash[i]=a[i];
		sort(hash+1,hash+1+n);
		for(int i=2;i<=n;++i)if(hash[i] != hash[size])hash[++size]=hash[i];
		int sum=0;
		for(int i=1;i<=n;++i){
			int x=search1(a[i]-m),y=search2(a[i]+m),k=search1(a[i]);
			int ans=Query(y)-Query(x-1);
			ans=(ans%mod+mod)%mod;
			sum=(sum+ans)%mod;
			Update(k,ans+1);
		}
		cout<<sum<<endl;
	}
	return 0;
} 