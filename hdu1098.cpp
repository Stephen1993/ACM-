#include<iostream>
using namespace std;
int main()
{
	int k,a;
	while(cin>>k)
	{
		if(k%65==0)
		{
			cout<<"no"<<endl;
			continue;
		}
		int i;
		for(i=1;i<65;++i)
		{
			if((18+k*i)%65==0)
				break;
		}
		if(i==65)
		cout<<"no"<<endl;
		else
		cout<<i<<endl;
	}
	return 0;
}