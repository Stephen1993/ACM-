#include<iostream>
#include<string>
using namespace std;
int main()
{
	int t,i,j;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>s;
		if(s[0]=='-')cout<<s[0];
		bool flag=false;
		for(i=s.size()-1;i>0;i--)
		{
			if(s[i]!='0')
			 for(j=i;j>0;j--)
			 {
 				cout<<s[j];
 				flag=true;
 			 }
 			 if(flag)break;
		}
		if(s[0]!='-')cout<<s[0];
		for(j=s.size()-1-i;j>0;j--)
		cout<<'0';
		cout<<endl;
	}
	return 0;
}