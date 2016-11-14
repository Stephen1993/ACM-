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

const int MAX=20;
__int64 dp[MAX][3];
/*
dp[i][0]��ʾ����<=i�Ĳ�����49�����ĸ���,
dp[i][1]��ʾ����Ϊi�Ĳ�����49���Ǻ���9�����ĸ���,
dp[i][2]��ʾ����<=i����49�����ĸ���
*/
int digit[MAX],size;

void init(){
	dp[0][0]=1;
	for(int i=1;i<MAX;++i){
		dp[i][0]=dp[i-1][0]*10-dp[i-1][1];//����iλ����������ֻ��i-1λ����ǰ��+0,1,2,3...9,����Ҫ��ȥ4+9xxx ==>49xxx
		dp[i][1]=dp[i-1][0];//ֻ��Ҫ�ڲ�����49����ǰ���һλ9������
		dp[i][2]=dp[i-1][2]*10+dp[i-1][1];//iλ����ǰiλ����49����ǰiλ������49���ǵ�iλ��4,��i-1λ��9 
	}
}

int main(){
	init();
	int last,flag,t;
	unsigned __int64 n,sum;
	cin>>t;
	while(t--){
		last=size=flag=0,sum=0; 
		cin>>n;
		++n;//n+1��Ϊ������n������49�����޷�ͳ��������
		while(n)digit[++size]=n%10,n=n/10;
		for(int i=size;i>=1;--i){
			sum+=dp[i-1][2]*digit[i];//��i=sizeʱ�ͼ�����ǰ<iλ������ ==iλ���ǵ�iλС��digit[i]�ĺ���49�����ĸ���,���Խ�����ֻҪ���㵱��sizeλ��digit[size]...
			if(flag)sum+=dp[i-1][0]*digit[i];//�˴����ӵ�һ����iλ������49��
			if(!flag && digit[i]>4)sum+=dp[i-1][1]; 
			if(last == 4 && digit[i] == 9)flag=1;
			last=digit[i];
		} 
		cout<<sum<<endl;
	}
	return 0;
} 
 