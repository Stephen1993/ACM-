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

const int MAX=200000+10;
int sum[MAX<<2];//sum表示第i个节点表示的区间的最大值

void BuildTree(int n,int left,int right){//建立一颗满二叉树直到节点的区间内元素个数为1 
	if(left == right){scanf("%d",&sum[n]);return;}
	int mid=left+right>>1;
	BuildTree(n<<1,left,mid);//将区间二分建立左子树 
	BuildTree(n<<1|1,mid+1,right);//将区间二分建立右字树 
	sum[n]=sum[n<<1]>sum[n<<1|1]?sum[n<<1]:sum[n<<1|1];//该区间的最大值 
}

void Update(int a,int date,int n,int left,int right){
	if(left == right){sum[n]=date;return;}//更新区间a~a的值
	int mid=left+right>>1;
	if(a<=mid)Update(a,date,n<<1,left,mid);//a在mid的左边 
	else Update(a,date,n<<1|1,mid+1,right);//a在mid的右边
	sum[n]=sum[n<<1]>sum[n<<1|1]?sum[n<<1]:sum[n<<1|1];//更新区间的最大值 
}

int Query(int L,int R,int n,int left,int right){
	if(L<=left && right<=R)return sum[n];//找到区间L~R中的一段left~right的最大值
	int mid=left+right>>1,a=0,b=0;
	if(L<=mid)a=Query(L,R,n<<1,left,mid);//寻找L~R在mid左边即L~mid得最大值
	if(R>mid)b=Query(L,R,n<<1|1,mid+1,right);//寻找L~R在mid右边即mid+1~R的最大值
	return a>b?a:b; 
}

int main(){
	int n,m,a,b;
	char s[2];
	while(scanf("%d%d",&n,&m)!=EOF){
		BuildTree(1,1,n);
		for(int i=0;i<m;++i){
			scanf("%s%d%d",s,&a,&b);
			if(s[0] == 'U')Update(a,b,1,1,n);
			else printf("%d\n",Query(a,b,1,1,n));
		}
	}
	return 0;
} 