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
	for(int i=0,j=1,p=0;p<n;j=j*2,m=p){//j表示合并的子串长度 
		for(p=0,i=n-j;i<n;++i)y[p++]=i;//对第二关键字超出数组范围的子串排序
		for(i=0;i<n;++i)if(sa[i]>=j)y[p++]=sa[i]-j;//对剩下子串根据第二关键字排序
		for(i=0;i<m;++i)wm[i]=0;
		for(i=0;i<n;++i)wm[x[y[i]]]++;
		for(i=1;i<m;++i)wm[i]+=wm[i-1];
		for(i=n-1;i>=0;--i)sa[--wm[x[y[i]]]]=y[i]; 
	 	for(t=x,x=y,y=t,i=p=1,x[sa[0]]=0;i<n;++i){//求新的x,相当于rank,但是相同的子串要排名相同 
	 		x[sa[i]]=cmp(y,sa[i],sa[i-1],j)?p-1:p++;//判断子串suffix(sa[i])与suffix(sa[i-1])是否相同并且确定排名 
	 	}
	}
	rank=x;
}

/*在计算好height[rank[i]]后,对于height[rank[i+1]],如果sa[rank[i]-1]的首字母和sa[rank[i]]首字母相同
则rank[i+1]肯定在rank[sa[rank[i]-1]+1]后面,根据排名为a,b的子串的最长公共前缀为[a,b]中最小的
所以i+1和sa[rank[i+1]-1]的公共前缀>=height[rank[i]]-1即>=k-1;
如果sa[rank[i]-1]的首字母和sa[rank[i]]首字母不相同,则上一次的k就是0,所以无影响 
*/
void calheight(int *r,int *sa,int n){
	for(int i=0,j=0,k=0;i<n;height[rank[i++]]=k){ 
		for(k?--k:0,j=sa[rank[i]-1];r[i+k] == r[j+k];++k);
	}
}

void InitRMQ(int n){
	for(int i=1;i<=n;++i)f[i][0]=height[i];//初始化从i开始区间长度为2^0的最值
	int l=log(n*1.0)/log(2.0);//2*l<=n
	for(int j=1;j<=l;++j){
		for(int i=1;i+(1<<j)-1<=n;++i){//i+2^j-1<=n
			f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);//i+2^j-1 - (i+2^(j-1))+1=2^(j-1)
		}
	}
}

int LCP(int i,int j){//求rank[i]与rank[i]+1,ran[i]+1与rank[i]+2...的最长公共前缀中的最值,即height[rank[i]+1]~height[rank[j]]的最值 
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
		for(int j=1;j<=n;++j){//对于长度为j的循环节,sum记录循环次数 
			for(int i=0;i+j<n;i+=j){
				if(s[i] == s[i+j]){
					int len=LCP(i,i+j);//向后匹配 
					int num=len/j;
					int k=i-(j-len%j);
					if(k>=0 && len%j && LCP(k,k+j)>=len)++num;//向前匹配 
					if(num == sum)L[++size]=j;//L记录得到最多循环次数的可能的子串长度
					else if(num > sum)sum=num,L[size=0]=j; 
				}
			}
		}
		for(int i=1;i<=n && sum;++i){//求哪个子串可以循环sum次 
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