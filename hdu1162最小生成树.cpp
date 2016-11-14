#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#include<cmath>
#define INF 99999999
using namespace std;
const int MAX=5000;
typedef struct{
	float l;
	int x;
	int y;
}edge;
edge e[MAX];
float s[101][2],sum;
int father[101],rank[101];
bool cmp(edge a,edge b){
	if(a.l==b.l){
		if(a.x==b.x)return a.x<b.x;
		return a.y<b.y;
	}
	return a.l<b.l;
}
void makeset(int num){
	for(int i=0;i<num;++i){
		father[i]=i;
		rank[i]=1;
	}
}
int findset(int v){
	if(father[v]!=v){
		father[v]=findset(father[v]);
	}
	return father[v];
}
void Union(int x,int y,float L){
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
	sum+=L;
}
int main(){
	int n;
	while(cin>>n){
		sum=0;
		makeset(n);
		for(int i=0;i<n;++i){
			cin>>s[i][0]>>s[i][1];
		}
		int k=0;
		for(int i=0;i<n-1;++i){
			for(int j=i+1;j<n;++j){
				e[k].x=i;
				e[k].y=j;
				e[k++].l=sqrt((s[j][1]-s[i][1])*(s[j][1]-s[i][1])+(s[j][0]-s[i][0])*(s[j][0]-s[i][0]));
			}
		}
		sort(e,e+k,cmp);
		for(int i=0;i<k;++i){
			Union(e[i].x,e[i].y,e[i].l);
		}
		cout<<fixed<<setprecision(2)<<sum<<endl;
	}
	return 0;
}