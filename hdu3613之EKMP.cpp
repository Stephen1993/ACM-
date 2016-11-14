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
int next[MAX],extend1[MAX],extend2[MAX];
int sum[MAX],val[27];

void get_next(char *a,int len){
	int k=0,i=1;
	next[0]=len;//可有可无,因为用不上 
	while(k+1<len && a[k] == a[k+1])++k;
	next[1]=k;//这里预先算好next[1]是因为不能k=0,否则next[i-k]=next[i]不是已算好的 
	k=1;
	while(++i<len){//和EKMP的过程一样 
		int maxr=k+next[k]-1;
		next[i]=min(next[i-k],max(maxr-i+1,0));//这里是扩展KMP的精髓,即算法核心思想就是这
		while(i+next[i]<len && a[next[i]] == a[i+next[i]])++next[i];
		if(i+next[i]>k+next[k])k=i; 
	}
}

void EKMP(char *a,char *b,int *extend,int len){
	get_next(a,len);
	int k=0,i=0;
	while(k<len && a[k] == b[k])++k;
	extend[0]=k;
	k=0;
	while(++i<len){
		int maxr=k+extend[k]-1;
		extend[i]=min(next[i-k],max(maxr-i+1,0));//next[i-k]是a与b从i开始的可能已经匹配的长度
		while(i+extend[i]<len && a[extend[i]] == b[i+extend[i]])++extend[i];//这里是扩展KMP的精髓,即算法核心思想就是这
		if(i+extend[i]>k+extend[k])k=i; 
	}
}

int main(){
	int n;
	cin>>n;
	while(n--){
		for(int i=0;i<26;++i)cin>>val[i];
		scanf("%s",s1);
		int len=strlen(s1);
		for(int i=1;i<=len;++i){
			sum[i]=sum[i-1]+val[s1[i-1]-'a'];
			s2[i-1]=s1[len-i];
		}
		EKMP(s1,s2,extend1,len);
		EKMP(s2,s1,extend2,len);
		int ans=0,temp=0;
		for(int i=1;i<len;++i){
			if(extend1[len-i] == i)temp+=sum[i];//表示前i个字符是回文串
			if(extend2[i] == len-i)temp+=sum[len]-sum[i];//表示后len-i个字符为回文串
			if(temp>ans)ans=temp;
			temp=0; 
		}
		cout<<ans<<endl;
	}
	return 0;
} 