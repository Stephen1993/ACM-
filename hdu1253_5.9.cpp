#include<iostream>
#include<queue>
using namespace std;
typedef struct
{
	int x;
	int y;
	int z;
	int time;
}point;
int n,A,B,C,T;
point start,end_;
bool ture=false;
bool map[50][50][50];
int dir[6][3]={{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}}; 
void bfs(point start1)
{
  queue<point>enqueue;
  point outqueue,next;
  enqueue.push(start1);
  map[0][0][0]=1;
  while(!enqueue.empty())
  {
  	outqueue=enqueue.front();
  	enqueue.pop();
  	for(int i=0;i<6;i++)
  	{
	  	next.x=outqueue.x+dir[i][0];
	  	next.y=outqueue.y+dir[i][1];
	  	next.z=outqueue.z+dir[i][2];
	  	next.time=outqueue.time+1;
	  	if(next.x<0||next.y<0||next.z<0||next.x>=A||next.y>=B||next.z>=C||next.time>T||map[next.x][next.y][next.z]==1)
	  	continue;
	  	if(next.x==A-1&&next.y==B-1&&next.z==C-1)
	  	{
	  		ture=true;
	  		start.time=next.time;
	  		return ;
	  	}
		map[next.x][next.y][next.z]=1;
		enqueue.push(next);
    }
  }
}
int main()
{
	cin>>n;
	while(n--)
	{
		ture=false;
		cin>>A>>B>>C>>T;
		for(int i=0;i<A;i++)
		for(int j=0;j<B;j++)
		for(int k=0;k<C;k++)
		scanf("%d",&map[i][j][k]);
		//cin>>map[i][j][k];
		if(A-1==0&&B-1==0&&C-1==0)
		{
		cout<<"0"<<endl;
		continue;
		}
		end_.x=A-1;
		end_.y=B-1;
		end_.z=C-1;
		start.x=start.y=start.z=start.time=0;
		bfs(start);
		if(ture)cout<<start.time<<endl;
		else cout<<"-1"<<endl;
	}
	return 0;
} 