#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=130;
bool marry[MAX][MAX],mark[MAX];
int link[MAX];
int n,m;
bool find(int x){
	for(int i=1;i<=n;++i){
		if(!mark[i]&&marry[x][i]){
			mark[i]=true;
			if(!link[i]||find(link[i])){
				link[i]=x;
				return true;
			}
		}
	}
	return false;
}
int hungarian_algorithm(){
	int num=0;
	for(int i=1;i<=n;++i){
		memset(mark,false,sizeof mark);
		if(find(i))num++;
	}
	return num;
}
int main(){
	int t,a,b;
	cin>>t;
	while(t--){
		cin>>n>>m;
		memset(link,0,sizeof link);
		memset(marry,false,sizeof marry);
		for(int i=0;i<m;++i){
			cin>>a>>b;
			marry[a][b]=true;
		}
		int sum=hungarian_algorithm();
		cout<<n-sum<<endl;
	}
	return 0;
}