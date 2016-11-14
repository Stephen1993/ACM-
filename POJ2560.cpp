#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#include<cmath> 
#define INF 99999999
using namespace std;

const int MAX=111;
double s[MAX][2],sum;
int father[MAX],rank[MAX];

typedef struct{
	int x;
	int y;
	double l;
}edge;
edge e[10000];

bool cmp(edge a,edge b){
	if(a.l==b.l){
		if(a.x==b.x){
			return a.y<b.y;
		}
		return a.x<b.y;
	}
	return a.l<b.l;
}

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

void Union(int x,int y,double l){
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
	sum+=l;
	return;
}

int main(){
	int n;
	while(cin>>n){
		int k=0;
		makeset(n);
		for(int i=1;i<=n;++i){
			cin>>s[i][0]>>s[i][1];
			for(int j=1;j<i;++j){
				e[k].x=i;
				e[k].y=j;
				e[k++].l=sqrt( ( s[i][0]-s[j][0] )*( s[i][0]-s[j][0] )+( s[i][1]-s[j][1] )*( s[i][1]-s[j][1] ) );
			}
		}
		sort(e,e+k,cmp);
		sum=0;
		for(int i=0;i<k;++i){
			Union(e[i].x,e[i].y,e[i].l);
		} 
		cout<<fixed<<setprecision(2)<<sum<<endl;
	}
	return 0;
}