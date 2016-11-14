#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iomanip>
#include<queue>
#include<algorithm>
#include<limits.h>
using namespace std;
#define INF 999999
const int MAX=1111;
int road[MAX][MAX]={0};
bool start_biaoji[MAX],end_biaoji[MAX];
int t,s,d,max_city;
int floyd(){
	int temp=INF;
	for(int k=1;k<=max_city	;++k){
		for(int i=1;i<=max_city	;++i){
			if(road[i][k]!=INF)
			for(int j=1;j<=max_city	;++j){
				road[i][j]=road[i][j]<(road[i][k]+road[k][j])?road[i][j]:(road[i][k]+road[k][j]);
				if(start_biaoji[i]&&end_biaoji[j]){
					temp=temp<road[i][j]?temp:road[i][j];
				}
			}
		}
	}
	return temp;
}
int main(){
	while(scanf("%d%d%d",&t,&s,&d)!=EOF){
		int a,b,l;
		max_city=0;
		for(int i=1;i<1000;++i){
			for(int j=i+1;j<=1000;++j){
				road[i][j]=road[j][i]=INF;
			}
		}
		for(int i=0;i<t;++i){
			scanf("%d%d%d",&a,&b,&l);
			max_city=(a>b ? a:b) > max_city ? (a>b?a:b) : max_city;
			if(road[a][b]>l){
				road[a][b]=road[b][a]=l;
			}
		}
		memset(start_biaoji,false,sizeof start_biaoji);
		memset(end_biaoji,false,sizeof end_biaoji);
		for(int i=0;i<s;++i){
			scanf("%d",&a);
			start_biaoji[a]=true;
		}
		for(int i=0;i<d;++i){
			scanf("%d",&a);
			end_biaoji[a]=true;
		}
		int min_road=floyd();
		printf("%d\n",min_road);
	}
	return 0;
} 