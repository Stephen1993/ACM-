/*
思路:对所有牛按先左端点s从小到大排序,如果s相等则按e从大到小排序
每次更新e点,更新的目的是使得包含e点的区间含有点的个数+1
对于比牛[s,e]强壮的牛的个数则只要查询区间[e,MAX]内的点的个数
(由于前面更新的牛s<=当前的牛的s,所以只要前面的牛的e>=当前的牛的e即可,即求[e,MAX]含有的点的个数) 
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

const int MAX=100000+10;
int sum[MAX<<2];//区间内含有点的个数
int num[MAX];//记录比第i只牛壮的数量 

struct node{
	int s,e,ID;
	node(){}
	node(int S,int E,int pos):s(S),e(E),ID(pos){}
	bool operator <(const node &a)const {//比较函数 
		if(s == a.s)return e>a.e;
		return s<a.s; 
	}
}s[MAX];

void Update(int pos,int n,int left,int right){
	++sum[n];
	if(left == right)return;
	int mid=left+right>>1;
	if(pos<=mid)Update(pos,n<<1,left,mid);
	else Update(pos,n<<1|1,mid+1,right);
}

int Query(int L,int R,int n,int left,int right){
	if(L<=left && right<=R)return sum[n];
	int mid=left+right>>1,ans=0;
	if(L<=mid)ans+=Query(L,R,n<<1,left,mid);
	if(R>mid)ans+=Query(L,R,n<<1|1,mid+1,right);
	return ans;
}

int main(){
	int n,a,b;
	while(cin>>n,n){
		for(int i=1;i<=n;++i){
			scanf("%d%d",&a,&b);
			s[i]=node(a,b,i);
		}
		sort(s+1,s+n+1);
		memset(sum,0,sizeof sum);
		for(int i=1;i<=n;++i){
			if(s[i].s == s[i-1].s && s[i].e == s[i-1].e){
				num[s[i].ID]=num[s[i-1].ID];
			}else num[s[i].ID]=Query(s[i].e,MAX,1,1,MAX);
			Update(s[i].e,1,1,MAX);
		}
		for(int i=1;i<=n;++i)printf("%d%c",num[i],i == n?'\n':' ');
	}
	return 0;
} 