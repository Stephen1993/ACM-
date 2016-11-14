#include<iostream>
using namespace std;
int main()
{
	__int64 sum[1000]={0};
	int x;
	int n;
	cin>>n;
	while(n--)
	{
		cin>>x;
		for(int i=1;;++i)
		{
		  sum[i]=sum[i-1]+i*i*i;
		  if(x<=sum[i])
		  {
		    cout<<i<<endl;
		    break;
		  }
        }
	}
	return 0;
}