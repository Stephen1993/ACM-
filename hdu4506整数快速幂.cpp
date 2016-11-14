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

const int MAX=10000+10;
const int mod=1000000000+7;
__int64 s[MAX];

__int64 fastpower(__int64 a,__int64 b){
	__int64 sum=1;
	while(b){
		if(b&1)sum=(sum*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return sum;
}

int main(){
	__int64 t,n,c,k,a;
	cin>>c;
	while(c--){
		cin>>n>>t>>k;
		__int64 sum=fastpower(k,t);
		for(int i=0;i<n;++i){
			cin>>a;
			s[(i+t)%n]=(sum*a)%mod;
		}
		cout<<s[0];
		for(int i=1;i<n;++i)cout<<' '<<s[i];
		cout<<endl;
	}
	return 0;
}