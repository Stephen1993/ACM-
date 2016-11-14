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
int n,q;
int c[MAX][MAX];

int lowbit(int x){
	return x&(-x);
}

void Update(int x,int y){
	while(x<=n){
		int y1=y;
		while(y1<=n){
			c[x][y1]+=1;
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
	int t,x1,y1,x2,y2;
	char op[2];
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&q);
		memset(c,0,sizeof c);
		for(int i=0;i<q;++i){
			scanf("%s",op);
			if(op[0] == 'C'){
				scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
				Update(x1,y1);
				Update(x1,y2+1);
				Update(x2+1,y1);
				Update(x2+1,y2+1);
			}else{
				scanf("%d%d",&x1,&y1);
				printf("%d\n",Query(x1,y1)%2);
			}
		}
		printf("\n");
	}
	return 0;
}