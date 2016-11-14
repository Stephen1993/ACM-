#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=1000+10;
int c[MAX][MAX];
bool mark[MAX][MAX];

int lowbit(int x){
	return x&(-x);
}

void Update(int x,int y,int d){
	while(x<MAX){
		int y1=y;
		while(y1<MAX){
			c[x][y1]+=d;
			y1+=lowbit(y1);
		}
		x+=lowbit(x);
	}
}

int Query(int x,int y){
	int sum=0;
	while(x>0){
		int y1=y;
		while(y1>0){
			sum+=c[x][y1];
			y1-=lowbit(y1);
		}
		x-=lowbit(x);
	}
	return sum;
}

int main(){
	int q,x1,y1,x2,y2;
	char op[3];
	while(~scanf("%d",&q)){
		memset(c,0,sizeof c);
		memset(mark,false,sizeof mark);
		for(int i=1;i<=q;++i){
			scanf("%s",op);
			if(op[0] == 'B'){
				scanf("%d%d",&x1,&y1);
				//cout<<x1<<' '<<y1<<"hello"<<endl;
				++x1,++y1;
				if(mark[x1][y1])continue;
				Update(x1,y1,1);
				mark[x1][y1]=true;
			}else if(op[0] == 'D'){
				scanf("%d%d",&x1,&y1);
				//cout<<x1<<' '<<y1<<"hello"<<endl;
				++x1,++y1;
				if(!mark[x1][y1])continue;
				Update(x1,y1,-1);
				mark[x1][y1]=false;
			}else{
				scanf("%d%d%d%d",&x1,&x2,&y1,&y2);	
				++x1,++y1;
				++x2,++y2;
				if(x1>x2)swap(x1,x2);
				if(y1>y2)swap(y1,y2);
				//cout<<x1<<' '<<y1<<"hello"<<x2<<' '<<y2<<endl;
				printf("%d\n",Query(x2,y2)-Query(x2,y1-1)-Query(x1-1,y2)+Query(x1-1,y1-1));
			}
		}
	}
	return 0;
}