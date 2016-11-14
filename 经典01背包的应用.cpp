//http://codeforces.com/contest/366/problem/C
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=2*100000+10;
int a[110],c[110],wa[MAX],wb[MAX],*f=&wa[102000],*g=&wb[102000];

int main(){
	int n,k,b;
	while(cin>>n>>k){
		int x=0,y=0,sum=0;
		for(int i=0;i<n;++i)cin>>a[i];
		for(int i=0;i<n;++i){
			cin>>b;
			c[i]=a[i]-b*k;//(a[i]-c[i])/b=k => c[i]=a[i]-b*k
			if(c[i]<0)x+=c[i];
			else y+=c[i];
		}
		for(int i=x-100;i<=y+1000;++i)f[i]=g[i]=-INF;
		//01背包,c[i]作为重量,a[i]作为价值 
		g[0]=0;
		for(int i=0;i<n;++i){
			for(int j=x;j<=y;++j){
				f[j]=g[j];
				f[j]=max(f[j],g[j-c[i]]+a[i]);//c[i]将a[i]和b[i]联系起来了 
			}
			sum=f[0]>sum?f[0]:sum;
			swap(f,g);
		}
		if(!sum)sum=-1;
		cout<<sum<<endl;
	}
	return 0;
}