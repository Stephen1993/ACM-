#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=20000+10;
int *rank,sa[MAX],height[MAX],temp[MAX];
int wa[MAX],wb[MAX],wm[MAX];

struct Node{
	int x,id;
	bool operator<(const Node &a)const{
		if(x == a.x)return id<a.id;
		return x<a.x;
	}
}r[MAX];

bool cmp(int *r,int a,int b,int l){
	return r[a] == r[b] && r[a+l] == r[b+l];
}

void makesa(Node *r,int *sa,int n,int m){
	int *x=wa,*y=wb,*t,i,j,p;
	sort(r,r+n);//由于这里最初的m很大所以不采取基数排序,而是采用快速排序,当然也可以先离散化再基数排序 
	for(i=0;i<n;++i)sa[i]=r[i].id;
	for(i=1,x[sa[0]]=0;i<n;++i)x[sa[i]]=(r[i].x == r[i-1].x?m-1:m++);
	/*for(i=0;i<m;++i)wm[i]=0;
	for(i=0;i<n;++i)wm[x[i]=r[i]]++;
	for(i=1;i<m;++i)wm[i]+=wm[i-1];
	for(i=n-1;i>=0;--i)sa[--wm[x[i]]]=i;*/
	for(i=0,j=1,p=0;p<n;j=j*2,m=p){//进行基数排序,当然也可以用快速排序,但是这里基数排序更快 
		for(p=0,i=n-j;i<n;++i)y[p++]=i;
		for(i=0;i<n;++i)if(sa[i]>=j)y[p++]=sa[i]-j;
		for(i=0;i<m;++i)wm[i]=0;
		for(i=0;i<n;++i)wm[x[y[i]]]++;
		for(i=1;i<m;++i)wm[i]+=wm[i-1];
		for(i=n-1;i>=0;--i)sa[--wm[x[y[i]]]]=y[i];
		for(t=x,x=y,y=t,i=p=1,x[sa[0]]=0;i<n;++i){
			x[sa[i]]=cmp(y,sa[i],sa[i-1],j)?p-1:p++;
		}
	} 
	rank=x;
}

void calheight(int *r,int *sa,int n){
	for(int i=0,j=0,k=0;i<n;height[rank[i++]]=k){
		for(k?--k:0,j=sa[rank[i]-1];r[i+k] == r[j+k];++k);
	}
}

int main(){
	int n,k;
	while(cin>>n>>k){
		for(int i=0;i<n;++i)cin>>temp[i],r[i].x=temp[i]+1,r[i].id=i;
		r[n].x=0,r[n].id=n;
		makesa(r,sa,n+1,1);
		calheight(temp,sa,n);
		int l=1,r=n,mid,sum=0,num=1;
		while(l<=r){
			mid=l+r>>1;
			num=1;
			for(int i=1;i<=n;++i){
				if(height[i]>=mid)++num;
				else num=1;
				if(num>=k)break;
			}
			if(num>=k)l=mid+1;
			else r=mid-1;
		}
		cout<<r<<endl;
	}
	return 0;
}