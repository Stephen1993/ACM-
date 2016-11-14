#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 999999999
using namespace std;

const int MAX=100001;
int x[MAX][2],y[MAX];

typedef struct node{
	int a,b,c,ID;
};
node s[MAX],p[MAX];

bool cmp1(node a,node b){
	return a.a>b.a;
}

bool cmp2(node a,node b){
	return a.b>b.b;
}

bool cmp3(node a,node b){
	return a.a*1.0/a.c>b.a*1.0/b.c;
}

bool cmp4(node a,node b){
	return a.b*1.0/a.c>b.b*1.0/b.c;
}

int main(){
	int n,m;
	while(cin>>n>>m){
		for(int i=0;i<n;++i)cin>>s[i].a>>s[i].b>>s[i].c,s[i].ID=i;
		for(int i=0;i<m;++i){
			cin>>y[i];
			p[i]=s[y[i]];
		}
		sort(p,p+m,cmp1);
		x[p[0].ID][0]=1,x[p[0].ID][1]=1;
		for(int i=1,k=1,j=2;i<m;++i,++j){
			if(p[i].a != p[i-1].a)k=j;
			x[p[i].ID][0]=1,x[p[i].ID][1]=k;
		}
		sort(p,p+m,cmp2);
		if(x[p[0].ID][1]>1)x[p[0].ID][0]=2,x[p[0].ID][1]=1;
		for(int i=1,k=1,j=2;i<m;++i,++j){
			if(p[i].b != p[i-1].b)k=j;
			if(x[p[i].ID][1]>k)x[p[i].ID][0]=2,x[p[i].ID][1]=k;
		}
		sort(p,p+m,cmp3);
		if(x[p[0].ID][1]>1)x[p[0].ID][0]=3,x[p[0].ID][1]=1;
		for(int i=1,k=1,j=2;i<m;++i,++j){
			if(p[i].a*1.0/p[i].c != p[i-1].a*1.0/p[i-1].c)k=j;
			if(x[p[i].ID][1]>k)x[p[i].ID][0]=3,x[p[i].ID][1]=k;
		}
		sort(p,p+m,cmp4);
		if(x[p[0].ID][1]>1)x[p[0].ID][0]=4,x[p[0].ID][1]=1;
		for(int i=1,k=1,j=2;i<m;++i,++j){
			if(p[i].b*1.0/p[i].c != p[i-1].b*1.0/p[i-1].c)k=j;
			if(x[p[i].ID][1]>k)x[p[i].ID][0]=4,x[p[i].ID][1]=k;
		}
		for(int i=0;i<m;++i){
			cout<<x[y[i]][1]<<':'<<x[y[i]][0]<<endl;
		}
		cout<<endl;
	}
	return 0;
}