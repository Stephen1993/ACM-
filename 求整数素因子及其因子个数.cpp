#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<iomanip>
#define INF 999999
using namespace std;
const int MAX=100;
int factor[MAX],k;
int factor_power[MAX];
void prime_factor(int x){
	k=0;
	//�������ж�2�ǲ���,����ֻ��Ҫ�ж���������,Ч������,if(x%2 == 0).. 
	for(int i=2;i*i<=x;++i){//��2��ʼѰ�����ӣ�Ѱ�ҵ�������һ��Ϊ������(��Ϊ�����������������Էֽ������֮���类������). 
		if(x%i==0){ 
			int num=0;
			while(!(x%i)){//���x���ж��i(��4����2��2)�������i. 
				x=x/i;
				num++;//��������i����������. 
			}
			factor[k]=i;//��¼������ 
			factor_power[k++]=num;//��¼��Ӧ�������Ӹ��� 
		}
	}
	if(x!=1){
		factor[k]=x;//�����������̲���1��������. 
		factor_power[k++]=1;
	}
}
int main(){
	int n,sum;
	while(cin>>n){
		sum=1;
		prime_factor(n);
		cout<<n<<"����������:";
		for(int i=0;i<k;++i){
		    cout<<factor_power[i]<<"��"<<factor[i]<<' ';
			sum*=(factor_power[i]+1);//���Ӹ�����ʽ:(a1+1)*(a2+1).....,a1,a2...Ϊ������.	
		} 
		cout<<endl<<"����������:"<<sum<<"��\n";
	}
	return 0;
}
//**************************************************************************//
/*��ɸѡ�������������ӣ�Ч������.
Prime(){
	//for(int i=2;i<MAX/2;++i)prime[2*i]=true;
	for(int i=3;i*i<MAX;i+=2){
		if(!prime[i]){
			for(int j=i*i;j<MAX;j+=2*i){
				prime[j]=true;
			}
		}
	}
	for(int i=2;i<MAX;++i){
    	if(!prime[i])s[++k]=i;
    }
} 
void prime_factor(int x){
	for(int i=0;i<k&&s[i]*s[i]<=x;++i){
		if(x%s[i]==0){
			int num=0;
			while(!(x%s[i])){ 
				x=x/s[i];
				num++;
			}
			factor[k]=s[i]; 
			factor_power[k++]=num; 
		}
	}
	if(x!=1){
		factor[k]=x; 
		factor_power[k++]=1;
	}
}
****************************************************************
��һ��Ч�ʼ��͵ķ���
fill(s,s+MAX,1);
for(int i=2;i<MAX;++i){//��������i 
	for(int j=2;j<=MAX/i;++j){
		s[i*j]+=1;
	}
}*/