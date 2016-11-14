#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<iomanip>
#include<queue>
#include<limits.h>
using namespace std;
const int MAX=10000;
bool prime[MAX]={false};
int num,n;
void calculate(){
	for(int i=2;i<=MAX;++i){
		if(!prime[i]){
			for(int j=2;j<=MAX/i;++j){
				prime[j*i]=true;
			}
		}
	}
}
bool dfs(int m){
	num+=m;
	if(num==n)return true;
	if(num>n)return false;
	if(m<=2)return false;
	while(prime[--m]);
	return dfs(m);
}
int main(){
	calculate();
	while(scanf("%d",&n),n){
		int sum=0;
		for(int i=n;i>=2;--i){
			num=0;
			if(!prime[i]){
				if(dfs(i))sum++;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}