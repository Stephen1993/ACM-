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
const int MAX=1000;
char a[MAX],b[MAX];
int s[MAX][MAX];
int main(){
	while(cin>>a>>b){
		memset(s,0,sizeof s);
		int la=strlen(a);
		int lb=strlen(b);
		for(int i=0;i<la;++i){
			for(int j=0;j<lb;++j){
				if(a[i]==b[j]){
					s[i+1][j+1]=s[i][j]+1;
				}
				else{
					s[i+1][j+1]=max(s[i][j+1],s[i+1][j]);
				}
			}
		}
		cout<<s[la][lb]<<endl;
	}
	return 0;
}