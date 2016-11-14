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

const int MAX=10+10;
bool mark[MAX][MAX];
int n,m,k,a,sum;
int father[MAX];

void dfs(int id,int num){
	if(num>m)return;
	if(sum != -1)return;
	if(id == n){sum=num;return;}
	dfs(id+1,num+1);
	for(int i=0;i<id;++i){
		if(father[i] != i)continue;//找集合的根 
		int temp=1;
		for(int j=i;j<id && temp;++j){
			if(father[j] == i)temp=mark[id][j];//判断该点是否能进入集合i(即是否和集合中的人互相喜欢) 
		}
		if(temp){father[id]=i;dfs(id+1,num);}//满足条件该点可以进入集合 
	}
	father[id]=id;
}

void Init(int &n){
	memset(mark,false,sizeof mark);
	for(int i=0;i<n;++i)father[i]=i;
}

int main(){
	while(cin>>n>>m){
		Init(n);
		for(int i=0;i<n;++i){
			cin>>k;
			while(k--){
				cin>>a;
				mark[i][a]=true;
			}
		}
		sum=-1;
		dfs(1,1);//查询下一个人所属集合和已有几个集合 
		if(sum != -1)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}