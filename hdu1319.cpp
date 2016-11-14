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
using namespace std;

const int MAX=1001;
bool prime[MAX];

void Prime(){
	for(int i=2;i<=MAX/2;++i)prime[i*2]=true;
	for(int i=3;i<=sqrt(MAX);i+=2){
		if(!prime[i]){
			for(int j=i*i;j<MAX;j+=2*i){
				prime[j]=true;
			}
		}
	}
	return;
} 

int main(){
	int a,b;
	Prime();
	while(cin>>a>>b){
		cout<<a<<' '<<b<<':';
		int num=0;
		int s[a];
		for(int i=1;i<=a;++i){
			if(!prime[i]){
				s[num++]=i;
			}
		}
		if(num<=2*b){
			for(int i=0;i<num;++i){
				cout<<' '<<s[i];
			}
		}
		else{
			int n=(num-1)/2-(b-1);
			int m=n+(2*b)-1;
			if(num&1)m--;
			for(int i=n;i<=m;++i)
			   cout<<' '<<s[i];
		}
		cout<<endl<<endl;
	}
	return 0;
}