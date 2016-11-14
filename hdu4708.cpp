#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=10;
int s[MAX][MAX];

int main(){
	int n,m;
	while(scanf("%d",&n),n){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j)scanf("%d",&s[i][j]);
		}
		int sum=0,num=0,temp=0,k; 
		for(int i=0;i<n/2;++i){//从第i行开始的四边形 
			k=INF,temp=-INF;
			for(int j=0;j<=n-2*i-2;++j){//分别计算顺时针旋转j(逆时针旋转n-2*i-1-j次)次后左上角,左下角,右上角,右下角相加的和 
				m=s[i+j][i]+s[n-1-i][i+j]+s[i][n-1-i-j]+s[n-1-i-j][n-1-i];
				if(m>temp){
					temp=m;
					k=j;
				}else if(m == temp)k=min(k,n-2*i-1-k)<min(j,n-2*i-1-j)?k:j;//考虑得到相同的最大值但是旋转次数可能更少 
			}
			sum+=temp;
			num+=min(k,n-2*i-1-k);
		}
		cout<<sum+s[n/2][n/2]<<' '<<num<<endl;
	}
	return 0;
}