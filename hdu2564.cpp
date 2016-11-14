#include<iostream>
using namespace std;
int main()
{
	char s[150];
	char a;
	int n;
	cin>>n;
	getchar();
	while(n--)
	{
		int word=0;
		gets(s);
		for(int i=0;s[i]!='\0';++i)
		{
			if(word==0&&s[i]!=' ')
			{
			  a=s[i];
			  if(s[i]>='a'&&s[i]<='z')
			  a=s[i]-32;
			  cout<<a;
			  word=1; 
	        }
	        if(s[i]==' ')
	        word=0;
		}
		cout<<endl;
	}
	return 0;
} 