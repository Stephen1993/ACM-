#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#define INF 999999999
using namespace std;
const int MAX=7;
int b,a,d,c;
int main(){
	cin>>a>>b;
	c=b;
	d=0;
	while(c){
		d=d*10+c%10;
		c=c/10;
	}
	while(1){
		int n=b;
		c=0;
		if(n>a)
		while(n){
			if(n%10==4||n%10==7){
				c=c*10+n%10;
			}
			n=n/10;
		}
		if(c==d){
			cout<<b<<endl;
			break;
		}
		b++;
	}
	return 0;
}