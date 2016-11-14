#include<iostream>
using namespace std;
int main()
{
	int s[10000]={0};
	s[2]=1;
	bool ture;
	for(int i=3;i<10000;i+=2)
	{
	  ture=false;
	  for(int j=3;j*j<=i;j+=2)
	  if(i%j==0)
	  {
  		ture=true;
  		break;
  	  }
  	  if(!ture)s[i]=1;
	}
	int n;
	while(cin>>n,n)
	{
		int num=0;
		for(int i=2;i<=n/2;++i)
		if(i!=n-i&&s[i]==1&&s[n-i]==1)
		num++;
		cout<<num<<endl;
	}
	return 0;
}