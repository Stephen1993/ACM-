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

const int MAX=1000001;
int *s,*present,*prior;
//present代表前j个数且包括第j个数的i段子序列最大和,prior表示前j个数i段子序列的最大和 

int main(){
	int m,n;
	while(cin>>m>>n){
		s=new int[n+1];
		for(int i=1;i<=n;++i)scanf("%d",s+i);
		present=new int[n+1];
		prior=(int *)calloc(n+1,sizeof(int));//calloc和maccoc区别在于它分配的内存连续且已对数据初始化为0
		present[0]=0;//只需要对present[0]初始化,因为present[n]可以由present[n-1]得到
		int sum=0;
		for(int i=1;i<=m;++i){
			sum=-INF;
			for(int j=i;j<=n-m+i;++j){//m段时对应最少计算前n个数,m-1段时对应最少要计算前n-1个数,...i段对应最少要计算前n-m+i个数 
				//present[j-1]在这里代表前j-1个数i段序列的最大值,当j=j-1时就已经计算了present[j-1] 
			   //prior[j-1]在这里代表前j-1个数i-1段序列的最大值,因为还没更新prior[j-1]为i段的最大值
				present[j]=max(present[j-1]+s[j],prior[j-1]+s[j]);//将第j个数连载前i段的最后面或者自成一段与前i-1段合成i段 
				prior[j-1]=sum;//更新为前j-1个数i段的最大值,sum就是前j-1个数i段的最大值 
				sum=max(present[j],sum);//计算前j个数i段的最大值 
			}//present[j]=max(present[j-1]+s[j],prior[j-1]+s[j]);prior[j-1]=(present[j-1],prior[j-2]);
			prior[n-m+i]=sum;//prior[n]=max(present[n],prior[n-1]);
		} 
		cout<<sum<<endl;
		delete[] s;
		delete[] present;
		delete[] prior;
	}
	return 0;
}