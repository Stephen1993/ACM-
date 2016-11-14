#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<iomanip>
#include<limits.h>
using namespace std;
const int MAX=1000000;
bool prime[MAX]={false};
void calculate(){
	for(int i=2;i<=MAX;++i){
		if(!prime[i]){
			for(int j=2;j<=MAX/i;++j){
				prime[j*i]=true;
			}
		}
	}
}
int main(){
	calculate();
	int n;
	while(scanf("%d",&n),n){
		for(int i=2;i<=MAX;++i){
			if(!prime[i]&&(!prime[n-i])){
				printf("%d = %d + %d\n",n,i,n-i);
				break;
			}
		}
	}
	return 0;
}