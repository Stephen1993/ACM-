/*
KMP不多做介绍，有个小优化就是查找长度时从最长开始查找，只要查找到了就断开输出 
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

const int MAX=100+10;
char s[MAX][MAX],temp1[MAX],temp2[MAX];
int next[MAX];

void Strcpy(char *a,char *b,int S,int T){
	int k=0;
	for(int i=S;i<=T;++i){
		a[k++]=b[i];
	}
	a[k]='\0';
}

void get_next(char *a){
	int i=0,j=-1;
	next[0]=-1;
	while(i<strlen(a)){
		if(j == -1 || a[i] == a[j]){
			if(a[++i] != a[++j])next[i]=j;
			else next[i]=next[j];
		}else j=next[j];
	}
	return;
}

bool KMP(char *a,char *b){
	int i=0,j=0,lena=strlen(a),lenb=strlen(b);
	if(lena>lenb)return false;
	get_next(a);
	while(i<lena && j<lenb){
		if(i == -1 || a[i] == b[j])++i,++j;
		else i=next[i];
	}
	if(i>=lena)return true;
	return false;
}

int main(){
	int t,n,k;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;++i)cin>>s[i];
		int len=strlen(s[0]),maxlen=0;
		for(int i=0;i<len;++i){
			for(int j=i;j<len;++j){
				Strcpy(temp1,s[0],i,j);
				int L=strlen(temp1);
				for(k=0;k<L;++k)temp2[k]=temp1[L-1-k];
				temp2[L]='\0';
				for(k=1;k<n;++k){
					if(!KMP(temp1,s[k]) && !KMP(temp2,s[k]))break;
				}
				if(k == n)maxlen=max(maxlen,j-i+1);
			}
		}
		cout<<maxlen<<endl;
	}
	return 0;
}