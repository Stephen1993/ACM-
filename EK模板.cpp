#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=222;
template<typename T>bool up_min(T &a,const T &b){return a>b?a=b,1:0;}
int river[MAX][MAX],record_road[MAX],enqueue[MAX];
bool mark[MAX];
int n,m;

bool BFS(int s,int t){
	int point=-1;
	int head=0,size=0;
	memset(mark,false,sizeof mark);
	mark[s]=true;
	enqueue[size++]=s;
	while(head<size){
		point=enqueue[head++];
		for(int i=1;i<=m;++i){
			if(!mark[i]&&river[point][i]){
				record_road[i]=point;
				mark[i]=true;
				enqueue[size++]=i;
				if(i==t)return true; 
			}
		}
	}
	return false;
}

int EK(int s,int t){
	int all=0;
	while(BFS(s,t)){
		int flow=INF;
		for(int i=t;i!=s;i=record_road[i]){
			up_min(flow,river[record_road[i]][i]);
		}
		all+=flow;
		for(int i=t;i!=s;i=record_road[i]){
			river[record_road[i]][i]-=flow;
			river[i][record_road[i]]+=flow;
		}
	}
	return all;
}

int main(){
	int river_start,river_end,river_flow;
	while(cin>>n>>m){
		memset(river,0,sizeof river);
		for(int i=0;i<n;++i){
			cin>>river_start>>river_end>>river_flow;
			river[river_start][river_end]+=river_flow;
		}
		int sum=EK(1,m);
		cout<<sum<<endl; 
	}
	return 0;
}