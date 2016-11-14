#include<iostream>
using namespace std;
int main()
{
	int num[5001];
	int n,a,b,m;
	cin>>n;
	while(n--)
	{
		cin>>a>>b;
		int MAX=0;
		memset(num,0,sizeof(num));
		for(int i=a;i<=b;++i)
		{
		  for(int j=1;j*j<=i;++j)
		  {
			if(i%j==0)
			{
				if(j==i/j)
				num[i]++;
				else
				num[i]+=2;
			}
		 }
		 if(MAX<num[i])
		 {
	 	   m=i;
		   MAX=num[i];
         }
	  }
	  cout<<m<<endl;
   }
   return 0;
}