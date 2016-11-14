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

const int MAX=100000+10;
__int64 sum[MAX<<2],mark[MAX<<2];//sum表示区间和,mark表示父节点更新了但是孩子未更新

void BuildTree(int n,__int64 left,__int64 right){
	mark[n]=0;
	if(left == right){scanf("%I64d",&sum[n]);return;}
	__int64 mid=left+right>>1;
	BuildTree(n<<1,left,mid);
	BuildTree(n<<1|1,mid+1,right);
	sum[n]=sum[n<<1]+sum[n<<1|1];
}

void Upchild(int n,__int64 len){
	if(mark[n]){//表示该区间更新了但是孩子未更新 
		mark[n<<1]+=mark[n];//表示孩子更新了但是孩子的孩子未更新
		mark[n<<1|1]+=mark[n];
		sum[n<<1]+=(len-(len>>1))*mark[n];
		sum[n<<1|1]+=(len>>1)*mark[n];
		mark[n]=0;//表示不存在该区间更新了但是孩子未更新的情况 
	}
}

void Update(__int64 L,__int64 R,__int64 date,int n,__int64 left,__int64 right){
	if(L<=left && right<=R){
		sum[n]+=(right-left+1)*date;
		mark[n]+=date;//表示父节点更新了但是孩子未更新 
		return;
	}
	Upchild(n,right-left+1);//在本次更新前先更新上一次父节点更新但是孩子未更新的孩子 
	__int64 mid=left+right>>1;
	if(L<=mid)Update(L,R,date,n<<1,left,mid);
	if(R>mid)Update(L,R,date,n<<1|1,mid+1,right);
	sum[n]=sum[n<<1]+sum[n<<1|1]; 
}

__int64 Query(__int64 L,__int64 R,int n,__int64 left,__int64 right){
	if(L<=left && right<=R)return sum[n];
	Upchild(n,right-left+1);
	__int64 mid=left+right>>1,ans=0;
	if(L<=mid)ans+=Query(L,R,n<<1,left,mid);
	if(R>mid)ans+=Query(L,R,n<<1|1,mid+1,right);
	return ans;
}

int main(){
	int m;
	__int64 a,b,c,n;
	char s[2];
	while(scanf("%I64d%d",&n,&m)!=EOF){
		BuildTree(1,1,n);
		while(m--){
			scanf("%s",s);
			if(s[0] == 'C'){
				scanf("%I64d%I64d%I64d",&a,&b,&c);
				Update(a,b,c,1,1,n);
			}
			else{
				scanf("%I64d%I64d",&a,&b);
				printf("%I64d\n",Query(a,b,1,1,n));
			}
		}
	}
	return 0;
} 