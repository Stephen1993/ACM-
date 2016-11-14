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

const int MAX=1000+10;
int *rank,r[MAX],sa[MAX],height[MAX];
int wa[MAX],wb[MAX],wm[MAX];
char s[MAX];

bool cmp(int *r,int a,int b,int l){
	return r[a] == r[b] && r[a+l] == r[b+l];//r[a]表示第一关键字,r[a+l]表示第二关键字 
}

void makesa(int *r,int *sa,int n,int m){
	int *x=wa,*y=wb,*t;//x记录的是排序完的结果,相当于rank,y记录第二关键字
	 
	//第一次基数排序
	for(int i=0;i<m;++i)wm[i]=0;//对所有的子串个数清0 
	for(int i=0;i<n;++i)wm[x[i]=r[i]]++;//子串r[i]的个数(这里的子串长度为1即子串是r[i]) 
	for(int i=1;i<m;++i)wm[i]+=wm[i-1];//统计<=子串i的个数(子串长度为1,i表示的是子串的ASCII) 
	//wm[x[i]]表示<=x[i]的子串有多少个(排名从0开始,所以--wm[]),i=n-1开始是保证相同的子串位置在后面的就排在后面
	for(int i=n-1;i>=0;--i)sa[--wm[x[i]]]=i;//排名为--wm[x[i]]的子串是suffix(i) 
	
	//倍增进行基数排序直到全部子串的排名不同
	for(int i=0,j=1,p=1;p<n;j=j*2,m=p){//j表示要合并的子串的长度,m=p表示需要排序的最大值为p即排名 
		for(p=0,i=n-j;i<n;++i)y[p++]=i;//对第二关键字数组越界的子串先进行第二关键字排序
		for(i=0;i<n;++i)if(sa[i]>=j)y[p++]=sa[i]-j;//对剩余的子串进行第二关键字排序
		//通过第二关键字和第一关键字进行基数排序
		for(i=0;i<m;++i)wm[i]=0;
		for(i=0;i<n;++i)wm[x[y[i]]]++;//x记录的是上次排序完的结果(排名,也是第一关键字),相当于rank
		for(i=1;i<m;++i)wm[i]+=wm[i-1];
		//第二关键字(排名)从大到小,在第二关键字为i的那个子串y[i]的第一关键字为x[y[i]],第一关键字x[y[i]]前面有wm[]个则排名--wm[](排名从0开始) 
		for(i=n-1;i>=0;--i)sa[--wm[x[y[i]]]]=y[i];//计算排名为--wm[]的是子串y[i]
		//计算新的x相等的子串排名得相同,因为上一次的排名x要用到所以先用y保存(交换x,y即可) 
		for(t=x,x=y,y=t,i=p=1,x[sa[0]]=0;i<n;++i){
			x[sa[i]]=cmp(y,sa[i],sa[i-1],j)?p-1:p++;//如果子串的第一关键字和第二关键字相等则排名一样即p-1 
		} 
	}
	rank=x;//排序完后r已经是完全是rank了 
}

void calheight(int *r,int *sa,int n){
	for(int i=0,j=0,k=0;i<n;height[rank[i++]]=k)
		for(k?--k:0,j=sa[rank[i]-1];r[i+k] == r[j+k];++k);
}

int main(){
	while(~scanf("%s",s),s[0] != '#'){
		int len=0;
		for(len=0;s[len] != '\0';++len)r[len]=s[len];//转化成整数
		r[len]=0;
		makesa(r,sa,len+1,256);//len+1表示在字符串后面+0确保子串比较不会越界(即越界前一定能比出大小)
		calheight(r,sa,len+1);
		int L=INF,R=-INF,sum=0;
		for(int i=1;i<=len/2;++i){//长度为i公共子串
			L=INF,R=-INF;
			for(int j=2;j<=len;++j){//height[1]=0,所以j可以从2开始 
				if(height[j]>=i){
					L=min(L,sa[j]);
					L=min(L,sa[j-1]);
					R=max(R,sa[j]);
					R=max(R,sa[j-1]);
				}else{
					if(L+i<=R)++sum;
					L=INF,R=-INF;
				}
			}
			if(L+i<=R)++sum;
		}
		cout<<sum<<endl;
	}
	return 0;
}