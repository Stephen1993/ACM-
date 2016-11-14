#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
#include<queue>
using namespace std;
const int MAX=10005;
double dp[MAX],value[MAX][MAX];
int main(){
	int n,m;
	double a;
	cin>>n;
	while(n--){
		int all_money=0,max_money=0;
		cin>>a>>m;
		for(int i=0;i<m;++i){
			scanf("%lf%lf",&value[i][0],&value[i][1]);
			all_money+=(int)value[i][0];
		}
		for(int i=1;i<=all_money;++i){
			dp[i]=1;
		}
		dp[0]=0;
		for(int i=0;i<m;++i){
			for(int j=all_money;j>=(int)value[i][0];j--){
				dp[j]=min(dp[j],(1-(1-dp[j-(int)value[i][0]])*(1-value[i][1])));
				if(dp[j]<=a){
					max_money=max_money>j?max_money:j;
				}
			}
		}
		cout<<max_money<<endl;
	}
	return 0;
}

