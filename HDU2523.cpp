#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int main()
{
	int sum[2001],num;
	int c,n,k,x[1001];
	cin>>c;
	while(c--)
	{
		num=0;
	    memset(sum,0,sizeof(sum));
		cin>>n>>k;
		cin>>x[0];
		for(int i=1;i<n;++i)
		{
			cin>>x[i];
			for(int j=0;j<i;++j)
			{
				sum[abs(x[i]-x[j])]=1;
			}
		}
		for(int i=0;i<2001;++i)
		{
			if(sum[i])
			num++;
			if(num==k)
			{
				cout<<i<<endl;
				break;
			}
		}
	}
	return 0;
}