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
bool flag;
void prime_factor(int x){
	k=0;
	int num=0;
	if(x%2==0){
		while(!(x%2)){ 
				x=x/2;
				num++; 
		}
		//factor[k]=2; 
		factor_power[k++]=num;
	}
	for(int i=3;i*i<=x;i+=2){
		if(x%i==0){
			num=0;
			while(!(x%i)){ 
				x=x/i;
				num++; 
			}
			if(k>0&&num!=factor_power[0]){
				flag=false;
				break;
			}
			//factor[k]=i; 
			factor_power[k++]=num;
		}
	}
	if(x!=1){
		if(factor_power[0]!=1)flag=false;
	}
}
int main(){
	int n,sum;
	while(scanf("%d",&n),n){
		flag=true;
		sum=1;
		prime_factor(n);
		cout<<clock()<<endl;
		if(flag)cout<<factor_power[0]<<endl;
		else cout<<"1\n";
	}
	return 0;
}