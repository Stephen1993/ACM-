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

const int MAX=100010;
int father[MAX],rank[MAX],all;
bool flag,mark[MAX],indu[MAX];

void makeset(int num){
	for(int i=0;i<=num;++i){
		father[i]=i;
		rank[i]=1;
	}
}

int findset(int v){
	if(v != father[v]){
		father[v]=findset(father[v]);
	}
	return father[v];
}

void Union(int x,int y){
	int a=findset(x);
	int b=findset(y);
	if(a == b){
		flag=true;
		return;
	}
	if(rank[a]>rank[b]){
		rank[a]+=rank[b];
		father[b]=a;
	}
	else{
		rank[b]+=rank[a];
		father[a]=b;
	}
	all++;//计算边数. 
}

int main(){
	int a,b,num=1;
	while(cin>>a>>b,a>=0 && b>=0){
		int sum=0;//总的节点数. 
		all=0;
		if(a == 0 && b == 0){cout<<"Case "<<num++<<" is a tree.\n";continue;}
		memset(mark,false,sizeof mark);
		memset(indu,false,sizeof indu);
		flag=false;
		makeset(100005);
		Union(a,b);
		if(!mark[a]){sum++;mark[a]=true;}
		if(!mark[b]){sum++;mark[b]=true;}
		if(!indu[b]){indu[b]=true;}
		else flag=true;
		while(cin>>a>>b,a !=0 && b !=0){
			if(!flag)Union(a,b);
			if(!mark[a]){sum++;mark[a]=true;}
		    if(!mark[b]){sum++;mark[b]=true;}
		    if(!indu[b]){indu[b]=true;}
	        else flag=true;//所有点的入度最大不为1. 
		}
		//所有点的入度是否为1,是否存在环,是否边数比点数少1. 
		if(flag || sum-all != 1)cout<<"Case "<<num++<<" is not a tree.";
		else cout<<"Case "<<num++<<" is a tree.";
		cout<<endl;
	}
	return 0;
}