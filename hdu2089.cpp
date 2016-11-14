#include<iostream>
#include<string.h>
using namespace std;
bool s[1000001];
bool calculate(int a)
{
	while(a)
	{
		if(a%10==4||a%100==62)
		return false;
		a=a/10;
	}
	return true;
}
int main()
{
	memset(s,true,sizeof(s));
	for(int i=4;i<1000000;++i)
	s[i]=calculate(i);
	int n,m;
	while(cin>>n>>m,n||m)
	{
		int num=0;
		for(int i=n;i<=m;++i)
		if(s[i])num++;
		cout<<num<<endl;
	}
	return 0;
}