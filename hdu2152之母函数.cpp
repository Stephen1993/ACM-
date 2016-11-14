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

const int MAX=100+10;
int s[MAX][2],x[MAX],y[MAX],sum[MAX];

int main(){
	int n,m,a,b;
	while(cin>>n>>m){
		memset(y,0,sizeof y);
		y[0]=1;
		for(int i=1;i<=n;++i)cin>>s[i][0]>>s[i][1]; 
		for(int i=1;i<=n;++i){
			for(int j=0;j<=m;++j){
				for(int k=s[i][0];k<=s[i][1] && k+j<=m;++k){
					x[j+k]+=y[j];
				}
			}
			for(int j=0;j<=m;++j)y[j]=x[j];
			memset(x,0,sizeof x);
		}
		cout<<y[m]<<endl;
	} 
	return 0;
}