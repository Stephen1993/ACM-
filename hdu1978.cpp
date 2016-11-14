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

const int MAX=101;
int s[MAX][MAX];

int main(){
	int n,m,a,t;
	cin>>t;
	while(t--){
	    cin>>n>>m;
		memset(s,0,sizeof s);
		s[0][0]=1;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				cin>>a;
				for(int k=0;k<=a&&k+i<n;k++){
					for(int l=0;l+k<=a&&l+j<m;++l){
						if(l == 0 && k == 0)continue;
						s[i+k][l+j]=(s[i+k][j+l]+s[i][j])%10000;
					}
				}
			}
		}
		cout<<s[n-1][m-1]<<endl;
	}
	return 0;
}