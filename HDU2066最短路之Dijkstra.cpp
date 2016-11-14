#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<limits.h>
using namespace std;
#define INF 9999999
const int MAX=1111;
int t,d;
int road[MAX][MAX]={0},start[MAX],end[MAX];
int dijkstra(int s){
	int dis[MAX]={0};
	for(int i=1;i<=1000;++i){
		dis[i]=road[s][i];
	}
	bool biaoji[MAX]={false};
	biaoji[s]=true;
	for(int k=0;k<1000;++k){
		int u=s,t=INF;
		for(int j=1;j<=1000;++j){
			if(biaoji[j]!=true&&t>dis[j]){
				t=dis[j];
				u=j;
			}
		}
		if(t==INF)break;
		biaoji[u]=true;
		for(int i=1;i<=1000;++i){
			dis[i]=dis[i]<(dis[u]+road[u][i])?dis[i]:(dis[u]+road[u][i]);
		}
	}
	int temp=INF;
	for(int i=0;i<d;++i){
		temp=temp<dis[end[i]]?temp:dis[end[i]];
	}
	return temp;
}
int main(){
	int a,b,l,s;
	while(cin>>t>>s>>d){
		for(int i=1;i<1000;++i){
			for(int j=i+1;j<=1000;++j){
				road[i][j]=road[j][i]=INF;
			}
		}
		for(int i=0;i<t;++i){
			scanf("%d%d%d",&a,&b,&l);
			road[a][b]=road[b][a]=road[a][b]<l?road[a][b]:l;
		}
		for(int i=0;i<s;++i){
			cin>>start[i];
		}
		for(int i=0;i<d;++i){
			cin>>end[i];
		}
		int sum=INF;
		for(int i=0;i<s;++i){
			int m=dijkstra(start[i]);
			sum=sum<m?sum:m;
		}
		cout<<sum<<endl;
	}
	return 0;
}