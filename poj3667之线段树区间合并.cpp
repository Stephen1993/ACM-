/*
本题是线段树区间合并
所谓区间合并我理解为父节点的某些值是由左孩子和右孩子的某些值合并而得到的
对这题,父节点最大连续可用区间可能是由左孩子最大可用右区间和右孩子的最大可用左区间合并得到的 
*/
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

const int MAX=50000+50;
int sum[MAX<<2];//表示某个区间最大连续空区间
int lsum[MAX<<2],rsum[MAX<<2];//表示某个区间最大左连续和右连续空区间
int mark[MAX<<2];//表示父节点更新了但是孩子未更新 

void Upchild(int n,int len){
	if(mark[n] != -1){
		mark[n<<1]=mark[n<<1|1]=mark[n];
		sum[n<<1]=lsum[n<<1]=rsum[n<<1]=mark[n]?0:len-(len>>1);
		sum[n<<1|1]=lsum[n<<1|1]=rsum[n<<1|1]=mark[n]?0:(len>>1);
		mark[n]=-1;
	}
}

void Upfather(int n,int len){
	lsum[n]=lsum[n<<1],rsum[n]=rsum[n<<1|1];
	if(lsum[n] == len-(len>>1))lsum[n]+=lsum[n<<1|1];
	if(rsum[n] == len>>1)rsum[n]+=rsum[n<<1];
	sum[n]=max(rsum[n<<1]+lsum[n<<1|1],max(sum[n<<1],sum[n<<1|1]));
}

void BuildTree(int n,int left,int right){
	sum[n]=lsum[n]=rsum[n]=right-left+1;
	mark[n]=-1;
	if(left == right)return;
	int mid=left+right>>1;
	BuildTree(n<<1,left,mid);
	BuildTree(n<<1|1,mid+1,right);
}

void Update(int L,int R,int d,int n,int left,int right){
	if(L<=left && right<=R){
		sum[n]=lsum[n]=rsum[n]=d?0:right-left+1;
		mark[n]=d;
		return;
	}
	Upchild(n,right-left+1);//在本次更新前先更新上次父节点更新了但是孩子未更新的孩子节点
	int mid=left+right>>1;
	if(L<=mid)Update(L,R,d,n<<1,left,mid);
	if(R>mid)Update(L,R,d,n<<1|1,mid+1,right);
	Upfather(n,right-left+1);//由于孩子更新了,所以更新父节点 
}

int Query(int len,int n,int left,int right){
	if(left == right)return left;
	int mid=left+right>>1;
	Upchild(n,right-left+1);
	if(sum[n<<1]>=len)return Query(len,n<<1,left,mid);
	if(rsum[n<<1]+lsum[n<<1|1]>=len)return mid-rsum[n<<1]+1;
	return Query(len,n<<1|1,mid+1,right);
}

int main(){
	int n,m,a,b,c;
	while(cin>>n>>m){
		BuildTree(1,1,n);
		for(int i=0;i<m;++i){
			scanf("%d%d",&a,&b);
			if(a == 1){
				if(sum[1]<b)printf("0\n");
				else {
					int temp=Query(b,1,1,n);
					printf("%d\n",temp);
					Update(temp,temp+b-1,1,1,1,n);
				}
			}
			else{
				scanf("%d",&c);
				Update(b,b+c-1,0,1,1,n);
			}
		}
	}
	return 0;
} 