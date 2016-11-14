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

const int MAX=50000+10;
int sum[MAX<<2];//sum表示某个节点的区间和 

void BuildTree(int n,int left,int right){
	if(left == right){
		scanf("%d",sum+n);
		return;
	}
	int mid=left+right>>1;
	BuildTree(n<<1,left,mid);
	BuildTree(n<<1|1,mid+1,right);//n<<1|1等价于n*2+1
	sum[n]=sum[n<<1]+sum[n<<1|1]; 
}

void Update(int a,int add,int n,int left,int right){
	if(left == right){sum[n]+=add;return;}//left == right表示区间已经是a了
	int mid=left+right>>1;
	if(a<=mid)Update(a,add,n<<1,left,mid);
	else Update(a,add,n<<1|1,mid+1,right);
	sum[n]=sum[n<<1]+sum[n<<1|1];//更新区间和 
}

int Query(int L,int R,int n,int left,int right){
	if(L<=left && right<=R)return sum[n];//计算区间L~R中的一段left~right的和
	int mid=left+right>>1,ans=0;
	if(L<=mid)ans+=Query(L,R,n<<1,left,mid);//计算L~R在mid左边的即L~mid得和 
	if(R>mid)ans+=Query(L,R,n<<1|1,mid+1,right);//计算l~R在mid右边即mid+1~R的和 
	return ans; 
	/*
	if(R<=mid)return Query(L,R,n<<1,left,mid);
	else if(L>mid)return Query(L,R,n<<1|1,mid+1,right);
	else return Query(L,mid,n<<1,left,mid)+Query(mid+1,R,n<<1|1,mid+1,right);
	*/
}

int main(){
	int t,n,num=0,a,b;
	char s[10];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		BuildTree(1,1,n);
		printf("Case %d:\n",++num);
		while(scanf("%s",s),s[0] != 'E'){
			scanf("%d%d",&a,&b);
			if(s[0] == 'A')Update(a,b,1,1,n);
			if(s[0] == 'S')Update(a,-b,1,1,n);
			if(s[0] == 'Q')printf("%d\n",Query(a,b,1,1,n));
		}
	}
	return 0;
} 