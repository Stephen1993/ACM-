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

const int MAX=101;
int dp[MAX][MAX];//dp��ʾ����i��������ɱ��jֻ�ֵõ������ľ���ֵ.
int value[MAX][MAX];

int main(){
	int n,m,k,s;
	while(cin>>n>>m>>k>>s){
		memset(dp,0,sizeof dp);
		for(int i=0;i<k;++i){
			cin>>value[i][0]>>value[i][1];
		}
		int min=-1;
		//��ά���ñ���,�������������ɱ�Ĺ���Ϊ����. 
		for(int i=0;i<k;++i){
			for(int j=value[i][1];j<=m;++j){
				for(int t=1;t<=s;++t){//for(int t=s;t>=1;--t)Ҳ��. 
					dp[j][t]=max(dp[j][t],dp[j-value[i][1]][t-1]+value[i][0]);
					if(dp[j][t]>=n)min=min>(m-j)?min:(m-j);//�ڻ�õľ������n����������ʣ�����������. 
				}
			}
		}
		cout<<min<<endl;
	}
	return 0;
} 