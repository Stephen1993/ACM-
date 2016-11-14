#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=200+10;
int n,size;
int head[MAX],temp[2];
bool flag[2];//标记是否是唯一 
map<string,int>mp;
string a,b;

struct Edge{
	int v,next;
	Edge(){}
	Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[MAX];

void Init(int num){
	for(int i=0;i<=num;++i)head[i]=-1;
	size=0;
	mp.clear();
}

void InsertEdge(int u,int v){
	edge[size]=Edge(v,head[u]);
	head[u]=size++;
}

void dfs(int u,int father){
	int dp[2]={0,0};//dp[0]表示当前点u不去的最大人数,dp[1]表示去的最大人数
	bool mark[2]={true,true};
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v;
		if(v == father)continue;
		dfs(v,u);
		dp[0]=dp[0]+max(temp[0],temp[1]);
		dp[1]=dp[1]+temp[0];
		if(temp[0]>temp[1]){if(!flag[0])mark[0]=flag[0];}
		else if(temp[0]<temp[1]){if(!flag[1])mark[0]=flag[1];}
		else mark[0]=false;
		if(!flag[0])mark[1]=flag[0];
	}
	temp[0]=dp[0];
	temp[1]=dp[1]+1;
	flag[0]=mark[0];
	flag[1]=mark[1];
	return;
}

int main(){
	while(~scanf("%d",&n),n){
		Init(n);
		int k=0;
		cin>>a;
		mp[a]=++k;
		InsertEdge(0,1);
		for(int i=1;i<n;++i){
			cin>>a>>b;
			if(!mp[b])mp[b]=++k;
			if(!mp[a])mp[a]=++k;
			InsertEdge(mp[b],mp[a]);
		}
		dfs(0,-1);
		printf("%d %s\n",temp[0],flag[0]?"Yes":"No");
	}
	return 0;
}