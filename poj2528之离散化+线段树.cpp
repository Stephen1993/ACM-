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

//类似于在一个块上涂颜色,问最后能看到几种颜色
const int MAX=10000+10;
int hash[MAX*4];//离散化后的数组,所谓离散化简单理解就是压缩区间,将长区间映射成短区间
int color[MAX<<4];//记录父节点被染颜色但是孩子未更新
int s[MAX][2];//最初数组
bool mark[MAX];//在查询时标记颜色是否已经寻找到过
int sum;//统计总共有多少块

void Upchild(int n){
	if(color[n]){
		color[n<<1]=color[n<<1|1]=color[n];
		color[n]=0;
	}
}

void Update(int L,int R,int c,int n,int left,int right){
	if(L<=left && right<=R){color[n]=c;return;}
	Upchild(n);//本次更新前先更新上一次可能有的更新(即父节点更新了而孩子未更新)
	int mid=left+right>>1;
	if(L<=mid)Update(L,R,c,n<<1,left,mid);
	if(R>mid)Update(L,R,c,n<<1|1,mid+1,right);
}

void Query(int n,int left,int right){
	if(color[n]){//表示该块已被染成一种颜色
		if(!mark[color[n]])++sum;
		mark[color[n]]=true;
		return;
	}
	if(left == right)return;
	int mid=left+right>>1;
	Query(n<<1,left,mid);
	Query(n<<1|1,mid+1,right);
}

int Search(int key,int n,int x[]){
	int left=0,right=n-1;
	while(left<=right){
		int mid=left+right>>1;
		if(x[mid] == key)return mid;
		if(x[mid]<key)left=mid+1;
		else right=mid-1;
	}
	return -1;
}

int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int k=0;
		for(int i=1;i<=n;++i){
			scanf("%d%d",&s[i][0],&s[i][1]);
			hash[k++]=s[i][0];//开始离散化
			hash[k++]=s[i][1];
		}
		sort(hash,hash+k);
		int m=1;
		for(int i=1;i<k;++i){//把相同的消除,相同的应该映射为同一点并且还可以减少建树的区间
			if(hash[i] != hash[i-1])hash[m++]=hash[i];
		}
		/* 1-10,1-4,5-10和1-10,1-4,6-10都是映射成1,2,3,4即1-4,1-2,3-4,
		   则只能求到2块(1-2,3-4),但是前者看到2块(1-4,5-10),后则能看到3块(1-4,5-5,6-10)
		   所以采用隔板的思想如果相邻两个数差不为1则在两数间添加1个数,则上面的1-10,1-4,5-10或许映射成1-4,1-2,3-4
		   而1-10,1-4,6-10则会映射成1-5,1-2,4-5,其中4和6相差不是1则中间插入一个数5映射为3,这样求出答案才是正确答案
		*/
		for(int i=m-1;i>=1;--i){
			if(hash[i] != hash[i-1]+1)hash[m++]=hash[i-1]+1;
		}
		sort(hash,hash+m);//重新排序(使后面插入的数具有隔板的作用)
		//BuildTree(1,0,m-1);建树起不到任何作用,而树其实本身就存在那,平时建树是为了初始化一些东西而已
		memset(color,0,sizeof color);
		for(int i=1;i<=n;++i){
			int L=Search(s[i][0],m,hash);
			int R=Search(s[i][1],m,hash);
			Update(L,R,i,1,0,m-1);
		}
		sum=0;
		memset(mark,false,sizeof mark);
		Query(1,0,m-1);
		printf("%d\n",sum);
	}
	return 0;
}
