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
char s1[MAX],s2[MAX];
int next[MAX];

void get_next(char *a){
	int len=strlen(a);
	int j=-1,i=0;
	next[0]=-1;
	while(i<len){
		if(j == -1 || a[i] == a[j]){
			if(a[++i] != a[++j])next[i]=j;
			else next[i]=next[j];
		}else j=next[j];
	}
}

bool KMP(char *a,char *b){
	int lena=strlen(a),lenb=strlen(b);
	int i=0,j=0;
	while(j<lena){
		if(j == -1 || b[i] == a[j])i=(i+1)%lenb,++j;
		else j=next[j];
		if( i == 0 && j == 0)break;//表示匹配主串又是从第一位开始匹配 
	}
	if(j == lena)return true;
	else return false;
}

int main(){
	while(cin>>s1>>s2){
		if(strlen(s2)>strlen(s1)){cout<<"no"<<endl;continue;}
		get_next(s2);
		if(KMP(s2,s1))cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
	return 0;
}