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
}/* �Է�Ʊ��Ϊ������BUG 
100.00 5
1 A:5
1 B:20
1 C:24
1 A:30
1 A:60
�õ����� 90.00 ����ȷ��Ӧ����95.00
��������Եõ�Q��Ϊ��������Ϊ����Ǳ�����λС��������ֻ�轫int(Q*100)��Ϊ�������ɡ� 
*/