#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#include<set>
#define INF 99999999
using namespace std;

const int MAX=100001;
int father[MAX];
bool flag,mark[MAX];

int findset(int v){
	if(v!=father[v]){
		father[v]=findset(father[v]);
	}
	return father[v];
}

void Union(int x,int y){
	int a=findset(x);
	int b=findset(y);
	if(a==b && x!=y){
		flag=true;
		return;
	}
	father[a]=b;
	return;
}

int main(){
	int a,b;
	while(1){
		int num=0,sum=0;
		flag=false;
		memset(mark,false,sizeof mark);
		for(int i=1;i<=100000;++i)father[i]=i;
		while(scanf("%d%d",&a,&b),a!=0 || b!=0){
			if(a==-1 && b==-1)return 0;
			if(!mark[a]){
				mark[a]=true;
				sum++;
			}
			if(!mark[b]){
				mark[b]=true;
				sum++;
			}
			num++;
			if(!flag)
			Union(a,b);
		}
		if(flag || (sum!=num+1 && sum!=0))cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}