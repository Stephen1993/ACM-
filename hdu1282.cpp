#include<iostream>
using namespace std;
__int64 jiaohuan(__int64 n)
{
	int x=0;
	while(n>0)
	{
		x=x*10+n%10;
		n=n/10;
	}
	return x;
}
int main()
{
	__int64 n,m,s[2000];
	while(cin>>n)
	{
		int num=0;
		s[num]=n;
		m=jiaohuan(n);
		while(m!=n)
		{
			n+=m;
			m=jiaohuan(n);
			s[++num]=n;
		}
		cout<<num<<endl<<s[0];
		for(int i=1;i<=num;++i)
		cout<<"--->"<<s[i];
		cout<<endl;
	}
	return 0;
}