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

const int MAX=1024+10;
int n;
int c[MAX][MAX];

int lowbit(int x){
	return x&(-x);
}

void Update(int x,int y,int d){
	while(x<=n){
		int y1=y;
		while(y1<=n){
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
	int op,x,y,x2,y2,d;
	while(~scanf("%d%d",&op,&n)){
		memset(c,0,sizeof c);
		while(scanf("%d",&op),op != 3){
			if(op == 1){
				scanf("%d%d%d",&x,&y,&d);
				++x,++y;
				Update(x,y,d);
			}else{
				scanf("%d%d%d%d",&x,&y,&x2,&y2);
				++x,++y;
				++x2,++y2;
				printf("%d\n",Query(x2,y2)-Query(x2,y-1)-Query(x-1,y2)+Query(x-1,y-1));
			}
		}
	}
	return 0;
}