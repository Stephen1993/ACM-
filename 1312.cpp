#include<iostream>
using namespace std;
char map[21][21];
int n,m; 
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
typedef struct 
{
	int x;
	int y;
	int num;
}point;
point start,next;
void dfs(point start1)
{
	start.num++;
	for(int i=0;i<4;i++)
	{ 
		next.x=start1.x+dir[i][0];
		next.y=start1.y+dir[i][1];
		if(next.x<0||next.y<0||next.x>=m||next.y>=n)
		continue;
		if(map[next.x][next.y]=='#')
		continue;
		map[next.x][next.y]='#';
		dfs(next);
	}
	return ;
}
int main()
{
	while(cin>>n>>m,n,m)
	{
		start.num=0;
		for(int i=0;i<m;++i)
		for(int j=0;j<n;++j)
		{
			cin>>map[i][j];
			if(map[i][j]=='@')
			{
				start.x=i;
				start.y=j;
				map[i][j]='#';
			}
		}
		dfs(start);
		cout<<start.num<<endl;
	}
	return 0;
}