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

const int MAX=1000000+10;
char s[MAX*2];
int p[MAX*2];

int main(){
	int num=0;
	while(scanf("%s",s),s[0] != 'E'){
		int len=strlen(s);
		for(int i=len;i>=0;--i){
			s[i+i+2]=s[i];
			s[i+i+1]='#';
		}
		s[0]='*';
		int k=1,maxlen=0;
		for(int i=2;i<len+len+1;++i){
			int maxr=k+p[k]-1;
			p[i]=min(p[2*k-i],max(maxr-i+1,1));
			while(s[i-p[i]] == s[i+p[i]])++p[i];
			if(i+p[i]>k+p[k])k=i;
			if(p[i]>maxlen)maxlen=p[i];
		}
		cout<<"Case "<<++num<<": "<<maxlen-1<<endl;
	}
	return 0;
}