#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int s[1001]={0};
	s[3]=1;
	int a=3;
	for(int i=4;i<1001;++i){
		if(log2(i-a)!=int(log2(i-a))){
			s[i]=1;
			a=i;
		}
	}
	int n;
	while(cin>>n){
		if(s[n])cout<<"Cici"<<endl;
		else cout<<"Kiki"<<endl;
	}
	return 0;
}