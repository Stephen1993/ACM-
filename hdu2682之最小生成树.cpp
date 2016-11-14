//http://acm.hdu.edu.cn/showproblem.php?pid=2682
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

const int MAX=600+10;
int father[MAX],rank[MAX],s[MAX],sum,num;
bool prime[2000009];

void Prime(){
	prime[0]=prime[1]=true;
	for(int i=2;i*2<=2000000;++i)prime[i*2]=true;
	for(int i=3;i*i<=2000000;i+=2){
		if(!prime[i]){
			for(int j=i*i;j<=2000000;j+=2*i){
				prime[j]=true;
			}
		}
	}
}

struct Edge{
	int u,v,w;
	Edge(){}
	Edge(int U,int V,int W):u(U),v(V),w(W){}
}edge[MAX*MAX];

bool cmp(Edge a,Edge b){
	return a.w<b.w;
}

void makeset(int num){
	for(int i=0;i<=num;++i){
		father[i]=i;
		rank[i]=1;
	}
}

int findset(int v){
	if(v != father[v])father[v]=findset(father[v]);
	return father[v];
}

void Union(int x,int y,int l){
	int a=findset(x);
	int b=findset(y);
	if(a == b)return;
	if(rank[a]<rank[b]){
		father[a]=b;
		rank[b]+=rank[a];
	}else{
		father[b]=a;
		rank[a]+=rank[b];
	}
	sum+=l;
	--num;
}

int main(){
	Prime();
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		makeset(n);
		int size=0;
		for(int i=0;i<n;++i){
			scanf("%d",&s[i]);
			for(int j=0;j<i;++j){
				if(!prime[s[j]] || !prime[s[i]] || !prime[s[i]+s[j]]){
					edge[size++]=Edge(i,j,min(min(s[i],s[j]),abs(s[i]-s[j])));
				}
			}
		}
		sum=0;
		num=n;
		sort(edge,edge+size,cmp);
		for(int i=0;i<size;++i)Union(edge[i].u,edge[i].v,edge[i].w);
		if(num == 1)cout<<sum<<endl;
		else cout<<"-1"<<endl;
	}
	return 0;
}