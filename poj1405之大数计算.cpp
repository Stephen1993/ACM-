/*����:���ڵ�ǰ�����ֻ�о����ܷ���������ʹ�����˾����ֵܷĸ���
ʹ����������������ܽ����࣬ʹ�̻�ֵõ�����
����(һ�����еı��������������ı���)
��һ���˷���1/2,ʣ��1/2(����һ��������ܷ���1/3)
�ڶ����˷���1/3,ʣ��1/2 - 1/3=1/6(����һ��������ܷ���1/7)
�������˷���1/7,ʣ��1/6 - 1/7=1/42
....
��n���˷���f[n]=(f[n-1]-1)*f[n]+1;//f[n]��ʾ��ĸ 
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
				f[Id+1][k]+=f[Id][i]*f[Id-1][j];//f[Id+1]��¼(f[n-1]-1)*f[n],Ҳ��f[Id]-1 
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
	if(!f[Id+1][k])--k;//k=m+n,��Ҫ�жϵ�m+nλ,����20*20��40*40 
	f[Id+1][0]=k;
	for(int i=0;i<=k;++i)f[Id][i]=f[Id+1][i];//f[Id+1]�൱��(f[n-1]-1)*f[n],Ҳ��f[Id]-1 
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