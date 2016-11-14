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
//sum表示区间left~right的和,mark表示区间的是否已经更新(但是孩子未更新) 
int sum[MAX<<2],mark[MAX<<2];

void BuildTree(int n,int left,int right){
	mark[n]=0,sum[n]=1;
	if(left == right)return;
	int mid=left+right>>1;
	BuildTree(n<<1,left,mid);
	BuildTree(n<<1|1,mid+1,right);
	sum[n]=sum[n<<1]+sum[n<<1|1];
}

void Upchild(int n,int len){
	if(mark[n]){//表示父节点更新过但是孩子没有更新 
		mark[n<<1]=mark[n<<1|1]=mark[n];//表示孩子更新了但是孩子的孩子未更新
		sum[n<<1]=(len-(len>>1))*mark[n];//更新左孩子区间和
		sum[n<<1|1]=(len>>1)*mark[n];//更新右孩子区间和
		mark[n]=0;//表示已不存在父节点更新了但是孩子未更新 
	}
}

void Update(int L,int R,int date,int n,int left,int right){
	if(L<=left && right<=R){//更新L~R中德一段区间left~right 
		sum[n]=(right-left+1)*date;
		mark[n]=date;//表示此节点已更新,但是未将孩子更新
		return; 
	}
	Upchild(n,right-left+1);//在即将可能更新孩子前,先将上一次需要更新孩子先更新好
	int mid=left+right>>1;
	if(L<=mid)Update(L,R,date,n<<1,left,mid);//更新left~right中的L~mid
	if(R>mid)Update(L,R,date,n<<1|1,mid+1,right);//更新left~right中的mid+1~R
	sum[n]=sum[n<<1]+sum[n<<1|1]; 
}

int main(){
	int t,n,m,a,b,c;
	scanf("%d",&t);
	for(int i=1;i<=t;++i){
		scanf("%d%d",&n,&m);
		BuildTree(1,1,n);
		while(m--){
			scanf("%d%d%d",&a,&b,&c);
			Update(a,b,c,1,1,n);
		}
		printf("Case %d: The total value of the hook is %d.\n",i,sum[1]);
	}
	return 0;
}
 