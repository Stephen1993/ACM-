#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<cmath>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=10000+10;
/*father[i]表示i节点的父亲,rank[i]i所在集合的元素
sum转换的次数
*/
int father[MAX],rank[MAX],sum[MAX];

void makeset(int num){
	for(int i=1;i<=num;++i){
		father[i]=i;
		rank[i]=1;
		sum[i]=0;
	}
} 

int findset(int v){
	if(v == father[v])return father[v];
	int temp=findset(father[v]);
	sum[v]+=sum[father[v]];
	father[v]=temp;//这里压缩路径是关键,由于压缩路径,节点增加每次增加的转移数量只可能是1
	return father[v];
}

void Union(int x,int y){
	int a=findset(x);
	int b=findset(y);
	if(a == b)return;
	father[a]=b;
	sum[a]=1;
	rank[b]+=rank[a];
}

int main(){
	int t,n,m,a,b,num=0;
	char s;
	cin>>t;
	while(t--){
		scanf("%d%d",&n,&m);
		printf("Case %d:\n",++num);
		makeset(n);
		for(int i=0;i<m;++i){
			getchar();scanf("%c",&s);
			if(s == 'T'){
				scanf("%d%d",&a,&b);
				Union(a,b);
			}
			else{
				scanf("%d",&a);
				int x=findset(a);
				printf("%d %d %d\n",x,rank[x],sum[a]);
			}
		}
	}
	return 0;
}