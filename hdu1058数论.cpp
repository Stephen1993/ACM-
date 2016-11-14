#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=5844;
int s[MAX]={1,1};
int prime[4]={2,3,5,7};
int a[4];
void shuaixuan(){
	for(int i=2;i<=5842;++i){
		for(int j=0;j<4;++j){
			while(prime[j]*s[a[j]]<=s[i-1])a[j]++;
		}
		int min=2000000001;
		for(int j=0;j<4;++j){
			if(prime[j]*s[a[j]]<min){
				min=prime[j]*s[a[j]];
			}
		}
		s[i]=min;
	}
}
int main(){
	shuaixuan();
	int n;
	while(scanf("%d",&n),n){
		if(n%10==1&&n%100!=11){
			printf("The %dst humble number is %d.\n",n,s[n]);
		}
		else if(n%10==2&&n%100!=12){
			printf("The %dnd humble number is %d.\n",n,s[n]);
		}
		else if(n%10==3&&n%100!=13){
			printf("The %drd humble number is %d.\n",n,s[n]);
		}
		else{
			printf("The %dth humble number is %d.\n",n,s[n]);
		}
	}
	return 0;
}