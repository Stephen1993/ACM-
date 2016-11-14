#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=10;

int main(){
	int n,p,t;
	cin>>t;
	while(t--){
		cin>>n;
		p=0;
		while(n%2==0){
			n=n/2;
			p++;
		}
		cout<<n<<' '<<p<<endl;
	}
	return 0;
}
/*
n=o*2^p ==> log(n)=log(o)+p ==>log(n/o)=p ==> n/o=2^x ==>o=n/(2^x),p=x.
*/