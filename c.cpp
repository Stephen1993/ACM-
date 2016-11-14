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

const int MAX=10;

int main(){
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF){
		__int64 sum1=0,sum=0;
		while(n>3 && m>3){
			sum=min((n-1)/2,(m-1)/2);
		    n=n-sum*2,m=m-sum*2;
		    sum1+=sum*4;
		}
		
		while(--n && m){
		sum1++;
		if(--m && n)sum1++;
		}
		printf("%I64d\n",sum1);
	}
	return 0;
}