#include<iostream>
using namespace std;
int main()
{
	int n,a,num[30001],j,i;
	while(scanf("%d",&n)!=EOF)
	{
		j=0;
		for(int k=0;k<n;++k)
		{
			scanf("%d",&a);
			for(i=0;i<j;++i)
			{
				if(a<=num[i])
				{num[i]=a;
				break;}
			}
			if(i==j)num[j++]=a;
		}
		cout<<j<<endl;
	}
	return 0;
}