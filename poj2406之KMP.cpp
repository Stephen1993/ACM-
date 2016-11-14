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

const int MAX=1000000+10;
char s[MAX];
int next[MAX];

void get_next(char *a){
	int len=strlen(a);
	int j=-1,i=0;
	next[0]=-1;
	while(i<len){
		if(j == -1 || a[i] == a[j]){
			next[++i]=++j;
		}else j=next[j];
	}
}

int main(){
	while(scanf("%s",s),strcmp(s,".")){
		get_next(s);
		int len=strlen(s);
		if(len%(len-next[len]) == 0)cout<<len/(len-next[len])<<endl;
		else cout<<'1'<<endl;
	}
	return 0;
} 