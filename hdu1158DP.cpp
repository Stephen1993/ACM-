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
int cost[14][MAX];//ÿ���¶����˵Ļ���. 
int s[14];
int n,hire,salary,fire;
int dp(){
	int max_people=s[1];//��i���¼���֮ǰ���������ʱ���Ա��. 
	int people=s[1];//��i����֮ǰ���������ʱ���Ա��.
	int min_cost; 
	cost[1][s[1]]=hire*s[1]+salary*s[1];//��һ���¹�Ӷ�˵���ĩ���軨��. 
	for(int i=2;i<=n;++i){
		max_people=max(s[i],max_people);
		for(int j=s[i];j<=max_people;++j){
			min_cost=INF;
			for(int k=s[i-1];k<=people;++k){//��i-1���Ѿ���Ӷ��k����. 
				if(k<=j){ 
					cost[i][j]=cost[i-1][k]+(j-k)*hire+j*salary;//��i�¹�Ӷj�˲���Ҫ��������Ҫ�Ļ���. 
				}
				else{
					cost[i][j]=cost[i-1][k]+(k-j)*fire+j*salary;//��i�¹�Ӷj�˲���Ҫ�������Ҫ�Ļ���.
				}
				min_cost=min(min_cost,cost[i][j]);
			}
			cost[i][j]=min_cost;//��i�¹�Ӷj���˵���С����. 
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