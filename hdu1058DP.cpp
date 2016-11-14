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

const int MAX=5845;
int s[MAX]={1,1};//记录第i个humble numbers. 
int prime[]={2,3,5,7};//数种只含的四种素因子. 
int num[4];//用来确定s中第几个数分别*2,*3,*5,*7能刚好大于s中的最大数. 

void calculate(){
	for(int i=2;i<MAX;++i){
		for(int j=0;j<4;++j){
			while(s[num[j]]*prime[j]<=s[i-1])++num[j];//求分别增加因子2,3,5,7的最小的数能够刚好大于s中的最大的数. 
		}
		s[i]=min(min(s[num[0]]*2,s[num[1]]*3),min(s[num[2]]*5,s[num[3]]*7));//将四种情况(增加因子2,3,5,7)中的最小的数给s[i]. 
	}
}

int main(){
	int n;
	calculate();
	while(cin>>n,n){
		if(n%10 == 1 && n%100 != 11)printf("The %dst humble number is %d.\n",n,s[n]);
		else if(n%10 == 2 && n%100 !=12)printf("The %dnd humble number is %d.\n",n,s[n]);
		else if(n%10 == 3 && n%100 != 13)printf("The %drd humble number is %d.\n",n,s[n]);
		else printf("The %dth humble number is %d.\n",n,s[n]);
	}
	return 0;
}