#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 999999999
using namespace std;

const int MAX=101;
int s[MAX][MAX];

int main(){
	int n,m;
	while(cin>>n){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j)scanf("%d",&s[i][j]);
		}
		int sum=0,Max=-INF,num;
		for(int i=0;i<n;++i){
			for(int j=i;j<n;++j){
				sum=0;
				for(int k=0;k<n;++k){//��ǰk�е�i�е���j�е��Ӿ�������� 
					num=0;
					for(int a=i;a<=j;++a)num+=s[k][a];//���k�е�i�е���j�е�ֵ 
					sum=sum+num>num ? sum+num : num;
					Max=sum>Max ? sum : Max;
				}
			}
		}
		cout<<Max<<endl;
	}
	return 0;
}