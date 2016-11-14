#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char a[51];
	int t;
	int x1,x2,x3,x4,la;
	cin>>t;
	while(t--)
	{   
	    cin>>a;
		x1=x2=x3=x4=0;
		la=strlen(a);
		if(la<8||la>16)
		{
			cout<<"NO"<<endl;
			continue;
		}
		for(int i=0;i<la;++i)
		{
			if('A'<=a[i]&&a[i]<='Z')
			x1=1;
			else
			  if(a[i]>='a'&&a[i]<='z')
			  x2=1;
			  else
                if(a[i]>='0'&&a[i]<='9')
                x3=1;
                else
                x4=1;
		}
		if(x1+x2+x3+x4>2)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
} 