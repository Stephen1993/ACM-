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

const int MAX=100002;
bool dp[MAX];//��m��������,dp[i]����Ҫ���ֵΪi����Ʒ�Ƿ���ǡ����Ӳ����.
int a[102],b[102];//a�����i��Ӳ�ҵļ�ֵ,b�������. 

int main(){
	int n,m,k;
	while(cin>>n>>m,n||m){
		for(int i=0;i<n;++i)cin>>a[i];
		for(int i=0;i<n;++i)cin>>b[i];
		if(m<=0){cout<<"0\n";continue;}//���������Ļ����mΪ���������.
		memset(dp,false,sizeof(bool)*(m+1));
		dp[0]=true;
		for(int i=0;i<n;++i){
			/*if(a[i]*b[i]>=m){//���a[i]*b[i]>=m,���ڱ�������m��,��i��Ӳ�ҿ���ȡ����n��(n*a[i]<=m)�����ᳬ��b[i]��,���Կ��Կ���Ϊ��ȫ����. 
				for(int j=a[i];j<=m;++j){
					if(dp[j-a[i]])dp[j]=true;
				}
			}*/
			//else{//���a[i]*b[i]<m,���ڱ�������m��,��i��Ӳ��������ȡb[i]��,�����ر���. 
				for(k=1;k*2-1<=b[i];k=k*2){//�ö����ư�b[i]�ֳ�1,2,4,8...2^(k-1),b[i]-2^k+1����Ʒ,Ȼ����01��������. 
					for(int j=m;j>=k*a[i];--j){
						if(dp[j-k*a[i]])dp[j]=true;
					}
				}
				for(int j=m;j>=(b[i]-k+1)*a[i];--j){
					if(dp[j-(b[i]-k+1)*a[i]])dp[j]=true;
				}
			//}
		}
		int sum=0;
		for(int i=1;i<=m;++i)if(dp[i])sum++;
		cout<<sum<<endl;
	}
	return 0;
} 