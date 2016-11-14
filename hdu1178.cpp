#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
#include<queue>
#include<cstdlib>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=100;
int n;
float sum;
int main(){
	while(scanf("%d",&n),n){
		sum=1.0/6*n*(n+1)*(n+2);
		int num=0;
		while(sum>=10){
			sum=sum/10;
			num++;
		}
		cout<<fixed<<setprecision(2)<<sum<<"E"<<num<<endl; 
	}
	return 0;
} 