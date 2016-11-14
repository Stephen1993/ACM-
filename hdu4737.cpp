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
int s[MAX],digit[33],pow[31]={1};

void digitAdd(int n){
	int size=-1;
	while(n)digit[++size]+=n%2,n=n/2;
}

void digitSub(int n){
	int size=-1;
	while(n)digit[++size]-=n%2,n=n/2;
}

int f(){
	int size=0,sum=0;
	for(int i=0;i<31;++i)sum+=(digit[i]>0)*pow[i];
	return sum;
}

int main(){
	for(int i=1;i<31;++i)pow[i]=pow[i-1]*2;
	int t,n,m,Case=0,i,j,k,sum,ans;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(i=0;i<n;++i)scanf("%d",&s[i]);
		sum=ans=i=j=k=0;
		memset(digit,0,sizeof digit);
		while(j<n){
			if((f()|s[j])<m)digitAdd(s[j]),sum+=j-i+1,++j;
			else {if(i<j)digitSub(s[i]);++i;}
			if(i>j)j=i;
		}
		printf("Case #%d: %d\n",++Case,sum);
	}
	return 0;
}