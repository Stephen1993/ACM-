#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;
int main()
{
	int x[500],y[500],a[10],b[10],n,k,t;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		for(int i=0;i<k;++i)
		cin>>a[i]>>b[i];
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		y[0]=1;
		for(int i=0;i<k;++i)
		 {
		  for(int j=0;j<=n;++j)
		   for(int t=0;t+j<=n&&t<=a[i]*b[i];t=t+a[i])
		    x[t+j]=y[j]+x[t+j];
	      for(int j=0;j<=n;++j)
	        y[j]=x[j],x[j]=0;
		 }
	   cout<<y[n]<<endl;
	}
	return 0;
}