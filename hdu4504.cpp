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

const int MAX=25;
int dp[MAX][MAX*3];//dp��ʾ����i�εõ�j�ֵ���෽����

int main(){
	int a,b,t;
	dp[0][0]=dp[1][1]=dp[1][2]=dp[1][3]=1;
	for(int i=2;i<MAX;++i){//Ԥ����ʡʱ�� 
		for(int j=0;j<MAX*3;++j){
			dp[i][j]=dp[i-1][j-1];//��ʾ���ν������ֵ�1��
			if(j>=2)dp[i][j]+=dp[i-1][j-2];//��ʾ���ν����о�Ͷ����2��
			if(j>=3)dp[i][j]+=dp[i-1][j-3];//��ʾ���ν����������3�� 
		}
	}
	while(cin>>a>>b>>t){
		int k=(t/15)/2,p=((t/15)%2 ? 1:0),num=(b+k-a+1)>(k+p)?(b+k-a+1):(k+p);//num��ʾ����Ҫ�ö��ٷ�,����Ϊ0��,k+p��ʾ���Խ������ٴ� 
		__int64 sum=0;
		for(int i=num;i<=(k+p)*3;++i)sum+=dp[k+p][i];
		cout<<sum<<endl;
	}
	return 0;
} 
