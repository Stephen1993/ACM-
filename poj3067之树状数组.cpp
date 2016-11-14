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
int n,m,k;
int c[MAX];

struct Node{
	int x,y;
	bool operator<(const Node &a)const{
		if(x == a.x)return y<a.y;
		return x<a.x;
	}
}s[MAX*MAX];

int lowbit(int x){
	return x&(-x);
}

void Update(int x,int y){
	while(x<=m){
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
	int t,num=0;
	scanf("%d",&t);
	while(t--){
		memset(c,0,sizeof c);
		scanf("%d%d%d",&n,&m,&k);
		for(int i=0;i<k;++i){
			scanf("%d%d",&s[i].x,&s[i].y);
		}
		sort(s,s+k);
		LL sum=0;
		for(int i=0;i<k;++i){
			sum+=i-Query(s[i].y);
			Update(s[i].y,1);
		}
		printf("Test case %d: %lld\n",++num,sum);
	}
	return 0;
}