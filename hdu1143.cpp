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
nΪ����ʱ��ȻΪ0,��Ϊ����һ���޷�ʹ�ø�Ϊ3,
n��ż��ʱ���Կ���n-2��������2��,����f(2)*f(n-2),
Ҳ�ɿ���n-4�������ĸ�,���Ǵ�ʱֻ���ĸ����ǲ�����������
��һ��,�м�ǡ����ɳɹ����ֲ���f(2)*f(n-2)�ظ�,�����ظ�,
����n-6������6��....ͬ��,
f(n)=f(n-2)*2+f(n-4)*2+f(n-6)*2+...=f(n-2)*2+f(n-4)+f(n-2)-f(2)*f(n-4)=4*f(n-2)-f(n-4).
*/ 