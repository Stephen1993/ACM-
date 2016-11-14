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

const int MAX=100001;
int Left[MAX],Right[MAX];//求和第i个木板连续的高于或等于它的最左边木板和最右边木板,i,j,然后面积s=(j-i+1)*s[i],求最大的s即可. 
__int64 s[MAX];

int main(){
	int n;
	while(cin>>n,n){
		for(int i=0;i<n;++i){
			scanf("%I64d",&s[i]);
			Left[i]=Right[i]=i;//初始化连续的高于或等于它的木板只有它本身.
		}
		for(int i=1;i<n;++i){//求和第i个木板连续的高于或等于它的最左边的木板. 
			while(Left[i]-1>=0 && s[Left[i]-1]>=s[i])Left[i]=Left[Left[i]-1];
		}
		for(int i=n-2;i>=0;--i){//求和第i个木板连续的高于或等于它的最右边的木板.
			while(Right[i]+1<n && s[Right[i]+1]>=s[i])Right[i]=Right[Right[i]+1];
		}
		__int64 sum=0;
		for(int i=0;i<n;++i){
			if(s[i]*(Right[i]-Left[i]+1)>sum)sum=s[i]*(Right[i]-Left[i]+1);
		}
		cout<<sum<<endl;
	}
	return 0;
}