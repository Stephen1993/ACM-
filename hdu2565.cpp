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

const int MAX=10;

int main(){
	int n,t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n/2;++i){
			for(int k=0;k<i;++k)cout<<' ';
			cout<<'X';
			for(int j=i+1;j<n-1-i;++j)cout<<' ';
			cout<<'X'<<endl;;
		}
		for(int k=0;k<n/2;++k)cout<<' ';
		cout<<'X'<<endl;
		for(int i=n/2-1;i>=0;--i){
			for(int k=0;k<i;++k)cout<<' ';
			cout<<'X';
			for(int j=i+1;j<n-1-i;++j)cout<<' ';
			cout<<'X'<<endl;;
		}
		cout<<endl;
	}
	return 0;
}