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
int m;
int road[MAX][MAX]={0};
int dijkstra(int s){
	bool biaoji[MAX]={false};
	int dist[MAX];
	for(int i=1;i<m;++i){
		dist[i]=road[s][i];
	}
	biaoji[s]=true;
	dist[s]=0;
	for(int i=0;i<m;++i){
		int point=s;
		int min_road=INF;
		for(int j=2;j<m;++j){
			if(!biaoji[j]&&min_road>dist[j]){
				point=j;
				min_road=dist[j];
			}
		}
		if(min_road==INF)break;
		biaoji[point]=true;
		for(int k=1;k<m;++k){
			dist[k]=min(dist[k],dist[point]+road[point][k]);
		}
	}
	return dist[2];
}
int main(){
	int n;
	map<string,int>bus;
	char start[31],end[31],first[31],second[31];
	int length_;
	while(scanf("%d",&n),n!=-1){
		bus.clear();
		for(int i=1;i<160;++i){
			for(int j=i+1;j<=160;++j){
				road[i][j]=road[j][i]=INF;
			}
		}
		scanf("%s%s",start,end);
		bool flag=false;
		if(!strcmp(start,end)){
			flag=true;
		}
		bus[start]=1;
		bus[end]=2;
		m=3;
		for(int i=0;i<n;++i){
			scanf("%s%s%d",first,second,&length_);
			if(!bus[first])bus[first]=m++;
			if(!bus[second])bus[second]=m++;
			road[bus[first]][bus[second]]=road[bus[second]][bus[first]]=min(length_,road[bus[first]][bus[second]]);
		}
		if(flag){
			cout<<"0\n";
			continue;
		}
		int sum=dijkstra(1);
		if(sum!=INF)cout<<sum<<endl;
		else cout<<"-1\n";
	}
	return 0;
}