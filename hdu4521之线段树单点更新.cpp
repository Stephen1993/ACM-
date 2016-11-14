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
int sum[MAX<<2];//表示区间内以叶子值结束的最长子序列
int len[MAX];//表示以第i个数结束的最长子序列
int s[MAX];

void Update(int pos,int date,int n,int left,int right){
	if(left == right){sum[n]=date;return;}
	int mid=left+right>>1;
	if(pos<=mid)Update(pos,date,n<<1,left,mid);
	else Update(pos,date,n<<1|1,mid+1,right);
	sum[n]=max(sum[n<<1],sum[n<<1|1]);//更新区间内最长子序列(以某个叶子结束的序列) 
}

int Query(int L,int R,int n,int left,int right){
	if(L<=left && right<=R)return sum[n];
	int mid=left+right>>1,lmax=0,rmax=0;
	if(L<=mid)lmax=Query(L,R,n<<1,left,mid);
	if(R>mid)rmax=Query(L,R,n<<1|1,mid+1,right);
	return max(lmax,rmax);//返回这个区间内的最长子序列 
}

int main(){//O(nlogn)复杂度 
	int n,d;
	while(cin>>n>>d){
		memset(sum,0,sizeof sum);
		int maxlen=0;
		for(int i=1;i<=n;++i){
			scanf("%d",s+i);
			if(i-d-1>0)Update(s[i-d-1],len[i-d-1],1,0,MAX);//更新恰好满足第i个位置的数i-d-1 
			if(s[i]>0)len[i]=Query(0,s[i]-1,1,0,MAX)+1;//查询在s[i]出现之前出现的数且以该数结束的最长子序列 
			else len[i]=1;//在s[i]之前出现的数s[k]一定满足i-k>d,因为插入(更新)的时候是根据i-d-1更新的,i-(k-d-1)=d+1+(i-k)>d
			maxlen=max(maxlen,len[i]);
		}
		cout<<maxlen<<endl;
	}
	return 0;
} 