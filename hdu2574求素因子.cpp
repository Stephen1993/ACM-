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

const int MAX=1000+10;
char s[MAX][25];

int factor(int x){
	int num=0;
	if(x%2 == 0){
		++num;
		while(x%2 == 0)x=x/2;
	}
	for(int i=3;i*i<=x;++i){
		if(x%i == 0){
			++num;
			while(x%i == 0)x=x/i;
		}
	}
	if(x != 1)++num;
	return num;
}

int main(){
	int t,n,m,num,temp;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int num=-1,id=-1;
		for(int i=0;i<n;++i){
			scanf("%s%d",s[i],&m);
			if(!m)temp=0;//这里一定要判断m == 0,因为m=0则求素因子会死循环 
			else temp=factor(m);
			if(temp > num)id=i,num=temp;
			else if(temp == num && strcmp(s[id],s[i])>0)id=i;
		}
		printf("%s\n",s[id]);
	}
	return 0;
}