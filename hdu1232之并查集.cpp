#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=1001;
int father[MAX],rank[MAX];
bool mark[MAX];
void makeset(int num){
	for(int i=1;i<=num;++i){
		father[i]=i;
		rank[i]=1;
	}
}
int findset(int v){
	if(v!=father[v]){
		father[v]=findset(father[v]);
	}
	return father[v];
}
void Union(int x,int y){
	int a=findset(x);
	int b=findset(y);
	if(a==b)return;
	if(rank[a]>rank[b]){
		father[b]=father[a];
		rank[a]+=rank[b];
	}
	else{
		father[a]=father[b];
		rank[b]+=rank[a];
	}
}
int main(){
	int n,m,a,b;
	while(cin>>n,n){
		makeset(n);
		cin>>m;
		for(int i=0;i<m;++i){
			cin>>a>>b;
			Union(a,b);
		}
		int num=0;
		for(int i=2;i<=n;++i){
			if(findset(1)!=findset(i)){
				num++;
				Union(1,i);
			}
		}
		cout<<num<<endl;
	}
	return 0;
}