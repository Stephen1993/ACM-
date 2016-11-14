#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<iomanip>
#include<limits.h> 
using namespace std;
const int MAX=1111;
int father[MAX],rank[MAX];
int sum;
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
		father[b]=a;
		rank[a]+=rank[b];
	}
	else{
		father[a]=b;
		rank[b]+=rank[a];
	}
	sum--;
}
int main(){
	int n,m,t,a,b;
	cin>>t;
	while(t--){
		cin>>n>>m;
		sum=n;
		makeset(n);
		for(int i=0;i<m;++i){
			cin>>a>>b;
			Union(a,b);
		}
		cout<<sum<<endl;
	}
	return 0;
}