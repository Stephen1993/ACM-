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
const int MAX=222;
int map[MAX][MAX],flow[MAX][MAX],p[MAX],a[MAX];
int n,m,u;
int EK(int s,int t){
	queue<int>Q;
	int all=0;
	memset(flow,0,sizeof flow); 
	while(1){
		memset(a,0,sizeof a);
		a[s]=INT_MAX;
		Q.push(s);
		while(!Q.empty()){
			u=Q.front();
			Q.pop();
			for(int i=1;i<=m;++i){
				if(!a[i]&&map[u][i]>flow[u][i]){
					Q.push(i);
					a[i]=min(a[u],map[u][i]-flow[u][i]);
					p[i]=u;
				}
			}
		}
		if(a[t]==0)break;
		for(u=t;u!=s;u=p[u]){
			flow[p[u]][u]+=a[t];
			flow[u][p[u]]-=a[t];
		}
		all+=a[t];
	}
	return all;
}
int main(){
	while(cin>>n>>m){
		memset(map,0,sizeof map);
		int a,b,l;
		for(int i=0;i<n;++i){
			scanf("%d%d%d",&a,&b,&l);
			map[a][b]+=l;
		}
		int sum=EK(1,m);
		cout<<sum<<endl;
	}
	return 0;
}