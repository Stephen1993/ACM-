//Ã¶¾Ù°üº¬×´Ì¬iµÄ×´Ì¬j: 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=(1<<16)+10;
int len,bit;
int dp[MAX];
char s[20];
bool mark[MAX];

bool check(int x){
	if(x == 0)return true;
	int i=0,j=len-1;
	while(i<j){
		while(!(x&(1<<i)))++i;
		while(!(x&(1<<j)))--j;
		if(s[i] != s[j])return false;
		++i,--j;
	}
	return true;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",s);
		len=strlen(s);
		bit=1<<len;
		dp[bit-1]=0;
		for(int i=0;i<bit;++i)mark[i]=check(i);
		for(int i=bit-2;i>=0;--i){
			dp[i]=INF;
			for(int j = i;j<bit;j=(j+1)|i){
				if(!mark[i^j])continue;
				if(dp[i]>dp[j]+1)dp[i]=dp[j]+1;
			}
		}
		printf("%d\n",dp[0]);
	}
	return 0;
}
/*
Ã¶¾Ù×´Ì¬iµÄ×Ó×´Ì¬: 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=(1<<16)+10;
int len,bit;
int dp[MAX];
char s[20];
bool mark[MAX];

bool check(int x){
	if(x == 0)return true;
	int i=0,j=len-1;
	while(i<j){
		while(!(x&(1<<i)))++i;
		while(!(x&(1<<j)))--j;
		if(s[i] != s[j])return false;
		++i,--j;
	}
	return true;
}

int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",s);
		len=strlen(s);
		bit=1<<len;
		for(int i=0;i<bit;++i)mark[i]=check(i);
		for(int i=0;i<bit;++i)dp[i]=INF;
		dp[bit-1]=0;
		for(int i=bit-1;i>=0;--i){
			for(int j = i;j>0;j=((j-1)&i)){
				if(!mark[i^j])continue;
				if(dp[j]>dp[i]+1)dp[j]=dp[i]+1;
			}
			if(mark[i])if(dp[0]>dp[i]+1)dp[0]=dp[i]+1;
		}
		printf("%d\n",dp[0]);
	}
	return 0;
}
*/