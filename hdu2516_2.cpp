#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#define INF 999999
using namespace std;
const int MAX=100000;
int s[MAX];
int main(){
	int n;
	s[1]=1;
	s[0]=1;
	while(scanf("%d",&n),n){
		bool flag=false;
		for(int i=2;;++i){
			s[i]=s[i-1]+s[i-2];
			if(s[i]==n){
				flag=true;
				break;
			}
			if(s[i]>n){
				break;
			}
		}
		if(flag){
			cout<<"Second win\n";
		}
		else{
			cout<<"First win\n";
		}
	}
	return 0;
} 