//http://codeforces.com/contest/276/problem/C

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 999999999
using namespace std;

const int MAX=100001;
__int64 s[2*MAX],x[2*MAX];

int main(){
	int n,q,a,b;
	while(cin>>n>>q){
		for(int i=0;i<n;++i)cin>>s[i];
		for(int i=0;i<q;++i){
			cin>>a>>b;
			++x[a];
			--x[b+1];
		}
		for(int i=1;i<=n;++i)x[i]+=x[i-1];
		sort(s,s+n+1);
		sort(x,x+n+1);
		__int64 sum=0;
		for(int i=n;i>=1;--i)sum+=x[i]*s[i];
		cout<<sum<<endl;
	}
	return 0;
}