#include<iostream>
using namespace std;
int s[65536]={0};
void calu()
{
	for(int i=2;i<=256;++i)
	 if(s[i]==0)
	  for(int j=2*i;j<=65535;j+=i)
	   s[j]=1;
}
int main()
{
	int n,k;
	calu();
	while(cin>>n)
	{
		k=2;
		while(s[n])
		{
			for(int i=k;i<=256;++i)
			 if(s[i]==0)
			  if(n%i==0)
			   {
   				 printf("%d*",i);
   				 k=i;
   				 n=n/i;
   				 break;
   			   }
		}
		cout<<n<<endl;
	}
	return 0;
}