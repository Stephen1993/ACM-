/*
这个题目要运用到欧拉路得相关知识，并且也要并查集，题目说的是：给你n个单词，要你判断这些单词能不能首尾相连。
理解题目意思后，进行转化，输入字符串，提取首位字母作为下标来表示两节点的出现，以及相对应节点入度和出度的增加，
转化为并查集的应用即可。那么从可以想象一幅由首位字母节点构成的图，当且仅当图是一条欧拉回路或者欧拉通路的时候，
才能满足题目的要求，至于欧拉回路和欧拉通路的判定可以总结为如下：
1）所有的点联通
2）欧拉回路中所有点的入度和出度一样。
3）欧拉通路中起点的入度 - 出度 = 1，终点的 初度 - 入度 = 1， 其他的所有点入度 = 出度
*/
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
const int MAX=27;
int father[MAX],rank[MAX];
int in_du[MAX],out_du[MAX],number[MAX];//入度，出度.入度不等于出度的点. 
bool mark[MAX];//标记单词是否出现.
int n;
char s[1002];
void make_set(int num){
	for(int i=0;i<num;++i){
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
	if(x==y)return;
	if(rank[a]>rank[b]){
		father[b]=a;
		rank[a]+=rank[b];
	}
	else{
		father[b]=a;
		rank[b]+=rank[a];
	}
}
int main(){
	int t,first,last;
	cin>>t;
	while(t--){
		int sum=0;//记录根节点. 
		memset(in_du,0,sizeof in_du);
		memset(out_du,0,sizeof out_du);
		memset(mark,false,sizeof mark);
		memset(number,0,sizeof number);
		make_set(26);
		cin>>n;
		for(int i=0;i<n;++i){
			scanf("%s",s);
			first=s[0]-'a';
			last=s[strlen(s)-1]-'a';
			in_du[last]++;
			out_du[first]++;
			mark[first]=mark[last]=true;
			Union(first,last);
		}
		for(int i=0;i<26;++i){
			if(findset(i)==i&&mark[i]){
				sum++;
			}
		}
		if(sum>1){
			cout<<"The door cannot be opened."<<endl;
			continue;
		}
		int k=0;
		for(int i=0;i<26;++i){
			if(mark[i]&&in_du[i]!=out_du[i]){
				number[k++]=i;
			}
		}
		if(k>2){
			cout<<"The door cannot be opened."<<endl;
			continue;
		}
		if(k==0){
			cout<<"Ordering is possible."<<endl;
			continue;
		}
		if(k==2){
			if(in_du[number[0]]+1==out_du[number[0]]&&in_du[number[1]]-1==out_du[number[1]]||in_du[number[0]]-1==out_du[number[0]]&&in_du[number[1]]+1==out_du[number[1]]){
				cout<<"Ordering is possible."<<endl;
			}
			else{
				cout<<"The door cannot be opened."<<endl;
			}
		}
	}
	return 0;
} 