#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<vector>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=10001;
short dfn[MAX],low[MAX],stack[MAX];
bool in[MAX];
vector<short>edge[MAX];
int n,m,num,sum,top;

void tarjan(int v){
	dfn[v]=low[v]=++num;
	stack[top++]=v;
	in[v]=true;
	int j=0;
	for(int i=0;i<edge[v].size();++i){
		j=edge[v][i];
		if(!dfn[j]){
			tarjan(j);
			low[v]=min(low[v],low[j]);
		}
		else if(in[j]){
			low[v]=min(low[v],dfn[j]);
		}
	}
	if(low[v]==dfn[j]){
		j=stack[--top];
	}
}

int main(){
	int a,b;
	while(cin>>n>>m){
		top=num=sum=0;
		for(int i=1;i<=n;++i)edge[i].clear();
		for(int i=0;i<m;++i){
			scanf("%d%d",&a,&b);
			edge[a].push_back(b);
		}
		for(int i=1;i<=n;++i)dfn[i]=0,in[i]=false;
		for(int i=1;i<=n;++i){
			if(!dfn[i]){
				tarjan(i);
			}
		}
		if(sum==1)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}