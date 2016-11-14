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
char s[MAX];

int main(){
	int n;
	while(scanf("%d",&n),n){
		scanf("%s",s);
		int H=0,T=0;
		for(int i=0;i<n;++i){
			if(s[i] == 'H')++H;
			else ++T;
		}
		if(H%2 || T%2)printf("-1\n");
		else{
			int a=0,b=0,head=0,h=H/2,t=T/2,i;
			for(i=0;i<n;++i){
				if(a == h && b == t)break;
				if(s[i] == 'H')++a;
				else ++b;
				if(a>h || b>t){
					if(s[head] == 'H')--a;
					else --b;
					++head;
				}
			}
			if(head)printf("2\n%d %d\n",head,i);
			else printf("1\n%d\n",i);
		}
	}
	return 0;
}