#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char s[2000];
	int n,i,j,t;
	while(cin>>s>>n)//scanf("%s%d",s,&n)!=EOF
	{
        j=strlen(s);
        t=0;
		for(i=0;i<j;++i)
		{
			t=t*10+(s[i]-'0');
			t=t%n;
		}
		cout<<t<<endl;
	}
	return 0;
}