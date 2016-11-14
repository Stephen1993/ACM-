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
		sum+=n/3;//全是3和1的硬币有多少种.
		sum++;//全是1的硬币.
		sum+=n/2;//全拿2和1的硬币有多少种. 
		for(int i=1;i<=n/3;++i){
			sum+=(n-3*i)/2;//既拿2和3的硬币有多少种. 
		} 
		cout<<sum<<endl;
	}
	return 0;
} 