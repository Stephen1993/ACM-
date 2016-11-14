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

int get_next(char *a){
	int i=-1,j=0,len=strlen(a);
	next[0]=-1;
	while(j<len){
		if(i == -1 || a[i] == a[j])next[++j]=++i;
		else i=next[i];
	}
	if(len%(len-next[len]) == 0)return len/(len-next[len]);
	return 1;
}

int main(){
	while(cin>>s,s[0] != '.'){
		cout<<get_next(s)<<endl;
	}
	return 0;
}