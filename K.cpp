#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<queue>
#include<algorithm>
#include<iomanip>
#define INF 999999
using namespace std;
const int MAX=11111;
int main(){
	int a,b;
	while(scanf("%d%d",&a,&b),a||b){
		int num=1;
		int sum=a%1000;
		while(num<b){
			sum=sum*a%1000;
			num++;
		}
		cout<<sum<<endl;
	}
	return 0;
}