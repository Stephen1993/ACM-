#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=10+10;
int s[MAX][2],n,m,sum;
bool mark[MAX];

void dfs(int num,int m){
	if(m<=0){
		sum=min(sum,num);
		return;
	}
	for(int i=0;i<n;++i){
		if(mark[i])continue;
		mark[i]=true;
		if(m<=s[i][1])dfs(num+1,m-2*s[i][0]);
		else dfs(num+1,m-s[i][0]);
		mark[i]=false;
	}
}

int main(){
	while(cin>>n>>m){
		for(int i=0;i<n;++i)cin>>s[i][0]>>s[i][1];
		sum=INF;
		memset(mark,false,sizeof mark);
		dfs(0,m);
		if(sum == INF)cout<<"-1"<<endl;
		else cout<<sum<<endl;
	}
	return 0;
}