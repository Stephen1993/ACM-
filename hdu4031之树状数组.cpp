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

const int MAX=20000+10;
int n,q,T;
int a[MAX],b[MAX],t[MAX],ans[MAX];
int c[MAX],now[MAX];

int lowbit(int x){
	return x&(-x);
}

void Update(int x,int d){
	while(x<=n){
		c[x]+=d;
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

void Init(int num){
	for(int i=0;i<=num;++i)c[i]=ans[i]=0,now[i]=1;
}

int main(){
	int tt,size,num=0,x;
	char op[10];
	scanf("%d",&tt);
	while(tt--){
		scanf("%d%d%d",&n,&q,&T);
		Init(n);
		size=1;
		t[0]=-INF;
		printf("Case %d:\n",++num);
		for(int i=1;i<=q;++i){
			scanf("%s",op);
			if(op[0] == 'A'){
				scanf("%d%d",&a[size],&b[size]);
				Update(a[size],1);
				Update(b[size]+1,-1);
				t[size]=size++;
			}else{
				scanf("%d",&x);
				while(now[x]<size){
					if(a[now[x]]<=x  && x<=b[now[x]]){
						now[x]+=T;
						++ans[x];
					}else ++now[x]; 
				}
				printf("%d\n",Query(x)-ans[x]);
			}
		}
	}
	return 0;
}