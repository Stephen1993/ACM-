#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>m;
	while(m--)
	{
	   cin>>n;
	   cout<<2*n*n-n+1<<endl;//f(n)=f(n-1)+4n-3����ÿ������һ���ߣ��������ӵ�n���ߣ�������n-1�����㣬������n���ռ䣬���Ϊ����ƽ����..... 
    }
	return 0;
} 