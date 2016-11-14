#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<iomanip>
#define INF 999999
using namespace std;
const int MAX=1555;
int link[MAX];
vector<int>marry[MAX];//用邻接表求最大匹配,marry[i]表示与i匹配的入队.
bool mark[MAX];
int n;
bool find(int x){
	for(int i=0;i<marry[x].size();++i){
		if(!mark[marry[x][i]]){
			mark[marry[x][i]]=true;
			if(link[marry[x][i]]==-1||find(link[marry[x][i]])){
				link[marry[x][i]]=x;
				return true;
			}
			//mark[marry[x][i]]=false;
		}
	}
	return false;
}
int hungarian_algorithm(){
	int num=0;
	for(int i=0;i<n;++i){
		memset(mark,false,sizeof mark);
		if(find(i))num++;
	}
	return num;
}
int main(){
	int a,b,c;
	while(cin>>n){
		memset(link,-1,sizeof link);
		for(int i=0;i<n;++i){
			marry[i].clear();
		}
		for(int i=0;i<n;++i){
			scanf("%d: (%d)",&a,&b);
			for(int j=0;j<b;++j){
				scanf("%d",&c);
				marry[a].push_back(c);
				marry[c].push_back(a);
			}
		}
		int sum=hungarian_algorithm();
		cout<<sum/2<<endl;
	}
	return 0;
}
