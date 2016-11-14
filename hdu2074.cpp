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

const int MAX=41;
string s[MAX];

int main(){
	int n,num=0;
	char a,b;
	while(cin>>n>>a>>b){
		if(num++)cout<<endl;
		if(n == 1){cout<<a<<endl;continue;}
		for(int i=0;i<n/2+1;++i)s[i].clear();
		if(((n-1)/2)&1)for(int i=0;i<n;++i)s[0]+=b;
		else for(int i=0;i<n;++i)s[0]+=a;
		for(int i=1;i<n/2+1;++i){
			s[i]=s[i-1];
			for(int j=i;j<n/2+1;++j){
				if(s[i][j]==a)s[i][j]=s[i][n-1-j]=b;
				else s[i][j]=s[i][n-1-j]=a;
			}
		}
		cout<<' ';
		for(int i=0;i<n-2;++i)cout<<s[0][0];
		cout<<" \n";
		for(int i=1;i<n/2+1;++i)cout<<s[i]<<endl;
		for(int i=n/2-1;i>=1;--i)cout<<s[i]<<endl;
		cout<<' ';
		for(int i=0;i<n-2;++i)cout<<s[0][0];
		cout<<" \n";
	}
	return 0;
}