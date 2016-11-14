#include<iostream>
using namespace std;
int main()
{
	char s[15];
	int n;
	cin>>n;
	while(n--)
	{
		int la=0;
		int lb=0;
		int num=0;
		int sum=1;
		int m=0;
		cin>>s;
		for(int i=2;s[i]!='\0';++i)
		{
			if(s[i]=='(')la=i;
			if(s[i]==')')lb=i;
		}
		if(la==0)
		for(int i=2;s[i]!='\0';++i)
		{
			num=num*10+s[i]-'0';
			sum=sum*10;
		}
		else
		{
			for(int i=la+1;s[i]!=')';++i)
			{
				num=num*10+s[i]-'0';
				sum=sum*10;
			}
			if(la!=0)
			sum=sum-1;
			for(int i=2;i<la;++i)
			m=m*10+s[i]-'0';
		}
		num=m*sum+num;
		while(la-2&&la)
		{
			sum=sum*10;
			la--;
		}
		int a=sum;
		int b=num;
		int c;
		while(b)
		{   c=b;
			b=a%b;
			a=c;
		}
		cout<<num/a<<'/'<<sum/a<<endl;
	}
	return 0;
}