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
int road[MAX][MAX],dist[MAX];//road��ʾ��a����b�ľ���,dist��ʾ��㵽i�ľ��� 
bool mark[MAX];//���i���Ƿ������ 
vector<int>marry[MAX];//�洢ÿһ���ܵ��ĵ�,ʹ���ڽӾ�����Ч������. 
int n,m,s[MAX];
void spfa(int s){
	memset(mark,false,sizeof(bool)*(n+1));
	fill(dist,dist+(n+1),INF);//��ʼ����㵽���е�ľ��������. 
	dist[s]=0;//��㵽���ľ���0. 
	queue<int>enqueue;
	int outqueue;
	enqueue.push(s);//������.
	while(!enqueue.empty()){
		outqueue=enqueue.front();
		enqueue.pop();
		mark[outqueue]=false;
		for(int i=0;i<marry[outqueue].size();++i){//ʹ���ڽӾ���. 
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
	if(point==2)return 1;//�ҵ��յ�,����. 
	if(s[point])return s[point];//���ҹ��ĵ㲢�ҿ���,����·����.
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
				road[i][j]=road[j][i]=INF;//��ʼ��a��b�ľ��������. 
			}
		}
		for(int i=1;i<=n;++i)marry[i].clear();
		for(int i=0;i<m;++i){
			scanf("%d%d%d",&a,&b,&c);
			road[a][b]=road[b][a]=c;//a��b��b��a�ľ�����c.
			marry[a].push_back(b);
			marry[b].push_back(a); 
		}
		spfa(2);
		int sum=dfs(1);
		cout<<sum<<endl;
	}
	return 0;
} 