/*
����˼·��
1.�Լ����һ������Դ�㣬����㼯�����ӵ�����Դ���ϣ�Ȼ������볬��Դ��ļ��ϵ�·��������Ϊ0�������ͳ�Ϊһ��n+1����ĵ�Դ���·�㷨����������
2.����ͼ+�յ��Dijkstra��Ȼ���¼��Сֵ��
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
        	road[0][start]=0;//���ӳ���Դ��0�ҳ���Դ�㵽���ľ���Ϊ0. 
        }
        sum=dijkstra(0); 
        if(sum!=INF)
          cout<<sum<<endl;
        else cout<<"-1\n";
	}
	return 0;
}