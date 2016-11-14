#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<queue>
#include<iomanip>
#include<map>
#define INF 9999999
using namespace std;
const int MAX=10001;
const int mod=10000007;
int fn[MAX];
int a,b,c,d,e,f,n;
int main(){
	int t;
	cin>>t;
	int num=1;
	while(t--){
		scanf("%d%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f,&n);
		fn[0]=a%mod;
		fn[1]=b%mod;
		fn[2]=c%mod;
		fn[3]=d%mod;
		fn[4]=e%mod;
		fn[5]=f%mod;
		for(int i=6;i<=n;++i){
			fn[i]=(fn[i-1]+fn[i-2]+fn[i-4]+fn[i-5]+fn[i-6]+fn[i-3])%mod;
		}
		printf("Case %d: %d\n", num++, fn[n] );
	}
	return 0;
} 