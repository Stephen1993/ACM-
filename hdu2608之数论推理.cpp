/*
����:������n=2^k*p1^s1*p2^s2*p3^s3*...*pi^si;//k,s1...si>=0,p1..piΪn�������� 
����T[n]=(2^0+2^1+...+2^k)*(p1^0+p1^1+...+p1^s1)*...*(pi^0+pi^1+...+pi^si);
��Ȼ(2^0+2^1+...+2^k)%2=1,����T[n]��0��1��ȡ����(p1^0+p1^1+...+p1^s1)*...*(pi^0+pi^1+...+pi^si)
��p1...pi��������(��2֮�������һ��������),����(pi^0+pi^1+...+pi^si)ֻҪ��һ��siΪ����(i=1...i) 
��(pi^0+pi^1+...+pi^si)%2=0,��T[n]%2=0//��siΪ����,��pi^si+1Ϊż��,pi^1+pi^2+...+pi^(si-1)Ϊż��(ż����������Ϊż��)
����ҪT[n]%2=1,�����е�siΪż������n=2^(k%2)*m^2;//m=2^(k/2)*p1^(s1/2)*p2^(s2/2)*...*pi^(si/2)
����ֻҪnΪĳ������ƽ������ĳ������ƽ������T[n]%2=1,ֻҪͳ��n�ĸ������� 
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<cmath>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=10;

int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		int sum=(int)sqrt(n*1.0)+(int)sqrt(n*1.0/2);
		cout<<sum%2<<endl;
	}
	return 0;
}