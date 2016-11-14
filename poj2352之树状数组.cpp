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

const int MAX=15000+10;
const int N=32000+10;
int n;
int c[33333],num[MAX];

int lowbit(int x){
	return x&(-x);
}

void Update(int x,int y){
	while(x<=N){
		c[x]+=y;
		x+=lowbit(x);
	}
}

int Query(int x){
	int sum=0;
	while(x>0){
		sum+=c[x];
		x-=lowbit(x);
	}
	return sum;
}

int main(){
	int x,y;
	while(~scanf("%d",&n)){
		memset(c,0,sizeof c);
		memset(num,0,sizeof num);
		for(int i=0;i<n;++i){
			scanf("%d%d",&x,&y);
			++x,++y;
			++num[Query(x)];
			Update(x,1);
		}
		for(int i=0;i<n;++i)printf("%d\n",num[i]);
	}
	return 0;
}