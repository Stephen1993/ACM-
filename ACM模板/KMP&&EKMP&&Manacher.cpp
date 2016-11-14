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

const int MAX=100000+10;
char a[MAX],b[MAX];
int next[MAX],extend[MAX],p[MAX];

/******************************************************************************/

KMP:
void get_next(char *a,int len){
	int i=-1,j=0;
	next[0]=-1;
	while(j<len){
		if(i == -1 || a[i] == a[j]){
			if(a[++i] == a[++j])next[j]=next[i];//如果需要用到next的性质就不要用这一步优化,这一步主要是在KMP时:a[j] != b[k],a[j] == a[i],j=next[j]=next[i]
			else next[j]=i;
		}else i=next[i];
	}
}

int KMP(char *a,char *b){
	int lena=strlen(a),lenb=strlen(b),i=0,j=0;
	get_next(a,lena);
	while(j<lenb && i<lena){
		if(i == -1 || a[i] == b[j])++i,++j;
		else i=next[i];
	}
	return i;//i == lena表示a是b的字串 
}
/******************************************************************************/

Manacher:
void manacher(char *s){
	int len=strlen(s);
	for(int i=len;i>=0;--i){
		s[i+i+2]=s[i];
		s[i+i+1]='#';
	}
	s[0]='*';
	int k=1,maxlen=0;
	for(int i=2;i<len+len+1;++i){
		int maxr=k+p[k]-1;
		p[i]=min(p[2*k-i],max(maxr-i+1,1));
		while(s[i-p[i]] == s[i+p[i]])++p[i];
		if(i+p[i]>k+p[k])k=i;
		if(p[i]>maxlen)maxlen=p[i];
	}
}
/******************************************************************************/

EKMP:
void get_next(char *a,int len){
	int k=0,i=1;
	next[0]=len;
	while(k<len && a[k] == a[k+1])++k;//可以事先a[len]='*',则可以不必k<len且下面也不用判断<len 
	next[1]=k;
	k=1;
	while(++i<len){
		int maxr=k+next[k]-1;
		next[i]=min(next[i-k],max(maxr-i+1,0));
		while(i+next[i]<len && a[next[i]] == a[i+next[i]])++next[i];
		if(i+next[i]>k+next[k])k=i;
	}
}

void EKMP(char *a,char *b){
	int lena=strlen(a),lenb=strlen(b),k=0,i=0;
	get_next(a,lena);
	b[lenb]='*';//b[lenb]重置为a,b里没出现的字符 
	while(a[k] == b[k])++k;//如果没有重置b[lenb],应为k<lenb && a[k] == b[k] 
	extend[0]=k;
	k=0;
	while(++i<lenb){
		int maxr=k+extend[k]-1;
		extend[i]=min(next[i-k],max(maxr-i+1,0));
		while(a[extend[i]] == b[i+extend[i]])++extend[i];//如果没有重置b[lenb],需判断i+extend[i]<lenb
		if(i+extend[i]>k+extend[k])k=i;
	}
}
/******************************************************************************/

int main(){
	while(cin>>a>>b){
		KMP(a,b);
		manacher(a);
		EKMP(a,b);
	}
	return 0;
} 