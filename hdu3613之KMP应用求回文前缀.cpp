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
char s[MAX*2];
int next[MAX*2],sum[MAX],val[27];
int pre[MAX],pos[MAX];//标记原串中的回文前缀和回文后缀 

void get_next(char *a,int len){
	int i=-1,j=0;
	next[0]=-1;
	while(j<len){
		if(i == -1 || a[i] == a[j])next[++j]=++i;
		else i=next[i];
	}
	return;
}

int main(){
	int n;
	cin>>n;
	while(n--){
		for(int i=0;i<26;++i)scanf("%d",&val[i]);
		scanf("%s",s);
		int len=strlen(s),k=len,temp=len;
		for(int i=1;i<=len;++i)sum[i]=sum[i-1]+val[s[i-1]-'a'];
		s[len]='#';//中间用一个字符隔开则next[len]就一定在#前面,即寻找到的回文前缀一定是原串的回文前缀 
		while(k)s[++len]=s[--k];//将原串反转连接在原串后面 
		s[++len]='\0';
		get_next(s,len);
		k=len;
		while(next[k])pre[next[k]]=n+1,k=next[k];//标记前next[len]个字符是回文串,即标记回文前缀 
		for(int i=0;i<temp;++i){//前后两部分字串交换位置实现将最初原串反转连接在前面,为了求回文后缀 
			s[i]=s[i]^s[temp+1+i];
			s[temp+1+i]=s[i]^s[temp+1+i];
			s[i]=s[i]^s[temp+1+i];
		}
		get_next(s,len);
		k=len;
		while(next[k])pos[next[k]]=n+1,k=next[k];//标记前next[len]是回文串,即标记回文后缀
		int ans=-INF,num=0;
		for(int i=1;i<temp;++i){//求最大值 
			if(pre[i] == n+1)num+=sum[i];
			if(pos[temp-i] == n+1)num+=sum[temp]-sum[i];
			if(num>ans)ans=num;
			num=0;
		}
		cout<<ans<<endl;
	}
	return 0;
}