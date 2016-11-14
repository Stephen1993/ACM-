#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char s[10001];
	int t,num[10001];
	cin>>t;
	while(t--)
	{
		memset(num,0,sizeof(num));
		cin>>s;
		for(int i=0,j=0;s[i]!='\0';++i)
		{
			if(s[i]==s[i+1])
			  num[j]++;
	        else
	          j=i+1;
		}
		for(int i=0;s[i]!='\0';++i)
		{
			if(num[i]>0)
			{
			  cout<<num[i]+1;
			  cout<<s[i];
			  i=i+num[i];
			  continue;
	        }
	        cout<<s[i];
		}
		cout<<endl;
	}
	return 0;
}