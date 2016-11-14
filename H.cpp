#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<iomanip>
#define INF 999999
using namespace std;
const int MAX=200;
int s[MAX][MAX];
int main(){
	int n;
	while(cin>>n){
		memset(s,0,sizeof s);
		for(int i=0;i<n;++i){
			for(int j=0;j<=i;++j){
				scanf("%d",&s[i][j]);
			}
		}
		for(int i=n-1;i>=0;i--){
			for(int j=0;j<=i;++j){
				s[i][j]=max(s[i+1][j]+s[i][j],s[i+1][j+1]+s[i][j]);
			}
		}
		cout<<s[0][0]<<endl;
	}
	return 0;
}