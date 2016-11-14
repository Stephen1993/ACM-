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
const int MAX=10002;
int n,m,s[MAX];
int main(){
	while(cin>>n>>m){
		for(int i=1;i<=n;++i){
			s[i]=i;
		}
		while(--m){ 
			next_permutation(s+1,s+n+1);
		}
		for(int i=1;i<=n;++i){
			printf("%d%c",s[i],i==n?'\n':' ');
		}
	}
	return 0;
} 