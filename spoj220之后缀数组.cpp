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
typedef long long LL;
using namespace std;

const int MAX=1000000+10;
int *rank,r[MAX],sa[MAX],height[MAX],n;
int wa[MAX],wb[MAX],wm[MAX],pos[15],xy[15][2];
char s[MAX/10];

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
		for(t=x,x=y,y=t,x[sa[0]]=0,i=p=1;i<n;++i){
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

void check(int k){
	int i=0;
	for(i=0;i<=n;++i)if(k<pos[i])break;
	xy[i][0]=min(xy[i][0],k);
	if(xy[i][0] == -1)xy[i][0]=k;
	xy[i][1]=max(xy[i][1],k);
}

bool panduan(int k){
	int i=0;
	for(i=0;i<n;++i)if(xy[i][1]-xy[i][0]<k)return false;
	return true;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		int len=-1,j=0;
		for(int i=0;i<n;++i){
			cin>>s;
			for(j=0,++len;s[j] != '\0';++j,++len)r[len]=s[j];
			r[len]=300+i;
			pos[i]=len;
		}
		r[len]=0;
		makesa(r,sa,len+1,310);
		calheight(r,sa,len);
		int l=0,r=len,mid;
		while(l<=r){
			mid=l+r>>1;
			memset(xy,-1,sizeof xy);
			for(int i=1;i<=len;++i){
				if(height[i]>=mid){
					check(sa[i]);
					check(sa[i-1]);
				}else{
					if(panduan(mid))break;
					memset(xy,-1,sizeof xy);
				}
			}
			if(panduan(mid))l=mid+1;
			else r=mid-1;
		}
		cout<<r<<endl;
	}
	return 0;
}