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
#define INF -1
using namespace std;

const int MAX=202;
__int64 L1,L2,L3,L4,C1,C2,C3,C4;
__int64 n,m;
__int64 dist[MAX][MAX],point[MAX];//dist记录的是价钱,point记录的是某点的坐标.

__int64 cost(__int64 x){
	if(x<0)x=-x;
	if(x>L4)return INF;
	if(x>L3)return C4;
	if(x>L2)return C3;
	if(x>L1)return C2;
	if(x>0)return C1;
	return 0;
}

void floyd(){
	for(int k=1;k<=n;++k){
		for(int i=1;i<n;++i){
			if(dist[i][k]!=INF){
				for(int j=1+i;j<=n;++j){
					if(dist[k][j]!=INF&&(dist[i][j]==INF||dist[i][j]>(dist[i][k]+dist[k][j]))){
						dist[i][j]=dist[j][i]=dist[i][k]+dist[k][j];
					}
				}
			}
		}
	} 
}
 
int main(){
	int t,num=1;
	scanf("%d",&t);
	while(t--){
		memset(dist,-1,sizeof dist);
		scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&L1,&L2,&L3,&L4,&C1,&C2,&C3,&C4);
		scanf("%I64d%I64d",&n,&m);
		for(int i=1;i<=n;++i){
			scanf("%I64d",&point[i]);
		}
		for(int i=1;i<n;++i){
			for(int j=i+1;j<=n;++j){
				dist[i][j]=dist[j][i]=cost(point[j]-point[i]);
			}
		}
		floyd();
		__int64 start,end;
		cout<<"Case "<<num++<<":\n";
        for(int i=1;i<=m;++i){
        	scanf("%I64d %I64d",&start,&end);
        	if(dist[start][end]!=INF)
        	  printf("The minimum cost between station %I64d and station %I64d is %I64d.\n",start,end,dist[start][end]);
        	else
        	  printf("Station %I64d and station %I64d are not attainable.\n",start,end);
        }
	}
	return 0;
}