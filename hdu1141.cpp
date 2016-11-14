#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<cmath>
#define INF 99999999
using namespace std;
const int MAX=200;
int main(){
	int n;
	while(cin>>n,n){
		n=(n-1960)/10+2;
		n=1<<n; 
		double s=0,i=0;
		while(++i){//用对数来比较》 
			s+=log10(i)/log10(2);
			if(s>=n){
				cout<<i-1<<endl;//其实每次求到结果可以储存起来,下次就不用继续求. 
				break;
			}
		}
	}
	return 0;
}