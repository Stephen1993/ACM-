#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#include<vector>
#define INF 99999999
using namespace std;

const int MAX=10001;
short dfn[MAX],low[MAX],stack[MAX];
bool in[MAX];
int top,num,sum;
vector<short>edge[MAX];

void tarjan(int v){
	dfn[v]=low[v]=++num;
	in[v]=true;
	stack[top++]=v;
	int x;
	for(int i=0;i<edge[v].size();++i){
		x=edge[v][i];
		if(!dfn[x]){
			tarjan(x);
			low[v]=min(low[v],low[x]);
		}
		else if(in[x]){
			low[v]=min(low[v],dfn[x]);
		}
	}
	if(dfn[v]==low[v]){
		sum++;
		do{
			x=stack[--top];
			in[x]=false;
		}
		while(x!=v);
	}
}

int main(){
	int n,m,a,b;
	while(cin>>n>>m,n+m){
		for(int i=1;i<=n;++i)edge[i].clear(),in[i]=false,dfn[i]=0;
		num=sum=top=0;
		for(int i=0;i<m;++i){
			scanf("%d%d",&a,&b);
			edge[a].push_back(b);
		}
		for(int i=1;i<=n;++i){
			if(!dfn[i])
			   tarjan(i);
		}
		if(sum==1)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
/*
5 6
1 2
2 3
3 5
3 4
4 2
5 1
*/
