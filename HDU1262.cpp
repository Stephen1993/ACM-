#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<cmath>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=10001;
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
}
void search(int &n){
	int a=n/2;
	for(int i=a;i>=2;--i){
		if(!prime[i]&&!prime[n-i]){
			cout<<i<<' '<<n-i<<endl;
			break;
		}
	}
	return;
}
int main(){
	int m;
	Prime();
	while(scanf("%d",&m)!=EOF){
		search(m);
	}
	return 0;
}