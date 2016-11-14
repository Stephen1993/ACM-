#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 999999999
using namespace std;

const int MAX=100001;
//s表示原数组,tree表示第i层元素序列,sum表示第i层L~j分到左子树的元素个数 
int s[MAX],tree[20][MAX],sum[20][MAX];
int n,m;

void BuildTree(int deep,int left,int right){
	if(left == right)return;
	int mid=(left+right)>>1,ln=left,rn=mid+1;//ln表示存左子树开始的下标,rn表示存右子树开始的下标 
	int lnum=mid-left+1;//num表示左子树元素的个数
	for(int i=left;i<=mid;++i){
		if(s[i]<s[mid])--lnum;//lnum剩余多少就代表有多少左子树元素和s[mid]相等 
	}
	for(int i=left;i<=right;++i){
		sum[deep][i]=sum[deep][i-1];//表示1~i的划分到左子树的个数 
		if(tree[deep][i]<s[mid]){
			++sum[deep][i];
			tree[deep+1][ln++]=tree[deep][i];
		} 
		else if(tree[deep][i]>s[mid]){
			tree[deep+1][rn++]=tree[deep][i];
		}
		else{
			if(lnum){
				--lnum;
				++sum[deep][i];
				tree[deep+1][ln++]=tree[deep][i];
			}
			else tree[deep+1][rn++]=tree[deep][i];
		}
	} 	
	BuildTree(deep+1,left,mid);//递归先后顺序不能变,因为sum必须从左到右记录才行 
	BuildTree(deep+1,mid+1,right);
}

int Query(int deep,int left,int right,int L,int R,int k){
	if(left == right)return tree[deep][left];
	int a,b;//a代表[left,L)内被划分到左子树的个数,b代表[L,R]....
	int mid=(left+right)>>1;
	a=sum[deep][L-1]-sum[deep][left-1];
	b=sum[deep][R]-sum[deep][L-1];
	if(b>=k){
		return Query(deep+1,left,mid,left+a,left+a+b-1,k);
	}
	else return Query(deep+1,mid+1,right,mid+L-left+1-a,mid+R-left+1-a-b,k-b);
}

int main(){
	int L,R,k,t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;++i){scanf("%d",&s[i]);tree[0][i]=s[i];}//初始化第0层元素
		sort(s+1,s+n+1);//对原数组排序
		BuildTree(0,1,n);//开始建树
		for(int i=0;i<m;++i){
			scanf("%d%d%d",&L,&R,&k);
			cout<<Query(0,1,n,L,R,k)<<endl;//从0层开始在1~n区间内查询区间L~R的第K大的数并输出 
		} 
	}
	return 0;
}