#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<time.h>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>
#define INF 999999 
using namespace std;
const int MAX=10000000;
bool prime[MAX+1];
void Prime(){
	for(int i=2;i<=MAX/2;++i)prime[i*2]=true;//��ż���ų� 
	for(int i=3;i<=(int)sqrt(MAX*1.0);i+=2){//ʣ�µ���ֻ�����������ı�����ż���ı����ѱ��ų�. 
		if(!prime[i]){
			for(int j=i*i;j<=MAX;j+=2*i){//j��i*i��ʼ��Ϊ�����е�����ֻ���ж�һ��,��i=5;��15�����ж� 
			    prime[j]=true;          //��Ϊ15�ѱ�i=3ʱ�ж�,j+=i*2�Ǳ�֤jΪ����(ż�����ѱ��жϹ�)(j+=2*i����Ϊ:����+����+����=����). 
		    }                          //j=i*i����Ϊj=i*k(k<i��Ϊ����)ʱ�类��i=kʱɸѡ����,����j��i*i��ʼ���ظ�. 
		}
	}
}
int main(){
	Prime();
	cout<<"ʱ��:"<<(double)clock()<<"ms"<<endl;
	return 0;
}