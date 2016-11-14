//http://codeforces.com/contest/278/problem/C

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

const int MAX=222;
int link[MAX],n,m;
bool marry[MAX][MAX];

void dfs(int v){
	for(int i=1;i<=n+m;++i){
		if(marry[v][i] && !link[i]){
			link[i]=v;
			dfs(i);
		}
	}
}

int main(){
	int k,a,sum=0;
	while(cin>>n>>m){
		for(int i=1;i<=n;++i){
			cin>>k;
			if(!k)++sum;
			for(int j=0;j<k;++j){
				cin>>a;
				marry[i][n+a]=marry[n+a][i]=true;
			}
		}
		int num=0;
		for(int i=1;i<=n;++i){
			if(!link[i]){
				link[i]=1;
				++num;dfs(i);
			}
		}
		if(sum == num)cout<<sum<<endl;
		else cout<<num-1<<endl;
	}
	return 0;
}