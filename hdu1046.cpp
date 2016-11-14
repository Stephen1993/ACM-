#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<map>
#include<cstring>
#include<string>
#include<iomanip>
#include<cmath>
#define INF 99999999
using namespace std;
const int MAX=10;
int n,m;
int main(){
	int t,num=1;
	cin>>t;
	while(t--){
	    cin>>n>>m;
	    cout<<"Scenario #"<<num++<<":\n";
		if((m*n)&1){
			cout<<fixed<<setprecision(2)<<(m*n-1)+sqrt(2)<<endl;
		}
		else{
			cout<<fixed<<setprecision(2)<<m*n*1.0<<endl;
		}
		cout<<endl;
	}
	return 0;
}
/*
如果m*n为偶数即偶数个小镇，则上面有m*n/2个，下面也有m*n/2个即可
如果m*n为奇数个则先减去1，但是最后的长度还要加上sqrt(2)
*/ 