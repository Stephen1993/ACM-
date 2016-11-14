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

const int MAX=4000+10;
char s[MAX][210],temp[210],temp2[210];
int next[210];

void Strcpy(char *a,char *b,int S,int T){
	int k=0;
	for(int i=S;i<=T;++i)a[k++]=b[i];
	a[k]='\0';
}

void get_next(char *a){
	int i=-1,j=0,len=strlen(a);
	next[0]=-1;
	while(j<len){
		if(i == -1 || a[i] == a[j]){
			if(a[++i] == a[++j])next[j]=next[i];
			else next[j]=i;
		}else i=next[i];
	}
	return;
}

bool KMP(char *a,char *b){
	int lena=strlen(a),lenb=strlen(b);
	if(lena>lenb)return false;
	get_next(a);
	int i=0,j=0;
	while(i<lena && j<lenb){
		if(i == -1 || a[i] == b[j])++i,++j;
		else i=next[i];
	}
	if(i>=lena)return true;
	return false;
}

int main(){
	int n,k;
	while(cin>>n,n){
		for(int i=0;i<n;++i)cin>>s[i];
		int len=strlen(s[0]),flag=0;
		for(int i=len;i>0;--i){
			for(int j=0;j+i-1<len;++j){//取长度为i的字符串并且从j开始 
				Strcpy(temp,s[0],j,j+i-1);
				for(k=1;k<n;++k){
					if(!KMP(temp,s[k]))break;
				}
				if(k == n){
					if(flag){if(strcmp(temp2,temp)>0)strcpy(temp2,temp);}
					else strcpy(temp2,temp);
					flag=true; 
				}
			}
			if(flag)break;
		}
		if(!flag)cout<<"IDENTITY LOST"<<endl;
		else cout<<temp2<<endl;
	}
	return 0;
}