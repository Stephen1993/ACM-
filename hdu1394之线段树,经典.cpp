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

const int MAX=5000+10;
int sum[MAX<<2],s[MAX];//表示sum[i]所代表的区间left~right已经出现的数的个数

//线段树我的简单理解为:用点(sum[i])去映射区间left~right,然后就能使用点sum[i]记录区间left~right的某些特性并加以计算 
//采用线段树的作用是计算最初的逆序数,更确切的说是计算区间left~right出现的数个数,即计算由left产生的逆序数 
void BuildTree(int n,int left,int right){//建立满二叉树 
	sum[n]=0;//初始化该区间出现的个数为0
	if(left == right)return;
	int mid=left+right>>1;
	BuildTree(n<<1,left,mid);
	BuildTree(n<<1|1,mid+1,right); 
}

void Update(int date,int n,int left,int right){//更新区间left~right出现的数的个数 
	if(left == right){++sum[n];return;}
	int mid=left+right>>1;
	if(date<=mid)Update(date,n<<1,left,mid);
	else Update(date,n<<1|1,mid+1,right);
	sum[n]=sum[n<<1]+sum[n<<1|1];//更新该区间出现的数的个数 
}

int Query(int L,int R,int n,int left,int right){//查询区间L~R出现的数的个数 
	if(L<=left && right<=R)return sum[n];
	int mid=left+right>>1,ans=0;
	if(L<=mid)ans+=Query(L,R,n<<1,left,mid);//计算L~R在left~mid内的区间L~mid出现的数的个数 
	if(R>mid)ans+=Query(L,R,n<<1|1,mid+1,right);//计算L~R在mid+1~R内的区间mid+1~R出现的数的个数 
	return ans; 
}

int main(){
	int n,ans;
	while(scanf("%d",&n)!=EOF){
		BuildTree(1,0,n-1);
		ans=0;
		for(int i=0;i<n;++i){
			scanf("%d",s+i);
			ans+=Query(s[i],n-1,1,0,n-1);//统计最初的逆序数,Query作用是查询s[i]~n-1出现的数的个数(即统计由s[i]产生的逆序数)
			Update(s[i],1,0,n-1);//更新0~n-1出现的数的个数 
		}
		int temp=ans;
		for(int i=0;i<n-1;++i){//根据公式求所有序列的逆序数 
			ans=ans-s[i]+n-1-s[i];//s[i]表示比s[i]小的数的个数,n-1-s[i]表示比s[i]大的数的个数
			temp=temp<ans?temp:ans; 
		}
		printf("%d\n",temp);
	}
	return 0;
} 