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
const int MAX=40;
__int64 s[MAX][MAX];
char p[MAX][MAX];
int main(){
	int n,a,b;
	while(cin>>n,n>0){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				cin>>p[i][j];
			}
		}
		memset(s,0,sizeof s);
		s[0][0]=1;
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				if(p[i][j]=='0')continue;
				a=i+p[i][j]-'0';
				b=j+p[i][j]-'0';
				if(a<n)s[a][j]+=s[i][j];
				if(b<n)s[i][b]+=s[i][j];
			}
		}
		cout<<s[n-1][n-1]<<endl;
	}
	return 0;
}