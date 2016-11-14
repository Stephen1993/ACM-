#include<iostream>
using namespace std;
__int64 n,m;
__int64 per_and_com(__int64 n,__int64 m){
	__int64 sum=1;
	for(__int64 i=1;i<=m;++i){
		sum=sum*(n-m+i)/i;
	}
	return sum;
}
int main(){
	while(cin>>n>>m,n||m){
		cout<<per_and_com(n+m,min(n,m))<<endl;
	}
	return 0;
}