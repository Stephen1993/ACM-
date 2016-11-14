#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int x[60],y[60],s[27];
	int t;
	cin>>t;
	while(t--)
	{
		for(int i=1;i<27;++i)
		 cin>>s[i];
	    memset(x, 0, sizeof(x));  
        memset(y, 0, sizeof(y));  
        y[0] = 1;  
		for(int i=1;i<27;++i)
		 {
		  for(int j=0;j<=50;++j)
           for(int k=0;k<=s[i]&&k*i+j<=50;k++)
            x[k*i+j]+=y[j];
          memcpy(y,x,sizeof(x));
          memset(x,0,sizeof(x));
	     }
	     int num=0;
	     for(int i=1;i<=50;++i)
	      num+=y[i];
         cout<<num<<endl;
	}
	return 0;
}