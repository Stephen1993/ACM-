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

const int MAX=300;
int s[1001][MAX];

void calculate(){
	s[1][0]=1,s[1][1]=1;
	s[2][0]=1,s[2][1]=2;
	s[3][0]=1,s[3][1]=4;
	s[0][0]=1,s[0][1]=1;
	for(int i=4;i<=1000;++i){
		int len=max(max(s[i-1][0],s[i-2][0]),s[i-4][0]);
		for(int j=1;j<=len;++j){
			s[i][j]+=s[i-1][j]+s[i-2][j]+s[i-4][j];
			s[i][j+1]=s[i][j]/10;
			s[i][j]=s[i][j]%10;
		}
		while(s[i][++len]){
			s[i][len+1]=s[i][len]/10;
			s[i][len]=s[i][len]%10;
		}
		s[i][0]=len-1;
	}
	return;
}

int main(){
	int n;
	calculate();
	while(cin>>n){
		for(int i=s[n][0];i>=1;--i){
			cout<<s[n][i];
		}
		cout<<endl;
	}
	return 0;
}