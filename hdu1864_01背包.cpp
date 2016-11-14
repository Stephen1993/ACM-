#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iomanip>
#include<algorithm>
#include<queue>
using namespace std;
const int MAX=50;
double dp[MAX];
double value[MAX];
int main(){
	double d[250];
	int n;
	double Q;
	while(cin>>Q>>n,n){
		memset(dp,0,sizeof(dp));
		int m;
		double money;
		char a,b;
		int k=0;
		for(int i=0;i<n;++i){
			memset(d,0,sizeof(d));
			cin>>m;
			double all_money=0;
			bool flag=true;
			for(int i=0;i<m;++i){
				//getchar();
				//scanf("%c:%lf",&a,&money);
				cin>>a>>b>>money;
				d[a]+=money;
				if(a!='A'&&a!='B'&&a!='C'||d[a]>600){
					flag=false;
				}
				all_money+=money;
			}
			if(all_money<=1000&&flag){
				value[k++]=all_money;
			}
		}
		double max_money=0;
		for(int i=0;i<k;++i){
			for(int j=k;j>=1;j--){
			   dp[j]=max(dp[j],dp[j-1]+value[i]);
			   if(dp[j]<=Q){
   				  max_money=max_money>dp[j]?max_money:dp[j];
   			   }
			}
		}
		cout<<fixed<<setprecision(2)<<max_money<<endl;
	}
}/* 以发票作为背包的BUG 
100.00 5
1 A:5
1 B:20
1 C:24
1 A:30
1 A:60
得到的是 90.00 但正确的应该是95.00
此题可以以得到Q作为背包，因为结果是保留两位小数，所以只需将int(Q*100)作为背包即可。 
*/