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

const int MAX=10000+10;
char a[MAX],b[1000000];
int next[MAX];

void get_next(char *a){
	int i=-1,j=0,len=strlen(a);
	next[0]=-1;
	while(j<len){
		if(i == -1 || a[i] == a[j]){
			if(a[++i] == a[++j])next[j]=next[j];
			else next[j]=i;
		}else i=next[i];
	}
	return;
}

int KMP(char *a,char *b){
	get_next(a);
	int i=0,j=0,num=0,lena=strlen(a),lenb=strlen(b);
	b[lenb]='#';
	while(j<=lenb){//不需要i<lena,要把b全部比较完 
		if(i == -1 || a[i] == b[j])++i,++j;
		else{//
			if(i == lena)++num;//表示有一个a 
			i=next[i];
		}
	}
	return num;
}

int main(){
	int n;
	cin>>n;
	while(n--){
		cin>>a>>b;
		cout<<KMP(a,b)<<endl;
	}
	return 0;
} 