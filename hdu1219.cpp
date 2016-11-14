#include<iostream>
#include<cstring>
using namespace std;
char s[100002];
int main()
{
	int p[256];
	while(gets(s))
	{
		memset(p,0,sizeof(p));
		int l=strlen(s);
		for(int i=0;i<l;++i)
		 p[s[i]]++;
	    for(int i=97;i<123;++i)
	    printf("%c:%d\n",i,p[i]);
	    cout<<endl;
	}
	return 0;
}