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

const int MAX=1000001;
char s[MAX];
int next[MAX],n;

void get_next(char *s){
	int i=0,j=-1;
	next[0]=j;
	while(i<n){
		if(j == -1 || s[i] == s[j])next[++i]=++j;
		else j=next[j];
	}
	return;
}

int main(){
	int num=1;
	while(scanf("%d",&n),n){
		scanf("%s",s);
		get_next(s);
		printf("Test case #%d\n",num++);
		for(int i=1;i<=n;++i){
			if(i%(i-next[i])==0 && next[i] != 0){
				printf("%d %d\n",i,i/(i-next[i]));
			}
		}
		cout<<endl;
	}
	return 0;
}