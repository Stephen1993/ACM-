/*
思路:本题难度在于如何将原串二分后判断前缀是否是回文和后缀是否是回文串
则可以将原串反转得s2,然后用原串s1去匹配s2,最终s1匹配到的位置就是s1的最大前缀回文串
同理用s2去匹配s1得到s2的最大前缀回文串,即s1得最大后悔回文串
然后根据next[k]的特性,next[k]跳转到的位置就是下一个前缀回文串(0~k和x~len相同,而x~len又是0~k反转得到的,所以0~k是回文串)
直到k=0,将所有前缀回文串和后缀回文串标记,然后对原串线性扫描求出最大值即可 
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

const int MAX=500000+10;
char s1[MAX],s2[MAX];
int next[MAX],sum[MAX],val[27];
int per[MAX],pos[MAX];//用来标记前缀回文串和后缀回文串

void get_next(char *a,int len){
	int i=-1,j=0;
	next[0]=-1;
	while(j<len){
		if(i == -1 || a[i] == a[j])next[++j]=++i;
		else i=next[i];
	}
}

int KMP(char *a,char *b,int len){
	int i=0,j=0;
	while(i<len && j<len){
		if(i == -1 || a[i] == b[j])++i,++j;
		else i=next[i];
	}
	return i;
}

int main(){
	int n,k;
	cin>>n;
	while(n--){
		for(int i=0;i<27;++i)scanf("%d",&val[i]);
		scanf("%s",s1);
		int len=strlen(s1);
		for(int i=0;i<len;++i)s2[i]=s1[len-1-i],sum[i+1]=sum[i]+val[s1[i]-'a'];
		get_next(s1,len);
		k=KMP(s1,s2,len);//求s1最大前缀回文串位置
		while(k)per[k]=n+1,k=next[k];//标记所有前缀回文串 
		get_next(s2,len);
		k=KMP(s2,s1,len);//求s1最大后缀回文串位置 
		while(k)pos[k]=n+1,k=next[k];//标记所有后缀回文串 
		int ans=-INF,num=0;
		for(int i=1;i<len;++i){
			if(per[i] == n+1)num+=sum[i];
			if(pos[len-i] == n+1)num+=sum[len]-sum[i];
			if(num>ans)ans=num;
			num=0;
		}
		cout<<ans<<endl;
	}
} 