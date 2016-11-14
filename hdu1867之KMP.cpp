#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=100000+10;
char a[MAX],b[MAX];
int next[MAX];

void get_next(char *a,int len){
	int i=-1,j=0;
	next[0]=-1;
	while(j<len){
		if(i == -1 || a[i] == a[j]){
			if(a[++i] == a[++j])next[j]=next[i];
			else next[j]=i;
		}else i=next[i];
	}
}

int KMP(char *a,char *b,int lena,int lenb){
	get_next(a,lena);
	int i=0,j=0;
	while(i<lena && j<lenb){
		if(i == -1 || a[i] == b[j])++i,++j;
		else i=next[i];
	}
	if(i<lena || (i == lena && j == lenb))return i;//a不能是b中间部分的字串 
	return 0;
}

int main(){
	while(cin>>a>>b){
		int lena=strlen(a),lenb=strlen(b);
		int la=KMP(a,b,lena,lenb);
		int lb=KMP(b,a,lenb,lena);
		if(la>lb || (la == lb && strcmp(a,b)>0)){
			cout<<b;
			for(int i=la;i<lena;++i)cout<<a[i];
		}
		else{
			cout<<a;
			for(int i=lb;i<lenb;++i)cout<<b[i];
		}
		cout<<endl;
	}
	return 0;
} 