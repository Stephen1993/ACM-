#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=2000+10;
int father[MAX],rank[MAX],set[MAX];
bool mark;

void makeset(int num){
	for(int i=1;i<=num;++i){
		father[i]=set[i]=i;
		rank[i]=1;
	}
}

int findset(int v){
	if(v != father[v])father[v]=findset(father[v]);
	return father[v];
}

void Union(int x,int y){
	int a=findset(x);
	int b=findset(y);
	if(a == b)return;
	if(rank[a]>rank[b]){
		father[b]=a;
		rank[a]+=rank[b];
	}
	else{
		father[a]=b;
		rank[b]+=rank[a];
	}
}

int main(){
	int t,n,m,a,b,num=0;
	cin>>t;
	while(t--){
		cin>>n>>m;
		makeset(n);
		mark=true;
		for(int i=0;i<m;++i){
			scanf("%d%d",&a,&b);
			if(findset(a) == findset(b))mark=false;
			if(mark){
				if(set[a] == a)set[a]=b;
				else Union(set[a],b);
				if(set[b] == b)set[b]=a;
				else Union(set[b],a);
			}
		}
		cout<<"Scenario #"<<++num<<":\n";
		if(mark)cout<<"No suspicious bugs found!"<<endl<<endl;
		else cout<<"Suspicious bugs found!"<<endl<<endl;
	}
	return 0;
} 