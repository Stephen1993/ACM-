#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#include<vector>
#define INF 99999999
using namespace std;
const int MAX=50005;
__int64 dp[MAX][505];//��i���ڵ㵽��������ľ�����j�ĸ���. 
vector<int>s[MAX];
int n,k;
__int64 sum;
void dfs(int pre,int x){
	memset(dp[x],0,sizeof(int)*(k+1));
	dp[x][0]=1;
	for(int i=0;i<s[x].size();++i){
		if(s[x][i]==pre)continue;
		dfs(x,s[x][i]);
		for(int j=0;j<k;++j){
			sum+=dp[x][j]*dp[s[x][i]][k-1-j];//x��������һ�����������1�����룬����ʣ��k-1-j������. 
		}
		for(int j=1;j<=k;++j){
			dp[x][j]+=dp[s[x][i]][j-1];
		}
	}
}
int main(){
	int a,b;
	while(cin>>n>>k){
		sum=0;
		for(int i=1;i<=n;++i){
			s[i].clear();
		}
		for(int i=0;i<n-1;++i){
			cin>>a>>b;
			s[a].push_back(b);
			s[b].push_back(a);
		}
		dfs(-1,1);
		cout<<sum<<endl;
	}
	return 0;
}
