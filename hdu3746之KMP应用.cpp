#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 9999999
using namespace std;

const int MAX=100000+10;
char s[MAX];
int next[MAX];

void get_next(char *a){
	int i=-1,j=0,len=strlen(a);
	next[0]=-1;
	while(j<len){
		if(i == -1 || a[i] == a[j])next[++j]=++i;
		else i=next[i];
	}
	return;
}

int main(){
	int n;
	scanf("%d",&n);
	while(n--){
		scanf("%s",s);
		get_next(s);
		int len=strlen(s),round=len-next[len];
		int t=(round-(len%round))%round;
		if(t == 0 && len/round == 1)t+=round;
		cout<<t<<endl;
	}
	return 0;
}