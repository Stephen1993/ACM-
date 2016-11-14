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

const int MAX=200000+10;//由于n<=200000,即高度最多需要n即可 
int sum[MAX<<2],h,w;//表示sum[i]所代表的区间left~right内最大的宽度 

void BuildTree(int n,int left,int right){
	sum[n]=w;
	if(left == right)return;
	int mid=left+right>>1;
	BuildTree(n<<1,left,mid);
	BuildTree(n<<1|1,mid+1,right);
}

int Query(int wi,int n,int left,int right){
	if(left == right){
		sum[n]-=wi;//在该高度贴广告,则相应的宽度需要减少
		return left; 
	}
	int mid=left+right>>1;
	int hi=sum[n<<1]>=wi?Query(wi,n<<1,left,mid):Query(wi,n<<1|1,mid+1,right);//尽量寻找高度小的位置放置广告 
	sum[n]=sum[n<<1]>sum[n<<1|1]?sum[n<<1]:sum[n<<1|1];//由于字树区间最大宽度变了,所以更新最大宽度
	return hi; 
}

int main(){
	int n,wi;
	while(~scanf("%d%d%d",&h,&w,&n)){
		if(h>n)h=n;//if h>n,则最多需要高度n就能放入n个广告
		BuildTree(1,1,h);
		for(int i=0;i<n;++i){
			scanf("%d",&wi);
			int hi=sum[1]>=wi?Query(wi,1,1,h):-1;//sum[1]表示整个区间的最大宽度 
			printf("%d\n",hi);
		} 
	}
	return 0;
}