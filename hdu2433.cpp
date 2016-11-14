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

const int MAX=100+10;
int edgenum[MAX][MAX],s[3002][2];//edgenum表示边u-v的数量,s是输入的边 
bool edge[MAX][MAX],flag[MAX][MAX][MAX],mark[MAX];//flag标记起点为i的最短路包含u-v边
int n,m,sum[MAX],dist[MAX];//sum是预定义得到的以i为起始点的最短路和,dist是点i到起始点的距离 

void Init(){
	memset(edgenum,0,sizeof edgenum);
	memset(flag,false,sizeof flag);
	memset(edge,false,sizeof edge);
}

int spfa(int s,bool p){
	int ans=0,u;
	for(int i=1;i<=n;++i)dist[i]=INF,mark[i]=false;
	dist[s]=0;
	mark[s]=true;
	queue<int>enqueue;
	enqueue.push(s);
	while(!enqueue.empty()){
		u=enqueue.front();
		enqueue.pop();
		mark[u]=false;
		for(int v=1;v<=n;++v){
			if(edge[u][v] && dist[v]>dist[u]+1){//dist[v]>dist[u]+edge[u][v]
				dist[v]=dist[u]+1;
				if(!mark[v]){
					mark[v]=true;
					enqueue.push(v);
					if(p)flag[s][u][v]=flag[s][v][u]=true;
				}
			}
		}
	}
	for(int i=1;i<=n;++i){
		if(dist[i] == INF){ans=INF;break;}
		else ans+=dist[i];
	}
	return ans;
}

int main(){
	int u,v,ans,temp;
	while(cin>>n>>m){
		Init();
		for(int i=0;i<m;++i){
			cin>>u>>v;
			edge[u][v]=edge[v][u]=true;
			++edgenum[u][v];
			++edgenum[v][u];
			s[i][0]=u,s[i][1]=v;
		}
		ans=temp=0;
		for(int i=1;i<=n;++i){//预处理好以点i为起始点的最短路和 
			sum[i]=spfa(i,true);//第二个参数是判断spfa里要不要执行flag
			if(sum[i] == INF){ans=INF;break;}
			else ans+=sum[i];
		}
		for(int i=0;i<m;++i){
			u=s[i][0];
			v=s[i][1];
			int num=ans;
			if(ans == INF)cout<<"INF"<<endl;
			else if(edgenum[u][v]-1>0)cout<<ans<<endl;
			else{
				edge[u][v]=edge[v][u]=false;
				for(int j=1;j<=n;++j){
					if(flag[j][u][v]){
						temp=spfa(j,false);
						if(temp == INF)break;
						else num+=temp-sum[j];
					}
				}
				if(temp == INF)cout<<"INF"<<endl;
				else cout<<num<<endl;
				edge[u][v]=edge[v][u]=true;
			}
		}
	}
	return 0;
} 