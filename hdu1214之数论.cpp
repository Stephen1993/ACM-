#include<iostream>
#include<cstdio>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<map>
#include<queue>
#include<string>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=10;
int main(){
	int n;
	while(cin>>n){
		int a=n/2;
		cout<<a*(a-1)/2+(n-a)*(n-a-1)/2<<endl;
	}
	return 0;
} 
/*
�����ٵ�ʱ��ʹ��ԭ����˳��պ��෴,��ʵ�൱��ð��:1 2 3 4 5 6 7 8 9
ð�ݺ�:9 8 7 6 5 4 3 2 1,���һ��Ȧ����ʵ���Էֳ�����ð�ݿ��Խ�ʡʱ��
��ֳ����κ�����һ�γ���Ϊa,����һ��Ϊn-a;
����ʱ��Ϊtime=(a*(a-1)+(n-a)*(n-a-1))/2=(2a^2-2na+n^2-n)/2;
��Ԫһ�κ������������ϣ�����Ϊa,������Сʱ��time��a=-2n/-2*2=n/2ȡ��;
*/