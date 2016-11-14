#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=102;
vector<int>s[MAX];
int v[MAX],sum[MAX],prior[MAX],dist[MAX];
bool mark[MAX];
int main(){
	int t,n,m,a,b,num=1;
	cin>>t;
	while(t--){
		cin>>n;
		memset(sum,0,sizeof(int)*(n+2));
		memset(mark,0,sizeof(int)*(n+2));
		for(int i=1;i<=n;++i){
			cin>>v[i];
			s[i].clear();
		}
		s[n+1].clear();
		v[n+1]=0;
		cin>>m;
		for(int i=0;i<m;++i){
			scanf("%d%d",&a,&b);
			s[b].push_back(a);
		}
		mark[1]=true;
		for(int i=2;i<=n+1;++i){
			for(int j=0;j<s[i].size();++j){
				if(mark[s[i][j]]&&v[i]+sum[s[i][j]]>sum[i]){
					sum[i]=v[i]+sum[s[i][j]];
					mark[i]=true;
					prior[i]=s[i][j];
				}
			}
		}
		int k=0,u=n+1;
		while(prior[u]!=1){
			dist[k++]=prior[u];
			u=prior[u];
		}
		cout<<"CASE "<<num++<<"#\n";
		cout<<"points : "<<sum[n+1]<<endl; 
		cout<<"circuit : 1";
		for(int i=k-1;i>=0;--i){
			cout<<"->"<<dist[i];
		}
		cout<<"->1\n";
		if(t)cout<<endl;
	}
	return 0;
}
