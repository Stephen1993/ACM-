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
const int MAX=1000001;
bool mark[MAX];
int main(){
	int sum,num;
	for(int i=1;i<MAX;++i){
		sum=i;
		num=i;
		while(num){
			sum+=num%10;
			num=num/10;
		}
		if(sum<MAX){
			mark[sum]=true;
		}
		if(!mark[i])printf("%d\n",i);
	}
	return 0;
} 