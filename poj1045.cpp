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
const int MAX=5;
char city_map[MAX][MAX];
int n,max_blockhouses;
bool judge(int x,int y){
	if(city_map[x][y]!='.')return false;
	for(int i=x-1;i>=0;i--){
		if(city_map[i][y]=='X')break;
		if(city_map[i][y]=='@')return false;
	}
	for(int i=y-1;i>=0;i--){
		if(city_map[x][i]=='X')break;
		if(city_map[x][i]=='@')return false;
	}
	return true;
}
void dfs(int pos,int num){
	if(pos==n*n){
		max_blockhouses=max(max_blockhouses,num);
		return;
	}
	int x=pos/n;
	int y=pos%n;
	if(judge(x,y)){
		city_map[x][y]='@';
		dfs(pos+1,num+1);
		city_map[x][y]='.';
	}
	dfs(pos+1,num); 
}
int main(){
	while(cin>>n,n){
		for(int i=0;i<n;++i){
			cin>>city_map[i];
		}
		max_blockhouses=0;
		dfs(0,0);
		cout<<max_blockhouses<<endl;
	}
	return 0;
}