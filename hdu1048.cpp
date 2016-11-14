#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	string a="VWXYZABCDEFGHIJKLMNOPQRSTU",
	       b="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string start,end_;
	char s[200];
	while(cin>>start,start!="ENDOFINPUT")
	{
		getchar();
		gets(s);
		cin>>end_;
		int l=strlen(s);
		for(int i=0;i<l;++i)
		 if(s[i]>='A'&&s[i]<='Z')
		  for(int j=0;j<51;j++)
		   if(s[i]==b[j]){s[i]=a[j];break;}
	   cout<<s<<endl;
	}
	return 0;
}