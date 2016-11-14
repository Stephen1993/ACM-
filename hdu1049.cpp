#include<iostream>
using namespace std;
int main()
{
	int n,u,d;
	while(cin>>n>>u>>d,n,u,d)
	{
		int num=(n-u)/(u-d);
		int sum=(n-u)-num*(u-d)+u;
		num*=2;
	    while(1)
	    {
    		num++;
    		sum=sum-u;
    		if(sum<=0)
    		break;
    		num++;
    		sum=sum+d;
    	}
    	cout<<num<<endl;
	}
	return 0;
}