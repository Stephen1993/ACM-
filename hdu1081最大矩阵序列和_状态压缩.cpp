#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#define INF 9999999
using namespace std;
const int MAX=111;
int s[MAX][MAX];//C储存第i行第j列前所有数之和. 
int main(){
	int n,a;
	while(cin>>n){
		for(int i=0;i<n;++i){
			for(int j=1;j<=n;++j){
				scanf("%d",&a);
				s[i][j]=s[i][j-1]+a; 
			}
		}
		int max=-INF,sum;
		for(int i=0;i<n;++i){
			for(int j=i+1;j<=n;++j){
				sum=0;
				for(int k=0;k<n;++k){
					if(sum<0){
						sum=0;
					}
					sum+=s[k][j]-s[k][i];//第k行第j列到第i列的最序列大值. 
					if(sum>max){
						max=sum;
					}
				}
			}
		}
		cout<<max<<endl;
	}
	return 0;
}
//本题最主要就是状态压缩累节省时间. 