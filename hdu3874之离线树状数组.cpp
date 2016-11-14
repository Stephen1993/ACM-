/*�������������е�ѯ�������ߴ����Ȼ������
Ȼ���������������ɨ�裬�����κ�����ֻ���������ֵ�λ�ã���ԭ����λ�ø�ֵΪ0
������ɨ��Ĺ����н�����Ͳ��ұ�������λ��ʹ�ú����������������Ҫ��ֻ����һ�θ������߲����� 
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <iomanip>
#define INF 99999999
typedef __int64 LL;
using namespace std;

const int MAX=50000+10;
int n,q,size;
LL c[MAX],a[MAX],sum[MAX*4];
int hash[MAX],mp[MAX];

struct Node{
	int l,r,id;
	bool operator<(const Node &temp)const{
		return r<temp.r;
	}
}s[MAX*4];

int lowbit(int x){
	return x&(-x);
} 

void Update(int x,int d){
	while(x<=n){
		c[x]+=d;
		x+=lowbit(x);
	}
}

LL Query(int x){
	LL sum=0;
	while(x>0){
		sum+=c[x];
		x-=lowbit(x);
	}
	return sum;
}

int search(int x){
	int left=1,right=size,mid;
	while(left<=right){//>=x�ĵ�һ���� 
		mid=left+right>>1;
		if(hash[mid]<x)left=mid+1;
		else right=mid-1;
	}
	return right+1;
}

int main(){
	int t,x;
	scanf("%d",&t);
	while(t--){
		memset(mp,0,sizeof mp);
		memset(c,0,sizeof c);
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",&a[i]),hash[i]=a[i];
		sort(hash+1,hash+1+n);
		size=1;
		for(int i=2;i<=n;++i)if(hash[i] != hash[size])hash[++size]=hash[i];
		scanf("%d",&q);
		for(int i=1;i<=q;++i){
			scanf("%d%d",&s[i].l,&s[i].r);
			s[i].id=i;
		}
		sort(s+1,s+1+q);
		int i=1,j=1;
		while(i<=n && j<=q){
			int k=search(a[i]);
			if(mp[k])Update(mp[k],-a[i]);
			Update(i,a[i]);
			mp[k]=i;
			if(s[j].r == i){
				LL ans=Query(i);
				while(s[j].r == i){
					LL temp=Query(s[j].l-1);
					sum[s[j].id]=ans-temp;
					++j;
				}
			}
			++i;
		}
		for(int i=1;i<=q;++i)printf("%I64d\n",sum[i]);
	}
	return 0;
}