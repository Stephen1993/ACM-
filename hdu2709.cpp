/*
分析:假定所要求的结果为s[n],则可直接在s[n-1]后面+1
所以s[n]+=s[n-1];
若n为偶数且a+b+c..+d=n且a,b,c,d...>=2,则s[n]+=s[n/2];//把2看成1，就有n/2个1，就转化为s[n/2]
所以：n为奇数 =〉s[n]=s[n-1]
n为偶数 =〉s[n]=s[n-1]+s[n/2] 
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

const int MAX=1000000+10;
const int mod=1000000000;
int s[MAX];

int main(){
	s[1]=1;
	for(int i=2;i<MAX;++i){
		s[i]=s[i-1];
		if(i%2 == 0)s[i]+=s[i/2];
		s[i]%=mod;
	}
	int n;
	while(cin>>n){
		cout<<s[n]<<endl;
	}
	return 0;
}