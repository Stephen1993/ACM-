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

const int MAX=10;
char Map[MAX][MAX];
int dir[8][2]={0,1,0,-1,1,0,-1,0,1,1,-1,-1,1,-1,-1,1};
int sum,ans;

void DFS(int x,int y,int i,int num){
	if(x<0 || y<0 || x>=8 || y>=8 || Map[x][y] == '*')return;
	if(Map[x][y] == 'L')++num;
	if(Map[x][y] == 'D'){ans+=num;return;}//表示i这个方向能翻转num个白棋 
	DFS(x+dir[i][0],y+dir[i][1],i,num);
}

int main(){
	int t,num=0;
	cin>>t;
	while(t--){
		sum=0;
		for(int i=0;i<8;++i)cin>>Map[i];
		for(int i=0;i<8;++i){
			for(int j=0;j<8;++j){
				if(Map[i][j] == '*'){
					ans=0;
					for(int k=0;k<8;++k){//对每个点8个方向进行搜索 
						DFS(i+dir[k][0],j+dir[k][1],k,0);
					}
					sum=sum>ans?sum:ans;
				}
			}
		}
		cout<<"Case "<<++num<<": "<<sum<<endl;
	}
	return 0;
}