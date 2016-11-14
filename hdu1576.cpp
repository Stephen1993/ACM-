#include<iostream>
using namespace std;
int main(){
	__int64 A,B,N,t;
	cin>>t;
	while(t--){
		cin>>N>>B;
		__int64 sum;
		__int64 num=B%9973;
		for(int i=0;;++i){
			if((N+i*9973)%num==0){
				cout<<(N+i*9973)/num<<endl;
				break;
			}
		}
	}
	return 0;
}