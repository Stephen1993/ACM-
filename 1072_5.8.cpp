#include<iostream>
#include<queue>
using namespace std;
int n,m;
char map[9][9];
int time1[11][11];
bool ture=false;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
typedef struct
{
	int x;
	int y;
	int z_time;
	int s_time;
}point;
point start;
void bfs(point start1)
{
	queue<point>enqueue;
	point outqueue,next;
	enqueue.push(start1);
	map[start1.x][start1.y]='0';
	while(!enqueue.empty())
	{
		outqueue=enqueue.front();
		enqueue.pop();
		for(int i=0;i<4;i++)
		{
			next.x=outqueue.x+dir[i][0];
			next.y=outqueue.y+dir[i][1];
			next.s_time=outqueue.s_time-1;
			next.z_time=outqueue.z_time+1;
			if(next.x<0||next.y<0||next.x>=n||next.y>=m||next.s_time<=0)
				continue;
			if(map[next.x][next.y]=='0')
				continue;
			if(map[next.x][next.y]=='3')
			{
				ture=true;
				start.z_time=next.z_time;
				return;
			}
			if(map[next.x][next.y]=='4')
			{
				next.s_time=6;
				map[next.x][next.y]='0';
			}
			if(time1[next.x][next.y]<next.s_time)
			{
				enqueue.push(next); 
				time1[next.x][next.y]=next.s_time;
			}
		}
	}
	return;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ture=false;
		cin>>n>>m;
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				cin>>map[i][j];
				if(map[i][j]=='2')
				{
					start.x=i;
					start.y=j;
				}
			}
			start.z_time=0;
			start.s_time=6;
			memset(time1,0,sizeof(time1));
			bfs(start);
			if(ture)cout<<start.z_time<<endl;
			else cout<<"-1"<<endl;
	}
	return 0;
}