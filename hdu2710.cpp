#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=20001;
int prime[MAX]={0,1};

int Prime(){
	for(int i=2;i<MAX;i++){
		if(!prime[i]){
			for(int j=i;j<MAX;j+=i){
				prime[j]=i;
			}
		}
	}
} 

int main(){
	Prime();
	int n,a;
	while(cin>>n){
		int m=0;
		for(int i=0;i<n;++i){
			cin>>a;
			if(prime[a] >= prime[m]){
				if(prime[a]>prime[m])m=a;
				else if(a<m)m=a;
			}
		}
		cout<<m<<endl;
	}
	return 0;
}