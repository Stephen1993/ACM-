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

const int MAX=100000+10;
int *rank,r[MAX],sa[MAX],height[MAX],L[MAX];
int wa[MAX],wb[MAX],wm[MAX],f[MAX][32];
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
	for(int i=0,j=1,p=0;p<n;j=j*2,m=p){//j��ʾ�ϲ����Ӵ����� 
		for(p=0,i=n-j;i<n;++i)y[p++]=i;//�Եڶ��ؼ��ֳ������鷶Χ���Ӵ�����
		for(i=0;i<n;++i)if(sa[i]>=j)y[p++]=sa[i]-j;//��ʣ���Ӵ����ݵڶ��ؼ�������
		for(i=0;i<m;++i)wm[i]=0;
		for(i=0;i<n;++i)wm[x[y[i]]]++;
		for(i=1;i<m;++i)wm[i]+=wm[i-1];
		for(i=n-1;i>=0;--i)sa[--wm[x[y[i]]]]=y[i]; 
	 	for(t=x,x=y,y=t,i=p=1,x[sa[0]]=0;i<n;++i){//���µ�x,�൱��rank,������ͬ���Ӵ�Ҫ������ͬ 
	 		x[sa[i]]=cmp(y,sa[i],sa[i-1],j)?p-1:p++;//�ж��Ӵ�suffix(sa[i])��suffix(sa[i-1])�Ƿ���ͬ����ȷ������ 
	 	}
	}
	rank=x;
}

/*�ڼ����height[rank[i]]��,����height[rank[i+1]],���sa[rank[i]-1]������ĸ��sa[rank[i]]����ĸ��ͬ
��rank[i+1]�϶���rank[sa[rank[i]-1]+1]����,��������Ϊa,b���Ӵ��������ǰ׺Ϊ[a,b]����С��
����i+1��sa[rank[i+1]-1]�Ĺ���ǰ׺>=height[rank[i]]-1��>=k-1;
���sa[rank[i]-1]������ĸ��sa[rank[i]]����ĸ����ͬ,����һ�ε�k����0,������Ӱ�� 
*/
void calheight(int *r,int *sa,int n){
	for(int i=0,j=0,k=0;i<n;height[rank[i++]]=k){ 
		for(k?--k:0,j=sa[rank[i]-1];r[i+k] == r[j+k];++k);
	}
}

void InitRMQ(int n){
	for(int i=1;i<=n;++i)f[i][0]=height[i];//��ʼ����i��ʼ���䳤��Ϊ2^0����ֵ
	int l=log(n*1.0)/log(2.0);//2*l<=n
	for(int j=1;j<=l;++j){
		for(int i=1;i+(1<<j)-1<=n;++i){//i+2^j-1<=n
			f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);//i+2^j-1 - (i+2^(j-1))+1=2^(j-1)
		}
	}
}

int LCP(int i,int j){//��rank[i]��rank[i]+1,ran[i]+1��rank[i]+2...�������ǰ׺�е���ֵ,��height[rank[i]+1]~height[rank[j]]����ֵ 
	i=rank[i],j=rank[j];
	if(i>j)swap(i,j);
	++i;
	int l=log(j-i+1.0)/log(2.0);//2^l<=j-i+1
	return min(f[i][l],f[j-(1<<l)+1][l]);
}

int main(){
	int Case=0;
	while(scanf("%s",s),s[0] != '#'){
		int n=0;
		for(n=0;s[n] != '\0';++n)r[n]=s[n];
		r[n]=0;
		makesa(r,sa,n+1,256);
		calheight(r,sa,n);
		InitRMQ(n);
		int sum=0,size=0,x=sa[1],y=sa[1]+1; 
		for(int j=1;j<=n;++j){//���ڳ���Ϊj��ѭ����,sum��¼ѭ������ 
			for(int i=0;i+j<n;i+=j){
				if(s[i] == s[i+j]){
					int len=LCP(i,i+j);//���ƥ�� 
					int num=len/j;
					int k=i-(j-len%j);
					if(k>=0 && len%j && LCP(k,k+j)>=len)++num;//��ǰƥ�� 
					if(num == sum)L[++size]=j;//L��¼�õ����ѭ�������Ŀ��ܵ��Ӵ�����
					else if(num > sum)sum=num,L[size=0]=j; 
				}
			}
		}
		for(int i=1;i<=n && sum;++i){//���ĸ��Ӵ�����ѭ��sum�� 
			for(int j=0;j<=size;++j){
				if(sa[i]+L[j]>=n)continue;
				int len=LCP(sa[i],sa[i]+L[j]);
				if(len/L[j] == sum){x=sa[i],y=sa[i]+(sum+1)*L[j],sum=0;break;}
			}
		}
		printf("Case %d: ",++Case);
		for(int i=x;i<y;++i)printf("%c",s[i]);
		printf("\n");
	}
	return 0;
}