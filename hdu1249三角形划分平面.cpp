#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#define INF 999999999
using namespace std;
const int MAX=10001;
int s[MAX]={0,2};
int main(){
	for(int i=2;i<=10000;++i){
		s[i]=s[i-1]+6*(i-1);
	}
	int n,t;
	cin>>t;
	while(t--){
		cin>>n;
		cout<<s[n]<<endl;
	}
	return 0;
}
//http://blog.sina.com.cn/s/blog_83ccc39d0100z3l9.html