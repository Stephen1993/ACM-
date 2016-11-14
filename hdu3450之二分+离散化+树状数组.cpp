/*分析:每次寻找以a[i]结尾的子序列能有多少个,只需要寻找a[i]-d和a[i]+d之之间数结尾的子序列
的全部个数,然后把a[i]直接放在那些数后面即可
找寻和更新都是用树状数组 
*/
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
int n,d,size;
int c[MAX],a[MAX],hash[MAX];

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
	int sum=0;
	while(x>0){
		sum+=c[x];
		x-=lowbit(x);
	}
	return sum%mod;
}

int search1(int x){//寻找第一个>=x的数 
	int left=1,right=size,mid;
	while(left<=right){
		mid=left+right>>1;
		if(hash[mid]<x)left=mid+1;
		else right=mid-1;
	}
	return right+1; 
}

int search2(int x){//寻找最后一个<=x的数 
	int left=1,right=size,mid;
	while(left<=right){
		mid=left+right>>1;
		if(hash[mid]<=x)left=mid+1;
		else right=mid-1;
	}
	return left-1;
}

int main(){
	while(~scanf("%d%d",&n,&d)){
		for(int i=1;i<=n;++i)scanf("%d",a+i),hash[i]=a[i];
		sort(hash+1,hash+n+1);
		size=1;
		for(int i=2;i<=n;++i)if(hash[i] != hash[size])hash[++size]=hash[i];
		int sum=0;
		memset(c,0,sizeof c);
		for(int i=1;i<=n;++i){
			int x=search1(a[i]-d),y=search2(a[i]+d),k=search1(a[i]);
			int ans=Query(y)-Query(x-1);
			ans=ans%mod+mod;
			sum=(sum+ans)%mod;
			Update(k,ans+1);
		}
		printf("%d\n",sum);
	}
	return 0;
}