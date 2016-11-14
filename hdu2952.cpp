#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=100+10;
char Map[MAX][MAX];
int n,m;
int dir[4][2]={0,1,0,-1,1,0,-1,0};

void BFS(int a,int b){
	queue<int>q;
	int oq,x,y;
	q.push(a*m+b);
	while(!q.empty()){
		oq=q.front();
		q.pop();
		for(int i=0;i<4;++i){
			x=oq/m+dir[i][0];
			y=oq%m+dir[i][1];
			if(x<0 || y<0 || x>=n || y>=m)continue;
			if(Map[x][y] != '#')continue;
			Map[x][y]='.';
			q.push(x*m+y);
		}
	}
}

int main(){
	int t,sum;
	cin>>t;
	while(t--){
		sum=0;
		cin>>n>>m;
		for(int i=0;i<n;++i)cin>>Map[i];
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				if(Map[i][j] == '#'){
					++sum;
					BFS(i,j);
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}