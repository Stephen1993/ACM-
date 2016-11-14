#include<iostream>
using namespace std;
const int MAX=32768;
int s[MAX]={0};
void shaixuan(){
	for(int i=2;i<=MAX;++i){
		if(!s[i]){
			for(int j=2*i;j<MAX;j+=i){
				s[j]=1;
			}
		}
	}
}
int main(){
	shaixuan();
	int n;
	while(cin>>n,n){
		int num=0;
		for(int i=2;i<=n/2;++i){
			if(!s[i]&&!s[n-i])num++;
		}
		cout<<num<<endl;
	}
	return 0;
}
