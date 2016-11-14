#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<queue>
#include<map>
#include<cstring>
#include<string>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=1000;
const int Base=10000;
int seg=4;
int sum[MAX];
int n,m;
void mult(int *A,int b){
	int p=0;
	for(int i=1;i<=A[0];++i){
		A[i]=A[i]*b+p;
		if(A[i]>=Base){
			p=A[i]/Base;
			A[i]=A[i]%Base;
		}else p=0;
	}
	if(p){A[A[0]+1]=p;A[0]++;}
}
void div(int *A,int b){
	for(int i=A[0];i>=1;--i){
		A[i-1]=(A[i]%b)*Base+A[i-1];//如果没确定整除则要这样(每次计算前都加上上一次的余数):                    
        A[i]=A[i]/b;               //A[i]+=c;                          
	}                             //c=(A[i]%m)*Base;
	while(!A[A[0]])A[0]--;       //B[i]=A[i]/m;
}                               //防止最后A[0]加上余数.
int main(){
	int num=1;
	while(cin>>m>>n,n||m){
		if(n>m){
			cout<<"Test #"<<num++<<":\n";
			cout<<"0\n";
			continue;
		}
		sum[0]=sum[1]=1;
		for(int i=1;i<=n+m;++i){
			mult(sum,i);
		}
		mult(sum,m+1-n);
		div(sum,m+1);
		cout<<"Test #"<<num++<<":\n";
		cout<<sum[sum[0]];
		for(int i=sum[0]-1;i>=1;--i){
			cout<<setfill('0')<<setw(4)<<sum[i];
		}
		cout<<endl;
	}
	return 0;
}