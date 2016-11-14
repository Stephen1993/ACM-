#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=10+10;

int gcd(int x,int y){
	int temp;
	int power=0;
	if(x == 0)return y;
	if(y == 0)return x;
	while(((x|y)&1) == 0){x=x>>1;y=y>>1;++power;}
	while((x&1) == 0)x=x>>1;
	while(y){
		while((y&1) == 0)y=y>>1;
		temp=y;
		if(x>y)y=x-y;
		else y=y-x;
		x=temp;
	}
	return (x<<power);
}

int Gcd(int x,int y){
	if(y == 0)return x;
	return Gcd(y,x%y);
}

int main(){
	int x,y;
	while(cin>>x>>y){
		cout<<gcd(x,y)<<endl;
	}
	return 0;
}