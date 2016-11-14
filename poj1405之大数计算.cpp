/*分析:对于当前这个人只有尽可能分配更多才能使后面人尽可能分的更多
使得最终亲属分配的总金额最多，使教会分得的最少
所以(一下所有的比例都是总遗嘱的比例)
第一个人分配1/2,剩下1/2(则下一个人最多能分配1/3)
第二个人分配1/3,剩下1/2 - 1/3=1/6(则下一个人最多能分配1/7)
第三个人分配1/7,剩下1/6 - 1/7=1/42
....
第n个人分配f[n]=(f[n-1]-1)*f[n]+1;//f[n]表示分母 
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=10000+10;
const int Base=10000;
int f[20][MAX];

void mult(int Id){
	int i,j,k,m=f[Id][0],n=f[Id-1][0];
	int all=m+n-1;
	for(i=1,k=1;i<=m;++i){
		k=i;
		if(f[Id][i]){
			for(j=1;j<=n;++j,++k){
				f[Id+1][k]+=f[Id][i]*f[Id-1][j];//f[Id+1]记录(f[n-1]-1)*f[n],也是f[Id]-1 
				if(f[Id+1][k]>=Base){
				   f[Id+1][k+1]+=f[Id+1][k]/Base;
				   f[Id+1][k]=f[Id+1][k]%Base;	
				}
			}
		}
	}
	while(f[Id+1][k]>=Base){
		f[Id+1][k+1]+=f[Id+1][k]/Base;
		f[Id+1][k++]=f[Id+1][k]%Base;
	}
	if(!f[Id+1][k])--k;//k=m+n,需要判断第m+n位,比如20*20，40*40 
	f[Id+1][0]=k;
	for(int i=0;i<=k;++i)f[Id][i]=f[Id+1][i];//f[Id+1]相当于(f[n-1]-1)*f[n],也是f[Id]-1 
	++f[Id][1];//f[n]=(f[n-1]-1)*f[n]+1;
	k=1;
	while(f[Id][k]>=Base)f[Id][k]=0,++f[Id][++k];
	if(k>f[Id][0])f[Id][0]=k;
}

int main(){
	f[1][0]=1,f[1][1]=2;
	f[2][0]=f[2][1]=1;
	int n,size;
	scanf("%d",&n);
	printf("2\n");
	for(int i=2;i<=n;++i){
		mult(i);
		size=f[i][0];
		printf("%d",f[i][size]);
		for(int j=size-1;j>0;--j)printf("%04d",f[i][j]);
		printf("\n");
	}
	return 0;
}