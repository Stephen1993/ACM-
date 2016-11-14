#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=8002;
int f[MAX][700];
int main(){
	f[1][0]=f[2][0]=f[3][0]=f[4][0]=f[1][1]=f[2][1]=f[3][1]=f[4][1]=1;
	for(int i=5;i<=8000;++i){
		int len=max(max(f[i-1][0],f[i-2][0]),max(f[i-3][0],f[i-4][0]));
		int c=0;
		for(int j=1;j<=len;++j){
			f[i][j]=f[i-1][j]+f[i-2][j]+f[i-3][j]+f[i-4][j]+c;
			c=f[i][j]/10000;
			f[i][j]%=10000;
		}
		while(c){
			f[i][++len]=c%10000;
			c=c/10000;
		}
		f[i][0]=len;
	}
	int n;
	while(cin>>n){
		cout<<f[n][f[n][0]];
		for(int i=f[n][0]-1;i>=1;--i){
			cout<<setfill('0')<<setw(4)<<f[n][i];
		}
		cout<<endl;
	}
	return 0;
}