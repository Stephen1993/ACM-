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

const int MAX=32768;

int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		long long sum=0;
		sum+=n/3;//ȫ��3��1��Ӳ���ж�����.
		sum++;//ȫ��1��Ӳ��.
		sum+=n/2;//ȫ��2��1��Ӳ���ж�����. 
		for(int i=1;i<=n/3;++i){
			sum+=(n-3*i)/2;//����2��3��Ӳ���ж�����. 
		} 
		cout<<sum<<endl;
	}
	return 0;
} 