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
const int MAX=1000;
int cost[14][MAX];//每个月多少人的花费. 
int s[14];
int n,hire,salary,fire;
int dp(){
	int max_people=s[1];//第i个月及其之前的所需最多时候的员工. 
	int people=s[1];//第i个月之前的所需最多时候的员工.
	int min_cost; 
	cost[1][s[1]]=hire*s[1]+salary*s[1];//第一个月雇佣人到月末所需花费. 
	for(int i=2;i<=n;++i){
		max_people=max(s[i],max_people);
		for(int j=s[i];j<=max_people;++j){
			min_cost=INF;
			for(int k=s[i-1];k<=people;++k){//第i-1月已经雇佣了k个人. 
				if(k<=j){ 
					cost[i][j]=cost[i-1][k]+(j-k)*hire+j*salary;//第i月雇佣j人并且要增加人需要的花费. 
				}
				else{
					cost[i][j]=cost[i-1][k]+(k-j)*fire+j*salary;//第i月雇佣j人并且要解雇人需要的花费.
				}
				min_cost=min(min_cost,cost[i][j]);
			}
			cost[i][j]=min_cost;//第i月雇佣j个人的最小花费. 
		}
		people=max_people;
	}
	for(int i=s[n];i<=max_people;++i){
		cost[n][s[n]]=min(cost[n][s[n]],cost[n][i]);
	}
	return cost[n][s[n]];
}
int main(){
	while(cin>>n,n){
		cin>>hire>>salary>>fire;
		for(int i=1;i<=n;++i){
			cin>>s[i];
		} 
		cout<<dp()<<endl;
	}
	return 0;
} 