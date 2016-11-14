#include<iostream>
#include<queue>
using namespace std;
const int MAX=200;
int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
char map[MAX][MAX]={0};
int n;
int m;
bool ture=false;
typedef struct point
{
	int x;
	int y;
	int num;
    bool operator <(const point t)const
      {
            return num > t.num;
      }      

}point1;
point Angel;
void bfs(point Angel2)
{
    int k=0;
	priority_queue<point>enqueue;
	point outqueue,next;
	enqueue.push(Angel2);
	while(!enqueue.empty())
	{
       outqueue=enqueue.top();
       enqueue.pop();
       map[Angel.x][Angel.y]='#';
	   for(int i=0;i<4;++i)
	   {
		  next.x=outqueue.x+dir[i][0];
		  next.y=outqueue.y+dir[i][1];
		  next.num=outqueue.num+1;
		  if(map[next.x][next.y]=='r')
		  {
  			ture=true;
  			Angel.num=next.num;
  			return;
  		  }
		  if(map[next.x][next.y]=='#')
		  continue;
		  if(next.x<0||next.y<0||next.x>=n||next.y>=m)
		  continue;
		  if(map[next.x][next.y]=='x')
		  next.num++;
		  map[next.x][next.y]='#';
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
      {
		cin>>map[i];
		for(int j=0;j<m;++j)
		{
			if('a'==map[i][j])
			{
			Angel.x=i;
			Angel.y=j;
			}
		}
       }
		Angel.num=0;
		bfs(Angel);
		if(ture)cout<<Angel.num<<endl;
		else cout<<"Poor ANGEL has to stay in the prison all his life."<<endl;
  }
	return 0;
}
/*7 8
#.#####.
#.a#..r.
#..#x...
..#..#.#
#...##..
.#......
........
4 5
#.###
r.rrr
#.##.
xxaxx
5 6
#r#..r
xxxxxx
#.#.xx
xxxx##
###.xa
*/
