#include<iostream>
using namespace std;
const int MAX=1000000;
int s[MAX]={0},p[1001]={0};
int main(){
	for(int i=1;i<=MAX/2;++i){
		for(int j=2*i;j<MAX;j+=i){
			s[j]+=i;
		}
	}
	for(int i=2;i<MAX;++i){
		if(s[i]<=1000){
			p[s[i]]=1;
		}
	}
	int n,t;
	cin>>t;
	while(t--){
		cin>>n;
		if(p[n])cout<<"no"<<endl;
		else cout<<"yes"<<endl;
	}
	return 0;
}