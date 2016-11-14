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
	//可以先判断2是不是,后面只需要判断奇数即可,效率增加,if(x%2 == 0).. 
	for(int i=2;i*i<=x;++i){//从2开始寻找因子，寻找到的因子一定为素因子(因为如果不是素因子则可以分解成因子之积早被除掉了). 
		if(x%i==0){ 
			int num=0;
			while(!(x%i)){//如果x含有多个i(如4含有2个2)则继续除i. 
				x=x/i;
				num++;//含有因子i的数量增加. 
			}
			factor[k]=i;//记录素因子 
			factor_power[k++]=num;//记录相应的素因子个数 
		}
	}
	if(x!=1){
		factor[k]=x;//最后除不尽的商不是1则是素数. 
		factor_power[k++]=1;
	}
}
int main(){
	int n,sum;
	while(cin>>n){
		sum=1;
		prime_factor(n);
		cout<<n<<"的素因子有:";
		for(int i=0;i<k;++i){
		    cout<<factor_power[i]<<"个"<<factor[i]<<' ';
			sum*=(factor_power[i]+1);//因子个数公式:(a1+1)*(a2+1).....,a1,a2...为素因子.	
		} 
		cout<<endl<<"共有因子数:"<<sum<<"个\n";
	}
	return 0;
}
//**************************************************************************//
/*先筛选好素数再求因子，效率增加.
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
另一种效率极低的方法
fill(s,s+MAX,1);
for(int i=2;i<MAX;++i){//含有因子i 
	for(int j=2;j<=MAX/i;++j){
		s[i*j]+=1;
	}
}*/