#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<queue>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=10001;
int main(){
	int n,first,last,a,x;
	while(cin>>n,n){
		int sum=-1,temp=-1;
		cin>>a;
		first=temp=sum=x=last=a;
		for(int i=1;i<n;++i){
			scanf("%d",&a);
			if(temp>0)temp=temp+a;//temp表示前i个数包括第i个数在内的最大子序列. 
			else temp=x=a;
			if(temp>sum){
				sum=temp;
				last=a;
				first=x;
			}
		}
		if(sum<0){sum=0;last=a;}
		cout<<sum<<' '<<first<<' '<<last<<endl;
	}
	return 0;
}