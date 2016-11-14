#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#define INF 99999999
using namespace std;
const int MAX=31;
int s[31]={1,0,3};
int main(){
	for(int i=4;i<=30;++i){
		s[i]=4*s[i-2]-s[i-4];
	}
	int n;
	while(cin>>n,n!=-1){
		cout<<s[n]<<endl;
	}
	return 0;
}
/*******************************************************************************
n为奇数时显然为0,因为增加一个无法使得高为3,
n是偶数时可以看成n-2个增加了2个,所以f(2)*f(n-2),
也可看成n-4增加了四个,但是此时只有四个的那部分左右两边
是一个,中间恰好组成成功这种不和f(2)*f(n-2)重复,其余重复,
看成n-6个增加6个....同理,
f(n)=f(n-2)*2+f(n-4)*2+f(n-6)*2+...=f(n-2)*2+f(n-4)+f(n-2)-f(2)*f(n-4)=4*f(n-2)-f(n-4).
*/ 