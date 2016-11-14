#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<iomanip>
#include<cmath>
#define INF 999999
using namespace std;
const int MAX=10000000;
bool prime[MAX];
int hui[1000],num=0;
void Prime(){
	for(int i=2;i<MAX/2;++i)prime[i*2]=true;//��ż���ų�. 
	for(int i=3;i<=(int)sqrt(MAX*1.0);i+=2){//ʣ�µ���ֻ�����������ı�����ż���ı����ѱ��ų�. 
		if(!prime[i]){
			for(int j=i*i;j<=MAX;j+=2*i){//j��i*i��ʼ��Ϊ�����е�����ֻ���ж�һ��,��i=5;��15�����ж� 
			    prime[j]=true;          //��Ϊ15�ѱ�i=3ʱ�ж�,j+=i*2�Ǳ�֤jΪ����(ż�����ѱ��жϹ�)(j+=2*i����Ϊ:����+����+����=����). 
		    }                          //j=i*i����Ϊj=i*k(k<i��Ϊ����)ʱ�类��i=kʱɸѡ����,����j��i*i��ʼ���ظ�. 
		}
	}
}
void huiwen(){
	char s[10];
	for(int i=2;i<MAX;++i){
		if(!prime[i]){
			sprintf(s,"%d",i);//��iת��Ϊ�ַ���s.
			int l=strlen(s),j;
			for(j=0;j<l/2;++j){
				if(s[j]!=s[l-1-j]){
					break;
				}
			}
			if(j==l/2)hui[num++]=i;
		}
	}
}
int main(){
	Prime();
	huiwen();
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF){
		for(int i=0;i<num;++i){
			if(hui[i]>b)break;
			if(hui[i]>=a){
				printf("%d\n",hui[i]);
			}
		}
		cout<<endl;
	}
	return 0;
}