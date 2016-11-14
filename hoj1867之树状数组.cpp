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

const int MAX=1000000+10;
int n,m,q;
int a[MAX],c[MAX];
bool prime[MAX*10];

void Prime(){
	prime[0]=prime[1]=true; 
	for(int i=2;i*2<=10000000;++i)prime[i*2]=true;
	for(int i=3;i*i<=10000000;i+=2){
		if(!prime[i]){
			for(int j=i*i;j<=10000000;j+=2*i)prime[j]=true;
		}
	}
}

int lowbit(int x){
	return x&(-x);
}

void Update(int x,int y){
	while(x<=n){
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
	Prime();
	int op,x,y,k,p,num=0;
	while(scanf("%d%d%d",&n,&q,&m),n+q+m){
		p=prime[m]?0:1;
		for(int i=1;i<=n;++i)a[i]=m;
		for(int i=1;i<=n;++i){
			k=lowbit(i);
			c[i]=k*p;
		}
		printf("CASE #%d:\n",++num);
		for(int i=0;i<q;++i){
			scanf("%d%d%d",&op,&x,&y);
			if(op == 0){
				a[x]+=y;
				if(!prime[a[x]] && prime[a[x]-y])Update(x,1);
				if(prime[a[x]] && !prime[a[x]-y])Update(x,-1);
			} 
			else printf("%d\n",Query(y)-Query(x-1));
		}
		printf("\n");
	}
	return 0;
}