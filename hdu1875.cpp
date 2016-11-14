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

const int MAX=101;
double pos[MAX][2],sum;
int father[MAX],rank[MAX];
int n,m,k;

typedef struct{
	int x;
	int y;
	double l;
}node;
node s[MAX*MAX];

bool cmp(node a,node b){
	return a.l<b.l;
}

void makeset(int num){
	for(int i=0;i<n;++i){
		father[i]=i;
		rank[i]=1;
	}
}

int findset(int v){
	if(v != father[v])father[v]=findset(father[v]);
	return father[v];
}

void Union(int x,int y,double l){
	int a=findset(x);
	int b=findset(y);
	if(a == b)return;
	if(rank[a]>rank[b]){
		rank[a]+=rank[b];
		father[b]=a;
	}
	else{
		rank[b]+=rank[a];
		father[a]=b;
	}
	sum+=100*l;
	n--;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n;
		k=0;
		sum=0;
		for(int i=0;i<n;++i)cin>>pos[i][0]>>pos[i][1];
		for(int i=0;i<n-1;++i){
			for(int j=i+1;j<n;++j){
				s[k].x=i,s[k].y=j,s[k++].l=sqrt((pos[i][0]-pos[j][0])*(pos[i][0]-pos[j][0])+(pos[i][1]-pos[j][1])*(pos[i][1]-pos[j][1]));
			}
		}
		makeset(n);
		sort(s,s+k,cmp);
		for(int i=0;i<k;++i){
			if(s[i].l>=10.0000000 && s[i].l<=1000.0000000)Union(s[i].x,s[i].y,s[i].l);
		}
		if(n == 1){
			cout<<fixed<<setprecision(1)<<sum<<endl;
		}
		else cout<<"oh!"<<endl;
	}
	return 0;
}