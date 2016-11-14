#include<iostream>
using namespace std;
const int INF=-1;
const int MAX=202;
__int64 dis[MAX][MAX];
__int64 s[MAX];
__int64 L1,L2,L3,L4,C1,C2,C3,C4;
__int64 T,N,M,x,y;

__int64 cost(__int64 x){
	if(x<0)x=-x;
	if(x>L4)return INF;
	if(x>L3)return C4;
	if(x>L2)return C3;
	if(x>L1)return C2;
	if(x>0)return C1;
	return 0;
}

void floyed(){
	for(int i=1;i<=N;++i){
		for(int j=1;j<N;++j){
			for(int k=j+1;k<=N;++k){
				if(dis[j][i]!=INF&&dis[i][k]!=INF){
					if(dis[j][k]==INF||dis[j][k]>(dis[j][i]+dis[i][k]))
					   dis[j][k]=dis[k][j]=dis[j][i]+dis[i][k];
				}
			}
		}
	}
}

int main(){
	cin>>T;
	int num=1;
	while(T--){
		scanf("%I64d%I64d%I64d%I64d%I64d%I64d%I64d%I64d",&L1,&L2,&L3,&L4,&C1,&C2,&C3,&C4);
		scanf("%I64d%I64d",&N,&M);
		for(int i=1;i<=N;++i){
			scanf("%I64d",&s[i]);
		}
		memset(dis,-1,sizeof(dis));
		for(int i=1;i<N;++i){
			for(int j=i+1;j<=N;++j){
				dis[i][j]=dis[j][i]=cost(s[j]-s[i]);
			}
		}
		floyed();
		cout<<"Case "<<num++<<':'<<endl;
		for(int i=1;i<=M;++i){
			scanf("%I64d %I64d",&x,&y);
			if(dis[x][y]==INF){
				printf ("Station %I64d and station %I64d are not attainable.\n",x,y);
			}
			else{
				printf ("The minimum cost between station %I64d and station %I64d is %I64d.\n",x,y,dis[x][y]);
			}
		}
	}
	return 0;
}