#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=14;
int s[MAX];
int n;

void dfs(int *p,int num,int m){
	if(num == 7){
		for(int i=1;i<6;++i)cout<<p[i]<<' ';
		cout<<p[6]<<endl;
		return;
	}
	if(m>n)return;
	p[num]=s[m];
	dfs(p,num+1,m+1);
	dfs(p,num,m+1);
	return;
}

int main(){
	int num=1;
	while(cin>>n,n){
		for(int i=1;i<=n;++i){
			cin>>s[i];
		}
		if(num!=1)
		cout<<endl;
		int p[7];
		dfs(p,1,1);
		num++;
	}
	return 0;
}