//��νŷ����������[1,n-1]����n�����Լ�� == 1�����ĸ���;
/*
���Ƶ�:��n������p��k���ݼ�n=p^k,���Գ���p�ı�����,����������n����, 
����n֮��p�ı������Ϊp^(k-1)-1��,����s[n]=s[p^k]=p^k-1-(p^(k-1)-1)=(p-1)*p^(k-1),s[n]����n��ŷ��ֵ.
ŷ�������ǻ��Ժ���,����˵��m,n����,s(mn)=s(m)*s(n),������n��Ϊ����,n=a1^p1*a2^p2...*an^pn(a1..anΪ����).
��s(n)=s(a1^p1)...*s(an^pn)=(a1-1)*a1^(p1-1)*...(an-1)*an^(pn-1)=(a1^p1-a1^��p1-1))...
=a1^p1(1-1/a1)*a2^p2(1-1/a2)...=n(1-1/a1)...
��ŷ��ֵ,1:�ù�ʽs(n)=s(a1^p1)...*s(an^pn)=(a1-1)*a1^(p1-1)*...(an-1)*an^(pn-1)��,������������Ӽ����ݼ���.
2:�ù�ʽs[n]=n*(1-1/a1)*(1-1/a2)*....��. 
*/ 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#define INF 999999
using namespace std;
const int MAX=100;
int Euler(int x){
	int sum=x;
	for(int i=2;i*i<=x;++i){//��x��������. 
		if(x%i==0){
			sum-=sum/i;
			while(x%i==0){
				x=x/i;
			}
		}
	}
	if(x!=1){
		sum-=sum/x;
	}
	return sum;
}
int main(){
	int n;
	while(cin>>n){
		cout<<"ŷ��ֵΪ:"<<Euler(n)<<endl;//ŷ��ֵ=n*(1-1/a1)*(1-1/a2)*....,a1,a2Ϊn�Ĳ��ظ���������. 
	}
	return 0;
}
/*��Ȼ�����Ԥ����������Ļ���Ҳ������ŷ������������죡
int Euler(int x){
   int i,tmp=x; 
   for(i=1; i<=prime[0] && prime[i]*prime[i]<=tmp; i++){//prime[0]���������ĸ���. 
       if( tmp%prime[i]==0 ) {
           x-= (x/prime[i]);
       while( tmp%prime[i] == 0 ) tmp/= prime[i];
       }
   }
   if(tmp>1) x-= x/tmp;
   return x;
}*/
//******************************************************************************//
