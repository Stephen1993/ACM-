/*
分析:
1.对于可能的长度二分,然后求这个长度的循环子串最多有多少个
2.对于长度l,若是有子串循环出现了两次,则该子串必定覆盖了s[0],s[0+l],s[0+2*l]...s[0+n*l]...这些点中的两个
3.对于第二种情况,由于不一定是从i,和i+k*l才开始匹配的,可能是从i之前就开始匹配,所以还要向前匹配 
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=50000+10;
int *rank,r[MAX],sa[MAX],height[MAX];
int wa[MAX],wb[MAX],wm[MAX],len[MAX][32];

bool cmp(int *r,int a,int b,int l){
	return r[a] == r[b] && r[a+l] == r[b+l];
}

void makesa(int *r,int *sa,int n,int m){
	int *x=wa,*y=wb,*t;
	for(int i=0;i<m;++i)wm[i]=0;
	for(int i=0;i<n;++i)wm[x[i]=r[i]]++;
	for(int i=1;i<m;++i)wm[i]+=wm[i-1];
	for(int i=n-1;i>=0;--i)sa[--wm[x[i]]]=i;
	for(int i=0,j=1,p=0;p<n;j=j*2,m=p){
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

void InitRMQ(int n){
	int l=log(n*1.0)/log(2.0);//2^l<=n
	for(int i=1;i<=n;++i)len[i][0]=height[i];
	for(int j=1;j<=l;++j){
		for(int i=1;i<=n+1-(1<<j);++i){//i+2^j-1<=n
			len[i][j]=min(len[i][j-1],len[i+(1<<(j-1))][j-1]);
		}
	}
}

int LCP(int a,int b){
	int i=rank[a],j=rank[b];
	if(i>j)swap(i,j);
	++i;
	int l=log(j-i+1.0)/log(2.0);
	return min(len[i][l],len[j+1-(1<<l)][l]);
}

int main(){
	int t,n;
	char s;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;++i)cin>>s,r[i]=s;
		r[n]=0;
		makesa(r,sa,n+1,100);
		calheight(r,sa,n);
		InitRMQ(n);
		int sum=0;
		for(int mid=1;mid<=n;++mid){
			for(int i=0;i+mid<n;i+=mid){
				if(r[i] == r[i+mid]){
					int k=LCP(i,i+mid);
					int ans=k/mid;
					k=mid-k%mid;
					if(k != mid && i-k>=0)ans=max(ans,LCP(i-k,i+mid-k)/mid);
					if(ans>sum)sum=ans;
				}
			}
		}
		cout<<sum+1<<endl;
	}
	return 0;
}
