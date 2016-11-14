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

const int MAX=30+10;
int s[MAX][MAX],node[MAX];
int n,m,ans,num[MAX];
bool mark[MAX];

void dfs(int u,int n,int sum){
	if(n == 0){ans=min(ans,sum);return;}
	for(int i=0;i<m;++i){
		if(mark[node[i]])continue;
		mark[node[i]]=true;
		dfs(node[i],n-num[node[i]],sum+s[u][node[i]]);
		mark[node[i]]=false;
	}
}

int main(){
	while(cin>>n,n){
		memset(mark,false,sizeof mark);
		memset(num,0,sizeof num);
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j)cin>>s[i][j];
		}
		cin>>m;
		ans=INF;
		for(int i=0;i<m;++i)cin>>node[i],++num[node[i]];
		for(int i=0;i<m;++i){
			mark[node[i]]=true;
			dfs(node[i],m-num[node[i]],s[0][node[i]]);
			mark[node[i]]=false;
		}
		cout<<ans<<endl;
	}
	return 0;
}