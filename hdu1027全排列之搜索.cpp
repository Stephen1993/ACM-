#include<iostream>
#include<cstdio>
using namespace std;
const int MAX=10002;
int n,m,sum;
int s[MAX];
bool mark[MAX];
void dfs(int num){
	if(num==n+1){
		sum++;
		return;
	}
	for(int i=1;i<=n;++i){
		if(sum==m)break;
		if(!mark[i]){
			s[num]=i;
			mark[i]=true;
			dfs(num+1);
			mark[i]=false;
		}
	}
}
int main(){
	while(cin>>n>>m){
		memset(mark,false,sizeof mark);
		sum=0;
		dfs(1);
		for(int i=1;i<=n;++i){
			printf("%d%c",s[i],i==n?'\n':' ');
		}
	}
	return 0;
}