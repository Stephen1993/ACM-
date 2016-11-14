#include<iostream>
using namespace std;

const int MAX=1001;
int g[MAX]={0,2},f[MAX]={1,2};

void calculate(){
	for(int i=2;i<=1000;++i){
		g[i]=g[i-1]+f[i-1];
		f[i]=f[i-1]+i;
	}
}

int main(){
	int n;
	calculate();
	while(cin>>n){
		cout<<g[n]<<endl;
	}
	return 0;
}
/*
��n��ֱ�߰�ƽ��ָ�ɵ��������� f(n)=f(n-1)+n=n(n+1)/2+1;
�ڰѿռ�ָ�Ϊ������������ʱ�򣬵�n��ƽ����ǰ(n-1)��ƽ���ཻ��
�������湲�ߣ����Դ�ʱ��ƽ����ǰ(n-1)��ƽ����(n-1)�����ߡ�
��Щ���߰ѵ�n��ƽ��ָ�Ϊf(n-1)�������������ƽ�潫ԭ�пռ�һ��Ϊ����
��������f(n-1)���ռ䣬�õ��ƹ�ʽ��g(n)=g(n-1)+f(n-1)=(n^3+5n)/6+1��
*/