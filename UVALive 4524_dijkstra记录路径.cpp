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
int road[MAX][MAX];//��¼��i��j�ĳ�ʼ����. 
bool mark[MAX];//�������.
int record_road[MAX];//��¼·��.
int dist[MAX];//��¼��i����ʼ��ľ���. 
int n,m;
void dijkstra(int s,int t){
	for(int i=0;i<n;++i){
		mark[i]=false;
		dist[i]=road[s][i];
		record_road[i]=s;//��ʼʱ��·��Ϊ��ʼ��(����ʼ�㵽i��ľ������). 
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
				record_road[i]=point;//Դ��s������point����i�ľ����ܸ��¸������¼·��i�Ǿ�����point��. 
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
				road[i][j]=road[j][i]=INF;//��ʼ�����е�·�����޳�. 
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