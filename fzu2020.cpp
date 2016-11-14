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

int Ext_gcd(int a,int b,int &x,int &y){
	if(b == 0){
		x=1,y=0;
		return a;
	}
	int gcd=Ext_gcd(b,a%b,y,x);
	y=y-(a/b)*x;
	return gcd;
}

int inv(int a,int mod){
	int x,y,gcd;
	gcd=Ext_gcd(a,mod,x,y);
	if(gcd == 1)return (x%mod+mod)%mod;
	else return -1;
}

int main(){
	int n,m,p,t;
	cin>>t;
	while(t--){
	    cin>>n>>m>>p;
		__int64 sum=1,temp=1;
		for(int i=1;i<=m;++i)sum=(sum*(n-m+i))%p,temp=(temp*i)%p;
		sum=(sum*inv(temp,p))%p;
		cout<<sum<<endl;
	}
	return 0;
}