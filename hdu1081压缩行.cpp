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

const int MAX=101;
int s[MAX][MAX];

int main(){
	int n,a;
	while(cin>>n){
		for(int i=1;i<=n;++i){
			for(int j=0;j<n;++j){
				scanf("%d",&a);
				s[i][j]=s[i-1][j]+a;
			}
		}
		int Max=-INF,num=0;
		for(int i=0;i<n;++i){
			for(int j=i+1;j<=n;++j){
				num=0;
				for(int k=0;k<n;++k){
					num=num+s[j][k]-s[i][k]>s[j][k]-s[i][k]?num+s[j][k]-s[i][k]:s[j][k]-s[i][k];
					Max=num>Max?num:Max;
				}
			}
		}
		cout<<Max<<endl;
	}
	return 0;
} 
                                                                                                               