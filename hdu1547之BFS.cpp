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
int n,m,sx,sy,s[MAX*MAX];
int dir0[6][2]={0,1,0,-1,1,0,-1,0,-1,-1,1,-1};//偶数行能走得方向(行下标从0开始)
int dir1[6][2]={0,1,0,-1,1,0,-1,0,-1,1,1,1};//奇数行能走得方向 

int BFS(bool flag,int sx,int sy){
	char ch=Map[sx][sy];
	Map[sx][sy]='E';
	int sum=0;
	queue<int>q;
	int oq,a,b;
	q.push(sx*m+sy);//将第x*n+y个点入队
	while(!q.empty()){
		oq=q.front();
		q.pop();
		if(flag)s[sum]=oq;//先记录点,如果sum<3则需要还原点 
		++sum;
		int x=oq/m,y=oq%m;
		for(int i=0;i<6;++i){
			if(x%2)a=x+dir1[i][0],b=y+dir1[i][1];
			else a=x+dir0[i][0],b=y+dir0[i][1];
			if(a<0 || b<0 || a>=n || (a%2 && b>=m-1) || b>=m)continue;
			if(Map[a][b] == 'E')continue;//表示该点为空
			if(flag && Map[a][b] != ch)continue;//查找周围连通且相同颜色的球 
			Map[a][b]='E';
			q.push(a*m+b);
		}
	}
	if(flag && sum<3){
		for(int i=0;i<sum;++i)Map[s[i]/m][s[i]%m]=ch;
	}
	return sum;
}

int main(){
	while(cin>>n>>m>>sx>>sy){
		--sx,--sy;
		for(int i=0;i<n;++i)cin>>Map[i];
		int ans=0,sum=0;//sum表示总的球数
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				if(Map[i][j]>='a' && Map[i][j]<='z')++sum;
			}
		}
		BFS(true,sx,sy);
		for(int i=0;i<m;++i){
			if(Map[0][i] != 'E')ans+=BFS(false,0,i);//查询与顶上连通的球 
		}
		cout<<sum-ans<<endl;
	}
	return 0;
}