#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=201;
int sum[MAX];
int main(){
	int t,a,b,n;
	cin>>t;
	while(t--){
		memset(sum,0,sizeof sum);
		cin>>n;
		for(int i=0;i<n;++i){
			cin>>a>>b;
			a=(a+1)>>1;
			b=(b+1)>>1; 
			if(a>b){
				swap(a,b);
			}
			for(int j=a;j<=b;++j){
				sum[j]++;
			}
		}
		int num=0;
		for(int i=1;i<=200;++i){
			num=max(num,sum[i]);
		}
		cout<<num*10<<endl;
	}
	return 0;
}