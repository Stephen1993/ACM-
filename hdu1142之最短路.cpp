#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=1001;
int road[MAX][MAX],dist[MAX];//road表示点a到点b的距离,dist表示起点到i的距离 
bool mark[MAX];//标记i点是否已入队 
vector<int>marry[MAX];//存储每一点能到的点,使用邻接矩阵是效率增大. 
int n,m,s[MAX];
void spfa(int s){
	memset(mark,false,sizeof(bool)*(n+1));
	fill(dist,dist+(n+1),INF);//初始化起点到所有点的距离无穷大. 
	dist[s]=0;//起点到起点的距离0. 
	queue<int>enqueue;
	int outqueue;
	enqueue.push(s);//起点入队.
	while(!enqueue.empty()){
		outqueue=enqueue.front();
		enqueue.pop();
		mark[outqueue]=false;
		for(int i=0;i<marry[outqueue].size();++i){//使用邻接矩阵. 
			if(dist[marry[outqueue][i]]>road[outqueue][marry[outqueue][i]]+dist[outqueue]){
				dist[marry[outqueue][i]]=road[outqueue][marry[outqueue][i]]+dist[outqueue];
				if(!mark[outqueue]){
					enqueue.push(marry[outqueue][i]);
					mark[marry[outqueue][i]]=true;
				}
			}
		}
	} 
}
int dfs(int point){
	if(point==2)return 1;//找到终点,返回. 
	if(s[point])return s[point];//已找过的点并且可行,返回路径数.
	for(int i=0;i<marry[point].size();++i){
		if(dist[point]>dist[marry[point][i]]){
			s[point]+=dfs(marry[point][i]);
		}
	} 
	return s[point];
}
main(){
	int a,b,c;
	while(cin>>n,n){
		cin>>m;
		memset(s,0,sizeof(int)*(n+1));
		for(int i=1;i<n;++i){
			for(int j=i+i;j<=n;++j){
				road[i][j]=road[j][i]=INF;//初始化a到b的距离无穷大. 
			}
		}
		for(int i=1;i<=n;++i)marry[i].clear();
		for(int i=0;i<m;++i){
			scanf("%d%d%d",&a,&b,&c);
			road[a][b]=road[b][a]=c;//a到b和b到a的距离是c.
			marry[a].push_back(b);
			marry[b].push_back(a); 
		}
		spfa(2);
		int sum=dfs(1);
		cout<<sum<<endl;
	}
	return 0;
} 