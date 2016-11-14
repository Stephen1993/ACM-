#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 999999999
using namespace std;

const int MAX=100000+10;
char s1[MAX],s2[MAX],a[27],b[27];
int next[MAX];

void get_next(char *a,int len){
	int i=-1,j=0;
	next[0]=-1;
	while(j<len){
		if(i == -1 || a[i] == a[j])next[++j]=++i;
		else i=next[i];
	}
}

int main(){
	int T;
	cin>>T;
	while(T--){
		cin>>a>>s1;
		for(int i=0;i<26;++i)b[a[i]-'a']=i+'a';
		int len=strlen(s1),k=len;
		for(int i=0;i<(len+1)/2;++i)s2[i]=b[s1[i]-'a'];//将密文转换为明文,密文长度>=明文长度
		for(int i=(len+1)/2;i<=len;++i)s2[i]=s1[i];
		get_next(s2,len);
		while(next[k]>len/2)k=next[k];
		cout<<s1;
		for(int i=next[k];i<len-next[k];++i)cout<<b[s1[i]-'a'];
		cout<<endl;
	}
	return 0;
} 