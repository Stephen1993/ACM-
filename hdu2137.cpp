#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char s[82];
	int n;
	while(scanf("%s%d",s,&n)!=EOF)
	{
		int l=strlen(s);
		n=n%8;
		if(n==0)cout<<s<<endl;
		else
		if(n==1||n==-7)
		{
			for(int i=l-1;i>=0;i--)
			 {
			  for(int j=i;j>0;j--)
			   cout<<' ';
		      cout<<s[i]<<endl;
		     }
		}
		else
		if(n==2||n==-6)
		{
			for(int i=l-1;i>=0;i--)
			 {
			  for(int j=l/2;j>0;j--)
			   cout<<' ';
		      cout<<s[i]<<endl;
		     }
		}
		else
		if(n==3||n==-5)
		{
			for(int i=l-1;i>=0;i--)
			 {
			  for(int j=l-1-i;j>0;j--)
			   cout<<' ';
		      cout<<s[i]<<endl;
		     }
		}
		else
		if(n==4||n==-4)
		{
			for(int i=l-1;i>=0;i--)
			  cout<<s[i];
            cout<<endl;
		}
		else
		if(n==5||n==-3)
		{
			for(int i=l-1;i>=0;i--)
			 {
			  for(int j=i;j>0;j--)
			   cout<<' ';
		      cout<<s[l-1-i]<<endl;
		     }
		}
		else
		if(n==6||n==-2)
		{
			for(int i=l-1;i>=0;i--)
			 {
			  for(int j=l/2;j>0;j--)
			   cout<<' ';
		      cout<<s[l-1-i]<<endl;
		     }
		}
		else
		if(n==7||n==-1)
		{
			for(int i=l-1;i>=0;i--)
			 {
			  for(int j=l-1-i;j>0;j--)
			   cout<<' ';
		      cout<<s[l-1-i]<<endl;
		     }
		}
	}
	return 0;
}