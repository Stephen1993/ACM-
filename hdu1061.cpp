#include<iostream>
#include<cstring>
using namespace std;
int s[10],s1[10];
int main()
{
	__int64 n,m;
	scanf("%I64d",&m);
	while(m--)
	{
		scanf("%I64d",&n);
		int sum=1;
		memset(s1,0,sizeof(s));
		int i;
		for(i=0;i<n;++i)
		{
			sum=sum*n%10;
			if(s1[sum])break;
			s[i]=sum;
			s1[sum]=1;
		}
		if(i==n)
		cout<<sum<<endl;
		else
		cout<<s[(n-1)%i]<<endl;
	}
	return 0;
}