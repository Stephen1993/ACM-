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
const int MAX=10001;
int length[100][100];
int s[101][101];
int dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
int m,n;
void dfs(int x,int y){
	for(int i=0;i<4;++i){
		int a=x+dir[i][0];
		int b=y+dir[i][1];
		if(!length[a][b]&&a>=0&&b>=0&&a<m&&b<n&&s[x][y]>s[a][b]){//满足条件且未搜索过得位置(记忆化搜索). 
			dfs(a,b);
		}
		if(a>=0&&b>=0&&a<m&&b<n&&s[x][y]>s[a][b])
		length[x][y]=max(length[x][y],length[a][b]+1);
	}
	return;
}
int main(){
	while(scanf("%d%d",&m,&n)!=EOF){
		int heigth=0;
		int l=-1;
		memset(length,0,sizeof length);
		for(int i=0;i<m;++i){
			for(int j=0;j<n;++j){
				scanf("%d",&s[i][j]);
			}
		}
		for(int i=0;i<m;++i){
			for(int j=0;j<n;++j){
				if(length[i][j]==0)
				   dfs(i,j);
				if(l<length[i][j]){
					l=length[i][j];
				}
			}
		}
		cout<<l+1<<endl;
	}
}