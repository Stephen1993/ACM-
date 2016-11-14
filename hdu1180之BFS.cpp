#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=22;
int dir[4][2]={1,0,-1,0,0,1,0,-1};
typedef struct noto{
	int x;
	int y;
	int time;
	bool operator<(const noto a)const{
		return time>a.time;
	}
};
noto start;
int n,m,x1,y1,x2,y2;
char s[MAX][MAX];
bool mark[MAX][MAX];
int bfs(){
	memset(mark,false,sizeof mark);
	mark[x1][y1]=true;
	priority_queue<noto>enqueue;
	noto outqueue,next;
	start.x=x1,start.y=y1,start.time=0;
	enqueue.push(start);
	while(!enqueue.empty()){
		outqueue=enqueue.top();
		enqueue.pop();
		for(int i=0;i<4;++i){
			next.x=outqueue.x+dir[i][0];
			next.y=outqueue.y+dir[i][1];
			next.time=outqueue.time+1;
			if(next.x<0||next.y<0||next.x>=n||next.y>=m||mark[next.x][next.y]||s[next.x][next.y]=='*')continue;
			if(s[next.x][next.y]=='-'||s[next.x][next.y]=='|'){
			    if((outqueue.time&1)){
    				if(s[next.x][next.y]=='|'&&(i==2||i==3)){
				    }
				    else if(s[next.x][next.y]=='-'&&(i==0||i==1)){
    				}
    				else{
				    	next.time++;
   			 	    }
    			}
    			else{
			    	if(s[next.x][next.y]=='-'&&(i==2||i==3)){
				    }
				    else if(s[next.x][next.y]=='|'&&(i==0||i==1)){
    				}
    				else{
				    	next.time++;
				    }
			    }
			    next.x+=dir[i][0];
			    next.y+=dir[i][1];
			}
			if(s[next.x][next.y]=='T')return next.time;
			mark[next.x][next.y]=true;
			enqueue.push(next);
		}
	}
}
int main(){
	while(cin>>n>>m){
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				cin>>s[i][j];
				if(s[i][j]=='S')x1=i,y1=j;
			}
		}
		int sum=bfs();
		cout<<sum<<endl;
	}
	return 0;
}