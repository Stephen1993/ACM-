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
const int MAX=1111;
int n,link[MAX];
vector<int>marry[MAX];
bool mark[MAX];
bool find(int x){
	for(int i=0;i<marry[x].size();++i){
		if(!mark[marry[x][i]]){
			mark[marry[x][i]]=true;
			if(link[marry[x][i]]==-1||find(link[marry[x][i]])){
				link[marry[x][i]]=x;
				return true;
			}
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
		for(int i=0;i<n;++i){
			marry[i].clear();
		}
		memset(link,-1,sizeof link);
		for(int i=0;i<n;++i){
			scanf("%d: (%d)",&a,&b);
			for(int j=0;j<b;++j){
				scanf("%d",&c);
				marry[a].push_back(c);
			}
		}
		int sum=n-hungarian_algorithm()/2;
		cout<<sum<<endl;
	}
	return 0;
}