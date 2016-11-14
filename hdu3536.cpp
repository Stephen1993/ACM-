#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;
const int MAX=100005;
int father[MAX],rank[MAX],s[MAX];
char flag[MAX];
int sum,num;
void makeset(int m){
	for(int i=0;i<m;++i){
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
	if(a==b){
		return;
	}
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
	int n,k,x,y,i;
	while(scanf("%d%d",&n,&k)&&!(n==0&&k==0)){
		makeset(n);
	    sum=n;
        num=0;
		memset(flag,0,sizeof(flag));
		memset(s,0,sizeof(s));
		for(i=0;i<k;++i){
			scanf("%d%d",&x,&y);
			s[x]++;
			s[y]++;
			Union(x,y);
		}
		for(i=0;i<n;++i){
			if(s[i]!=2)flag[findset(i)]=1;
		}
		for(i=0;i<n;++i){
			if(father[i]==i){
				if(flag[i]==0){
					num++;
				}
			}
		}
		printf("%d %d\n",sum,num);
	}
	return 0;
}