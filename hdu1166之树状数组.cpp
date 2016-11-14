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

const int MAX=50000+10;
int n;
int sum[MAX],c[MAX];

int lowbit(int x){//º∆À„2^k 
	return x&(-x);
}

void Update(int x,int y){
	while(x<=n){
		c[x]+=y;
		x=x+lowbit(x);
	}
}

int Query(int x){
	int sum=0;
	while(x>0){
		sum+=c[x];
		x=x-lowbit(x);
	}
	return sum;
}

int main(){
	int t,x,y,k,num=0;
	char a[10];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)scanf("%d",sum+i),sum[i]+=sum[i-1];
		for(int i=1;i<=n;++i){
			k=lowbit(i);
			c[i]=sum[i]-sum[i-k];
		}
		printf("Case %d:\n",++num);
		while(scanf("%s",a),a[0] != 'E'){
			cin>>x>>y;
			if(a[0] == 'A')Update(x,y);
			else if(a[0] == 'S')Update(x,-y);
			else printf("%d\n",Query(y)-Query(x-1));//cout<<Query(y)-Query(x-1)<<endl; 
		}
	}
	return 0;
}