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
int prime_factor[MAX],factor_num[MAX];
bool flag=true;

int digit(int n){
	int num=0;
	while(n){
		num+=n%10;
		n=n/10;
	}
	return num;
}

int factor(int n){
	int k=0;
	for(int i=2;i*i<=n;++i){//��������. 
		if(n%i == 0){
			int num=0;
			while(!(n%i)){
				n=n/i;
				num++;
			}
			prime_factor[k]=i;//��¼������. 
			factor_num[k++]=num;//��¼��Ӧ�������Ӹ���. 
		}
	}
	if(n!=1){
		prime_factor[k]=n;
		factor_num[k++]=1;
	}
	if(prime_factor[0] == n){flag=false;return 0;}//��ʾ����������. 
	int sum=0;
	for(int i=0;i<k;++i){//�����������ӵ�λ����. 
		sum+=factor_num[i]*digit(prime_factor[i]);
	}
	return sum;
}

int main(){
	int n;
	while(cin>>n,n){	
		while(n++){
			flag=true;
			if(flag && factor(n) == digit(n)){
				cout<<n<<endl;
				break;
			}
		}
	}
	return 0;
}