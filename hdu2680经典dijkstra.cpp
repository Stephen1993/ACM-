/*
解题思路：
1.自己多加一个超级源点，把起点集合连接到超级源点上，然后将起点与超级源点的集合的路径长度设为0，这样就称为一个n+1个点的单源最短路算法。。。。。
2.反向图+终点的Dijkstra，然后记录最小值。
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<iomanip>
#include<queue>
#include<map>
#define INF 999999
using namespace std;
const int MAX=1111;
int n,m,s,start;
int road[MAX][MAX]={0};
int dijkstra(int begin_){
	bool biaoji[MAX];
	int dist[MAX];
	for(int i=0;i<=n;++i){
		dist[i]=road[begin_][i];
		biaoji[i]=false;
	}
	dist[begin_]=0;
	biaoji[begin_]=true;
	for(int i=0;i<n;++i){
		int point=begin_;
		int min_road=INF;
		for(int j=0;j<=n;++j){
			if(!biaoji[j]&&min_road>dist[j]){
				point=j;
				min_road=dist[j];
			}
		}
		if(min_road==INF)break;
		biaoji[point]=true;
		for(int k=0;k<=n;++k){
			dist[k]=min(dist[k],dist[point]+road[point][k]);
		}
	}
	return dist[s];
}
int main(){
	int a,b,l;
	while(scanf("%d%d%d",&n,&m,&s)!=EOF){
		for(int i=0;i<n;++i){
			for(int j=i+1;j<=n;++j){
				road[i][j]=road[j][i]=INF;
			}
		}
		for(int i=0;i<m;++i){
			scanf("%d%d%d",&a,&b,&l);
			road[a][b]=min(road[a][b],l);
		}
		int w,sum=INF; 
		scanf("%d",&w);
        for(int i=0;i<w;++i){
        	scanf("%d",&start);
        	road[0][start]=0;//增加超级源点0且超级源点到起点的距离为0. 
        }
        sum=dijkstra(0); 
        if(sum!=INF)
          cout<<sum<<endl;
        else cout<<"-1\n";
	}
	return 0;
}