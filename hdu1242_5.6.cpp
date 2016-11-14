#include<iostream>
#include<queue>
using namespace std;
const int MAX=200;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
char map[MAX][MAX]={0};
int n;
int m;
bool ture=false;
typedef struct
{
	int x;
	int y;
	int num;
}point;
point Angel;
void bfs(point Angel)
{
	queue<point>enqueue;
	point outqueue,next;
	enqueue.push(Angel);
	while(!enqueue.empty())
	{
		outqueue=enqueue.front();
		enqueue.pop();
		for(int i=0;i<4;++i)
		{
			next.x=outqueue.x+dir[i][0];
			next.y=outqueue.y+dir[i][1];
			next.num=outqueue.num+1;
			if(map[next.x][next.y]=='r')
			{
				ture=true;
				Angel.num=next.num;
			}
			if(map[next.x][next.y]=='#')
				continue;
			if(next.x<0||next.y<0||next.x>=n||next.y>=m)
				continue;
			if(map[next.x][next.y]=='x')
				next.num++;
			enqueue.push(next);
		}
	}
	return;
}
int main()
{
	while(cin>>n>>m)
	{
		ture=false;
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j)
			{
				cin>>map[i][j];
				if('a'==map[i][j])
					Angel.x=i;
				Angel.y=j;
			}
			Angel.num=0;
			bfs(Angel);
			if(ture)cout<<Angel.num<<endl;
			else cout<<"Poor ANGEL has to stay in the prison all his life."<<endl;
	}
	return 0;
}