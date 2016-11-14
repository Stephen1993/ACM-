#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <sstream>
#include <cmath>
#include <climits>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=200+10;
int n,m,size,val[MAX],pre[MAX];
int dp[MAX],temp[MAX],head[MAX];
char s[2222],name[110];
map<string,int>Map;

struct Edge{
	int v,next;
	Edge(){}
	Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[MAX];

void Init(int num){
	for(int i=0;i<=num;++i)head[i]=-1,pre[i]=0;
	size=0;
}

void InsertEdge(int u,int v){
	edge[size]=Edge(v,head[u]);
	head[u]=size++;
}

int dfs(int u,int Id){
	int last=0,now=0;
	dp[Id]=0;
	for(int i=head[u];i != -1;i=edge[i].next){
		int v=edge[i].v;
		now=dfs(v,Id+last+1)+1;
		for(int j=last+1;j<=last+now;++j)dp[Id+j]=INF;
		for(int j=last;j>=0;--j){
			for(int k=1;k<now;++k){
				dp[Id+j+k]=min(dp[Id+j+k],dp[Id+j]+temp[k]);
			}
			dp[Id+j+now]=min(dp[Id+j+now],dp[Id+j]+val[v]);
		}
		last+=now;
	}
	for(int i=1;i<=last;++i)temp[i]=dp[Id+i];
	return last;
}

int main(){
	int u,v;
	stringstream Cin;
	while(gets(s)){
		if(s[0] == '#')break;
		Map.clear();
		sscanf(s,"%d%d",&n,&m);
		Init(n);
		int k=0;
		for(int i=1;i<=n;++i){
			gets(s);
			Cin.clear();
			Cin.str(s);
			Cin>>name;
			u=Map[name];
			if(u == 0)Map[name]=++k,u=k;
			Cin>>val[u];
			while(Cin>>name){
				v=Map[name];
				if(v == 0)Map[name]=++k,v=k;
				InsertEdge(u,v);
				pre[v]=u;
			}
		}
		for(int i=1;i<=n;++i)if(!pre[i])InsertEdge(0,i);
		dfs(0,0);
		int sum=INF;
		for(int i=m;i<=n;++i)if(sum>temp[i])sum=temp[i];
		printf("%d\n",sum);
	}
	return 0;
}