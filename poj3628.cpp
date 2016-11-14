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
const int MAX=22;
int s[MAX],h,n,excess;
void dfs(int pos,int num){
	if(num>=h){
		excess=min(excess,num-h);
		return;
	}
	if(pos+1<=n){
		dfs(pos+1,num+s[pos+1]);
	    dfs(pos+1,num);
	}
	return;
}
int main(){
	while(scanf("%d%d",&n,&h)!=EOF){
		for(int i=1;i<=n;++i){
			scanf("%d",&s[i]);
		}
		s[0]=0;
		excess=INF;
		dfs(0,0);
		cout<<excess<<endl;
	}
	return 0;
} 