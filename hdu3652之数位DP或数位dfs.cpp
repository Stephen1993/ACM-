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

const int MAX=10+5;
int dp[MAX][13][3],digit[MAX];
/*
size��ʾ��������ĳ���,��: 
dp[i][j][0]��ʾ��size��i+1λ������13�ҽ���ȥ����<=i��ģ13Ϊj�����ĸ���
dp[i][j][1]��ʾ��size��i+1λ������13���ǵ�i+1λ��1�ҽ���ȥ����<=i��ģ13Ϊj�����ĸ���
dp[i][j][2]��ʾ��size��i+1λ����13�ҽ���ȥ����<=i��ģ13Ϊj�����ĸ��� 
*/

void init(int n){
	digit[0]=0;
	while(n)digit[++digit[0]]=n%10,n=n/10;
	//memset(dp,-1,sizeof dp);
}

//size������漸λ��,mod����ǰ�ܵ�����,mark��ʾ3�����,flag��ǵ����� 
int digit_dfs(int size,int mod,int mark,bool flag){//���仯���� 
	if(!size)return !mod && mark == 2;//��ʾ����������
	if(flag && dp[size][mod][mark] != -1)return dp[size][mod][mark];//��ʾ���泤�ȿ������������Ѿ�������
	int m=flag?9:digit[size];//�жϵ�ǰ������ķ�Χ
	int sum=0;
	for(int i=0;i<=m;++i){
		int Mod=(mod*10+i)%13;
		int Mark=mark;
		if(mark != 2 && i != 1)Mark=0;//��һ����� 
		if(mark != 2 && i == 1)Mark=1;//�ڶ������ 
		if(mark == 1 && i == 3)Mark=2;//��������� 
		sum+=digit_dfs(size-1,Mod,Mark,flag || i<m); 
	} 
	if(flag)dp[size][mod][mark]=sum;//�����,�´β���������
	return sum; 
}

int main(){
	memset(dp,-1,sizeof dp);
	int n;
	while(cin>>n){
		init(n);
		cout<<digit_dfs(digit[0],0,0,0)<<endl;
	}
	return 0;
}