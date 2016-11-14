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

const int MAX=7+3;
int dp[MAX][3];
/*
dp[i][0]��ʾ����<=i�Ĳ�����62��4�����ĸ���
dp[i][1]��ʾ����Ϊi�Ĳ�����62�������λ��2�����ĸ���
dp[i][2]��ʾ����<=i�ĺ���62����4�����ĸ��� 
*/ 
int digit[MAX];//��¼����ÿһλ

void init(){//Ԥ�����ǰi��dp[i][0],dp[i][1],dp[i][2] 
	dp[0][0]=1;
	for(int i=1;i<MAX;++i){
		dp[i][0]=dp[i-1][0]*9-dp[i-1][1];//0,1,2,3,4,5...9 + xxxxxxx ==>0xxxx,1xxxxx.....����4xxxxx��6 + 2xxxx������
		dp[i][1]=dp[i-1][0];//2 + xxxxx ==> 2xxxxx 
		dp[i][2]=dp[i-1][2]*10+dp[i-1][0]+dp[i-1][1];//0,1,2,3...9 + xxx62xx/xxx4xxx , 4 + xxxx , 6 + 2xxxxxx
	}
}

int digit_dp(int n){
	int size=0,mark=0,sum=0;
	while(n)digit[++size]=n%10,n=n/10;
	digit[size+1]=0;
	for(int i=size;i>=1;--i){
		sum+=dp[i-1][2]*digit[i];//��λ�к��в������� 
		if(mark)sum+=dp[i-1][0]*digit[i];//��λ���Ѻ��в�����������λ�в����в������� 
		else{
			if(digit[i]>4)sum+=dp[i-1][0];//��ǰ��һλ������ɲ�������:4
			if(digit[i]>6)sum+=dp[i-1][1];//��ǰ��һλ����һλ������ɲ�������:62
			if(digit[i+1] == 6 && digit[i]>2)sum+=dp[i][1];//��ǰ��һλ����һλ������ɲ�������:62 
		} 
		if(digit[i+1] == 6 && digit[i] == 2 || digit[i] == 4)mark=true;
	}
	return sum;
}

int main(){
	init();
	int a,b;
	while(cin>>a>>b,a+b){
		cout<<b-a+1-digit_dp(b+1)+digit_dp(a)<<endl;
	}
	return 0;
} 