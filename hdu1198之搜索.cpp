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
const int MAX=51;
int n,m;
char f[MAX][MAX];
bool mark[MAX][MAX];
bool s[11][4]={{1,1,0,0},{1,0,1,0},{0,1,0,1},{0,0,1,1},{1,0,0,1},{0,1,1,0},  
{1,1,1,0},{1,1,0,1},{0,1,1,1},{1,0,1,1},{1,1,1,1}};//上左右下 
int dir[4][2]={-1,0,0,-1,0,1,1,0};//上左右下 
void dfs(int x,int y){
	mark[x][y]=true;
	for(int i=0;i<4;++i){
		int a=x+dir[i][0];
		int b=y+dir[i][1];
		if(!mark[a][b]&&a>=0&&b>=0&&a<m&&b<n&&s[f[x][y]-'A'][i]&&s[f[a][b]-'A'][3-i]){
			dfs(a,b);
		}
	}
	return;
}
int main(){
	while(cin>>m>>n,n>=0&&m>=0){
		for(int i=0;i<m;++i){
			cin>>f[i];
		}
		int sum=0;
		memset(mark,false,sizeof mark);
		for(int i=0;i<m;++i){
			for(int j=0;j<n;++j){
				if(!mark[i][j]){
					sum++;
					dfs(i,j);
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}