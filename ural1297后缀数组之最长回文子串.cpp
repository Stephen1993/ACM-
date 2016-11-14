#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=2*1000+10;
int *rank,r[MAX],sa[MAX],height[MAX];
int wa[MAX],wb[MAX],wm[MAX],L[MAX][32];
char s[MAX];

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
	int l=(int)(log(n*1.0)/log(2.0));//2*l<=n
	for(int i=1;i<=n;++i)L[i][0]=height[i];
	for(int j=1;j<=l;++j){
		for(int i=1;i<=n+1-(1<<j);++i){//i+2^j-1<=n
			L[i][j]=min(L[i][j-1],L[i+(1<<(j-1))][j-1]);
		}
	}
}

int LCP(int a,int b){
	int i=rank[a],j=rank[b];
	if(i>j)swap(i,j);
	++i;
	int l=(int)(log(j-i+1.0)/log(2.0));//2^j<=j-i+1
	return min(L[i][l],L[j-(1<<l)+1][l]);
}

int main(){
	while(~scanf("%s",s)){
		int n=strlen(s),len=n;
		s[n]='#';
		for(int i=n-1;i>=0;--i)s[++n]=s[i];
		s[++n]='\0';
		for(n=0;s[n] != '\0';++n)r[n]=s[n];
		r[n]=0;
		makesa(r,sa,n+1,256);
		calheight(r,sa,n);
		InitRMQ(n);
		int sum=1,Id=0;
		for(int i=1;i<len;++i){
			if(2*LCP(i+1,n-i)+1>sum)sum=2*LCP(i+1,n-i)+1,Id=i-LCP(i+1,n-i);
			if(2*LCP(i,n-i)>sum)sum=2*LCP(i,n-i),Id=i-LCP(i,n-i);
		}
		for(int i=Id;i<Id+sum;++i)cout<<s[i];
		cout<<endl;
	}
	return 0;
}