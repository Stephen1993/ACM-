#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <map>
#include <cmath>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=20000+10;
int n,m;
int digit[13],bin[13];
LL dp[MAX],temp[MAX];//对应j位为0表示第j位竖着,2表示j-1位竖着,1表示j被填充

bool check(int i,int j){
	int num=0;
	while(num<m){
		int a=i%3,b=j%3;
		if(a == 0 && b != 1)return false;
		if(a == 2 && b != 0)return false;
		if(a == 1 && b == 0)return false;
		if(a == 0 || a == 2)i=i/3,j=j/3,++num;
		if(a == 1){
			if(b == 2)i=i/3,j=j/3,++num;
			else{
				i=i/3,j=j/3,++num;
				a=i%3,b=j%3;
				if(a != 1)return false;
				if(b != 1)return false;
				i=i/3,j=j/3,++num;
				a=i%3,b=j%3;
				if(a != 1)return false;
				if(b != 1)return false;
				i=i/3,j=j/3,++num;
			}
		}
	}
	return true;
}

void cal(int i){
	int size=0;
	memset(digit,0,sizeof digit);
	while(i)digit[size++]=i%3,i=i/3;
}

void dfs(int id,int k,int i,int j){//dfs搜索i能到达的状态j 
	if(k>m)return;
	if(k == m){dp[j]+=temp[i];return;}
	if(digit[k] == 0){
		dfs(id,k+1,i,j+bin[k]*2);
	}
	if(digit[k] == 2){
		dfs(id,k+1,i,j+bin[k]*1);
	}
	if(digit[k] == 1){
		dfs(id,k+1,i,j+bin[k]*0);
		if(digit[k+1] == 1 && digit[k+2] == 1)
			dfs(id,k+3,i,j+bin[k]+bin[k+1]+bin[k+2]);
	}
}

void DP(){
	int bit=1,num=1;
	for(int i=1;i<=m;++i)bit=bit*3,num=num+bit;
	num-=bit;
	memset(temp,0,sizeof temp);
	for(int i=0;i<bit;++i)if(check(i,num))temp[i]=1;
	for(int k=0;k<n-1;++k){
		for(int i=0;i<bit;++i)dp[i]=0;
		for(int i=0;i<bit;++i){
			cal(i);
			dfs(k,0,i,0);
		}
		for(int i=0;i<bit;++i)temp[i]=dp[i];
	}
	printf("%lld\n",temp[num]);
}

int main(){
	bin[0]=1;
	for(int i=1;i<=10;++i)bin[i]=bin[i-1]*3;
	while(~scanf("%d%d",&m,&n),n+m){
		DP();
	}
	return 0;
}
/*
void dfs(int id,int k,int i,int j){//由i逆推到能到达i的状态j 
	if(k>m)return;
	if(k == m){dp[i]+=temp[j];return;}
	if(digit[k] == 0){
		dfs(id,k+1,i,j+bin[k]*1);
	}
	if(digit[k] == 2){
		dfs(id,k+1,i,j+bin[k]*0);
	}
	if(digit[k] == 1){
		dfs(id,k+1,i,j+bin[k]*2);
		if(digit[k+1] == 1 && digit[k+2] == 1)
			dfs(id,k+3,i,j+bin[k]+bin[k+1]+bin[k+2]);
	}
}

void DP(){
	int bit=1,num=1;
	for(int i=1;i<=m;++i)bit=bit*3,num=num+bit;
	num-=bit;
	memset(temp,0,sizeof temp);
	for(int i=0;i<bit;++i)if(check(i,num))temp[i]=1;
	for(int k=1;k<n;++k){
		for(int i=0;i<bit;++i)dp[i]=0;
		for(int i=0;i<bit;++i){
			cal(i);
			dfs(k,0,i,0);
		}
		for(int i=0;i<bit;++i)temp[i]=dp[i];
	}
	printf("%lld\n",temp[num]);
}
*/