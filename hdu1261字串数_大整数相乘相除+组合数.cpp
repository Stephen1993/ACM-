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

const int MAX=27;
short s[MAX];
int sub[100];

void mult(int *sub,int sum,int m){
	int Base=10000,p=0;
	for(int i=1;i<=sub[0];++i){//sub[0]记录大数的位数,计算sub[]*sum. 
		sub[i]=sub[i]*sum+p;
		p=sub[i]/Base;
		sub[i]=sub[i]%Base;
	}
	while(p){
		sub[0]++;
		sub[sub[0]]=p%Base;
		p=p/Base;
	}
	for(int i=sub[0];i>=1;--i){//计算sub[]/m;
		sub[i]+=p;
		p=(sub[i]%m)*Base;
		sub[i]=sub[i]/m;
	}
	while(!sub[sub[0]])sub[0]--;//大数的第一位为0则要去掉,如sub[]={3,1,2,0},该数是21而非021. 
}

void cbm(int n,int m){
	for(int i=1;i<=m;++i)
	    mult(sub,n-m+i,i);//每次sub[]*(n-m+i)/i.
	return;
}

int main(){
	int n;
	while(cin>>n,n){
		int sum=0;
		sub[0]=sub[1]=1;
		for(int i=0;i<n;++i){
			cin>>s[i];
			sum+=s[i];
		}
		for(int i=0;i<n-1;++i){
			cbm(sum,s[i]);//组合数. 
			sum-=s[i];
		}
		cout<<sub[sub[0]];
		for(int i=sub[0]-1;i>=1;--i){
			cout<<setfill('0')<<setw(4)<<sub[i];
		}
		cout<<endl;
	}
	return 0;
}