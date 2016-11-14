#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<map>
#include<cstring>
#include<string>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=100;
int n,m;
/*int per_and_com(int n,int m){
	if(n<=m){
		return 1;
	}
	if(m==1){
		return n;
	}
	return per_and_com(n-1,m)+per_and_com(n-1,m-1);//c(n,m)=c(n-1,m)+c(n-1,m-1);
}*/
int per_and_com(int n,int m){
	int sum=1;
	for(int i=1;i<=m;++i){
		sum=sum*(n-m+i)/i;//n*(n-1)*...*(n-m+1)/(m*(m-1)*....*1)按照从(n-m+1)/1*...乗一个除一个可以防溢出还有可整除.
	}
	cout<<sum<<endl;
	return sum;
}
int main(){
	while(cin>>n>>m){
		cout<<per_and_com(n,m)<<endl;
	}
	return 0;
}
