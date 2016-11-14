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

const int MAX=21;
int w[MAX][MAX][MAX];

int dfs(int x,int y,int z){
	if(x<=20 && y<=20 && z<=20 && x>=0 && y>=0 &&z>=0 && w[x][y][z])return w[x][y][z];
	if(x<=0 || y<=0 || z<=0)return 1;
	else
	if(x>20 || y>20 || z>20){
		return dfs(20,20,20);
	}
	else
	if(x<y && y<z){
		w[x][y][z]=dfs(x,y,z-1)+dfs(x,y-1,z-1)-dfs(x,y-1,z);
	}
	else w[x][y][z]=dfs(x-1,y,z)+dfs(x-1,y-1,z)+dfs(x-1,y,z-1)-dfs(x-1,y-1,z-1);
	return w[x][y][z];
}

int main(){
	int a,b,c;
	while(cin>>a>>b>>c,a!=-1 || b!=-1 || c!=-1){
		printf("w(%d, %d, %d) = %d\n",a,b,c,dfs(a,b,c));
	}
	return 0;
}