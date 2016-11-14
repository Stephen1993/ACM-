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

const int MAX=5000+10;
string Map[MAX];
int n,m,v,size,s[MAX][2];//s¼ÇÂ¼pµÄÎ»ÖÃ
int dir[4][2]={0,1,0,-1,1,0,-1,0};
bool mark[MAX];

struct Node{
	int x,y,t;
	Node(){}
	Node(int X,int Y,int T):x(X),y(Y),t(T){}
}start;

void CalculateP(){
	size=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(Map[i][j] == 'P'){
				s[size][0]=i;
				s[size][1]=j;
				++size;
			}else if(Map[i][j] == 'Y'){
				start=Node(i,j,0);
			}
		}
	}
}

int BFS(){
	memset(mark,false,sizeof mark);
	 queue<Node>q;
	 Node oq,next;
	 q.push(start);
	 mark[start.x*m+start.y]=true;
	 while(!q.empty()){
 		oq=q.front();
 		q.pop();
 		for(int i=0;i<4;++i){
		 	next=Node(oq.x+dir[i][0],oq.y+dir[i][1],oq.t);;
		 	if(next.x<0 || next.y<0 || next.x>=n || next.y>=m)continue;
		 	if(mark[next.x*m+next.y] || Map[next.x][next.y] == '#')continue;
		 	mark[next.x*m+next.y]=true;
		 	if(Map[next.x][next.y] == 'C')return next.t;
		 	if(Map[next.x][next.y] == 'P'){
		 		int len=q.size();
	 			for(int j=0;j<size;++j){
			 		mark[s[j][0]*m+s[j][1]]=true;
			 		q.push(Node(s[j][0],s[j][1],oq.t));
			 	}
			 	while(len--)next=q.front(),q.pop(),q.push(next);
	 		}else{
		 		next.t+=v;
		 		q.push(next);
		 	}
		 }
 	}
 	return -1;
}

int main(){
	while(cin>>n>>m>>v){
		for(int i=0;i<n;++i)cin>>Map[i];
		CalculateP();
		int temp=BFS();
		if(temp<0)cout<<"Damn teoy!"<<endl;
		else cout<<temp<<endl;
	}
	return 0;
}
