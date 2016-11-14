#include<iostream>
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

const int MAX=2*100000+10;
int *rank,r[MAX],sa[MAX],height[MAX];
int wa[MAX],wb[MAX],wm[MAX];
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

LL calculate(int n,int len,int k){
	int *mark=wb,*ans=wm,Top=0;//num[1],num[2]�ֱ��ʾ�ַ���A,B,suffix(0~i-1)��suffix(i)��������Ӵ�>=k���ܸ���
	LL sum=0,num[3]={0};
	for(int i=1;i<=n;++i){
		if(height[i]<k){
			Top=num[1]=num[2]=0;
		}else{
			for(int size=Top;size && ans[size]>height[i]-k+1;--size){//ά������ջ,ans��¼����suffix(j)��suffix(i-1)>=k��������Ӵ��ĸ���,����Խ���ʾheight[j]Խ��
				num[mark[size]]+=height[i]-k+1-ans[size];//suffix(j)��suffix(i)>=k��������Ӵ�ֻ���ǳ���Ϊk~height[i],������Ҫ��ȥ(ans[size]-(height[i]-k+1))
				ans[size]=height[i]-k+1;//���¸���(���µ���ջ,ʹջ����Ԫ�طǵݼ�)
			}
			ans[++Top]=height[i]-k+1;
			if(sa[i-1]<len)mark[Top]=1;//����num�����ӵĽ����suffix(i-1)��suffix(i)�Ľ��,�������ж�sa[i-1] 
			if(sa[i-1]>len)mark[Top]=2;
			num[mark[Top]]+=height[i]-k+1;//������suffix(i-1)��suffix(i)�����Ľ�� 
			if(sa[i]<len)sum+=num[2];//��ʾ��suffix(i)�����Ľ��������B����suffix(0~i-1)��suffix(i)>=k�ĸ���
			if(sa[i]>len)sum+=num[1];//��ʾ��suffix(i)�����Ľ��������A����suffix(0~i-1)��suffix(i)>=k�ĸ���
		}
	}
	return sum;
}

int main(){
	int k,n,len;
	while(~scanf("%d",&k),k){
		scanf("%s",s);
		for(n=0;s[n] != '\0';++n)r[n]=s[n];
		r[len=n]='#';
		scanf("%s",s+n+1);
		for(++n;s[n] != '\0';++n)r[n]=s[n];
		r[n]=0;
		makesa(r,sa,n+1,256);
		calheight(r,sa,n);
		cout<<calculate(n,len,k)<<endl;
	}
	return 0;
} 