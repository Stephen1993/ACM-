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

const int MAX=101;
int marry[MAX][MAX],link[MAX][MAX][2];//用砖的一头与另一头来匹配. 
int n,m,top;
bool mark[MAX][MAX];
int dir[][2]={1,0,-1,0,0,1,0,-1};

bool find(int x,int y){
	for(int i=0;i<4;++i){
		int a=x+dir[i][0];
		int b=y+dir[i][1];
		if(a>=0 && b>=0 && a<n && b<m && marry[x][y] != marry[a][b] && !mark[a][b]){
			mark[a][b]=true;
			if((link[a][b][0]+link[a][b][1]) == -2 || find(link[a][b][0],link[a][b][1])){
				link[a][b][0]=x;
				link[a][b][1]=y;
				return true;
			}
		}
	}
	return false;
}

bool hungarian_algorithm(){
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){   //奇偶性相同可以保证每个开始去匹配的点都是未被匹配的. 
			if((i&1) == (j&1)){//用奇偶性相同点去匹配它周围四个点(固定砖的一头,砖的另一头有四个方向可以放置) 
				memset(mark,false,sizeof mark);
				if(!find(i,j))return false;
			}
		}
	}
	return true;
}

int main(){
	while(cin>>n>>m){
		memset(link,-1,sizeof link);
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				cin>>marry[i][j];
			}
		}
		if(!hungarian_algorithm()){cout<<"-1\n";continue;}
		top=0;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				if(!((i&1) == (j&1))){//用奇偶性不同点来寻找与它匹配的点. 
					marry[i][j]=++top;
					marry[link[i][j][0]][link[i][j][1]]=top;
				}
			}
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<m-1;++j){
				cout<<marry[i][j]<<' ';
			}
			cout<<marry[i][m-1]<<endl;
		}
	}
	return 0;
}