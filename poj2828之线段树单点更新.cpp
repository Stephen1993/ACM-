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
int sum[MAX<<2];//表示区间内含有空位的个数
int s[MAX][2];//记录刚开始学生的插入位置和val
int val[MAX];//记录最终相应位置学生的val 

void BuildTree(int n,int left,int right){
	sum[n]=right-left+1;
	if(left == right)return;
	int mid=left+right>>1;
	BuildTree(n<<1,left,mid);
	BuildTree(n<<1|1,mid+1,right);
}

int Update(int pos,int n,int left,int right){
	--sum[n];//将在该区间某个位置插入所以空位减1 
	if(left == right)return left;
	int mid=left+right>>1;
	if(sum[n<<1]>=pos)return Update(pos,n<<1,left,mid);//如果左孩子的空位>=pos则可以在第pos个位置插入这个人 
	else return Update(pos-sum[n<<1],n<<1|1,mid+1,right); 
}
/*
注意上面的pos,输入时要插入到pos位置则前pos的位置一定已经插入人了,所以现在倒序插入就要先预留pos-1个位置给那些人插入
所以要将pos插入到左孩子,则sum[n<<1]>=pos
如果sum[n<<1]<pos则说明在倒序插入的时候有人插入到了pos后面,则有几个人插入到pos前面pos就要倒退几个人
所以pos应该插入在右边的从mid+1开始的第pos-sum[n<<1]个位置 
*/

int main(){
	int n,pos;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;++i){
			scanf("%d%d",&s[i][0],&s[i][1]);
		}
		BuildTree(1,1,n);//建树是为了更新sum 
		for(int i=n-1;i>=0;--i){//倒序插入可使先插入的不受后插入的影响 
			pos=Update(s[i][0]+1,1,1,n);//pos表示这个学生最终的位置
			val[pos]=s[i][1]; 
		}
		for(int i=1;i<n;++i)printf("%d ",val[i]);
		printf("%d\n",val[n]);
	}
	return 0;
} 