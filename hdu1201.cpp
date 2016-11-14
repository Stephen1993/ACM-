#include<iostream>
using namespace std;
int num;
int panduan(int m)
{
   return (m%4==0&&m%100!=0||m%400==0);	
}
int main()
{
	int a,b,n,c;
	cin>>n;
	while(n--)
	{
		num=0;
		scanf("%d-%d-%d",&a,&b,&c);
		if(panduan(a)&&b==2&&c==29&&!panduan(a+18))
		{
			cout<<"-1\n";
			continue;
		}
		for(int i=a;i<=a+18;i++)
	     if(panduan(i))num++;
	    if(b>2&&panduan(a))num--;
	    if(b<=2&&c<=28&&panduan(a+18))num--;
		cout<<18*365+num<<endl;
	}
	return 0;
}