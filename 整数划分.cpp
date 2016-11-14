#include<iostream>
using namespace std;
int n,m,num;
int f(int a,int b)
{
	if(a==b||b==1)
	return 1;
	int c=a-b;
	for(int i=1;i<=b&&i<=c;i++)
	{
		num+=f(c,i);
	}
	return 0;
}
int main()
{
	while(cin>>n>>m)
	{
		num=0;
		f(n,m);
		cout<<num<<endl;
	}
	return 0;
}