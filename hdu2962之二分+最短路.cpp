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

const int MAX=1000+10;
int dist[MAX],height[MAX][MAX],road[MAX][MAX];
int n,m,maxh,minl;
bool mark[MAX];

bool dijkstra(int s,int t,int h){
	for(int i=1;i<=n;++i){
		if(height[s][i]>=h)dist[i]=road[s][i];
		else dist[i]=INF;
		mark[i]=false;
	}
	dist[s]=INF,mark[s]=true;
	for(int k=1;k<=n;++k){
		int point=s;
		for(int i=1;i<=n;++i){
			if(dist[point]>dist[i] && !mark[i])point=i;
		}
		if(point == s)return false;
		if(point == t){minl=dist[t];maxh=h;return true;}
		mark[point]=true;
		for(int i=1;i<=n;++i){
			if(!mark[i] && dist[point]+road[point][i]<dist[i] && height[point][i]>=h){
				dist[i]=road[point][i]+dist[point];
			}
		}
	}
} 

void Init(int n){
	for(int i=1;i<=n;++i){ 
		for(int j=i+1;j<=n;++j){
			road[i][j]=road[j][i]=INF;
			height[i][j]=height[j][i]=-INF;
		}
	}
}

int main(){
	int a,b,l,h,left,right,mid,num=0;
	while(scanf("%d%d",&n,&m),n+m){
		Init(n);
		for(int i=1;i<=m;++i){
			scanf("%d%d%d%d",&a,&b,&h,&l);
			road[a][b]=l,height[a][b]=h;
			road[b][a]=l,height[b][a]=h;
			if(h == -1)height[a][b]=height[b][a]=INF;
		}
		scanf("%d%d%d",&a,&b,&h);
		left=0,right=h,maxh=-INF;
		while(left<=right){
			mid=left+right>>1;
			if(dijkstra(a,b,mid))left=mid+1;
			else right=mid-1;
		}
		if(h == -1)dijkstra(a,b,-1);
		if(num)cout<<endl;
		cout<<"Case "<<++num<<":\n";
		if(maxh == -INF)cout<<"cannot reach destination"<<endl;
		else printf("maximum height = %d\nlength of shortest route = %d\n",right,minl);
	}
	return 0;
}