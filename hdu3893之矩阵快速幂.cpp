/*分析:假设
dp[i][0]表示长度为i的全部有效数
dp[i][5]表示长度为i的以12345结尾的有效数(方便dp[i][0]减去654321xxx,123456xxx这种)
dp[i][4]表示长度为i的以1234结尾的有效数(方便得到dp[i][5])
dp[i][3]表示长度为i的以123结尾的有效数(方便得到dp[i][4])
dp[i][2]表示长度为i的以12结尾的有效数(方便得到dp[i])[3]
dp[i][1]表示长度为i的以1结尾的有效数(方便得到dp[i][2])
则:
dp[i][0]=5*dp[i-1][0]-2*dp[i][5];//减去654321,123456这种
dp[i][5]=dp[i-1][4];
dp[i][4]=dp[i-1][3];
dp[i][3]=dp[i-1][2]
dp[i][2]=dp[i-1][1];
dp[i][1]=dp[i][0]-dp[i-1][1]-dp[i][5];//减去11xxx,123456xxx这种
然后用矩阵快速幂求dp[n][0]
*/
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

const int MAX=6;
const int mod=112233;
__int64 array[MAX][MAX],sum[MAX][MAX];

void MatrixMult(__int64 a[MAX][MAX],__int64 b[MAX][MAX]){
	__int64 c[MAX][MAX]={0};
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j){
			for(int k=0;k<MAX;++k){
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	for(int i=0;i<MAX;++i){
		for(int j=0;j<MAX;++j)a[i][j]=c[i][j]%mod;
	}
}

__int64 Matrix(int k){
	memset(array,0,sizeof array);
	array[0][0]=5,array[0][1]=-2;
	array[1][2]=array[2][3]=array[3][4]=array[4][5]=array[5][0]=1;
	array[5][1]=array[5][5]=-1;
	for(int i=0;i<MAX;++i){//初始化sum使sum*a=a 
		for(int j=0;j<MAX;++j)sum[i][j]=(i == j);
	}
	while(k){
		if(k&1)MatrixMult(sum,array);
		MatrixMult(array,array);
		k>>=1;
	}
	return ((sum[0][0]*6+sum[0][5])%mod+mod)%mod;//dp[1][0]=6,dp[1][1]=1,dp[1][i]=0(i != 1 && i != 0)
}

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		if(n%2 == 0)printf("0\n");//偶数由于对称中间两个一定相等所以没有符合的 
		else{
			n=n/2+1;
			printf("%I64d\n",Matrix(n-1));//dp是从长度1开始,所以只需要矩阵相乘n-1次就是长度为n的结果 
		}
	}
	return 0;
}