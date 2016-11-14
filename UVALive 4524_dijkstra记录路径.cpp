#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<iomanip>
#define INF 100000000
using namespace std;
const int MAX=100;
int road[MAX][MAX];//记录从i到j的初始距离. 
bool mark[MAX];//标记作用.
int record_road[MAX];//记录路径.
int dist[MAX];//记录点i到开始点的距离. 
int n,m;
void dijkstra(int s,int t){
	for(int i=0;i<n;++i){
		mark[i]=false;
		dist[i]=road[s][i];
		record_road[i]=s;//初始时的路径为开始点(即开始点到i点的距离最短). 
	}
	dist[s]=0;
	record_road[s]=-1;
	mark[s]=true;
	while(1){
		int min_road=INF;
		int point=-1;
		for(int i=0;i<n;++i){
			if(!mark[i]&&min_road>dist[i]){
				min_road=dist[i];
				point=i;
			}
		}
		if(point==t)break;
		mark[point]=true;
		for(int i=0;i<n;++i){
			if(!mark[i]&&dist[i]>dist[point]+road[point][i]){
				dist[i]=dist[point]+road[point][i];
				record_road[i]=point;//源点s经过点point到点i的距离能更新更短则记录路径i是经过点point的. 
			}
		}
	}
	char out_road[MAX];
	int u=t;
	int k=0;
	while(u!=-1){
        out_road[k++]= u+'A';
        u= record_road[u];
    }
	for(int i=k-1;i>=0;--i) printf("%c%c", out_road[i], i==0 ? '\n' : ' ');
}
int main(){
	char a[3],b[3],start[3],end[3];
	int l;
	while(cin>>n>>m){
		for(int i=0;i<n;++i){
			for(int j=i+1;j<=n;++j){
				road[i][j]=road[j][i]=INF;//初始化所有的路线无限长. 
			}
		}
		for(int i=0;i<m;++i){
			scanf("%s%s%d",a,b,&l);
			road[*a-'A'][*b-'A']=road[*b-'A'][*a-'A']=l;
		}
		int num;
		cin>>num;
		for(int i=0;i<num;++i){
			scanf("%s%s",start,end);
			dijkstra(*start-'A',*end-'A');
		}
	}
	return 0;
} 