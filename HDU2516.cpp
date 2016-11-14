#include<iostream>
using namespace std;
int main()
{
	__int64 num[45];
	int n;
	num[0]=2;
	num[1]=3;
	for(int i=2;i<45;i++)
	num[i]=num[i-1]+num[i-2];
	while(cin>>n,n)
	{
		int i;
		for(i=0;i<45;++i)
		{
			if(n==num[i])break;
		}
		if(i==45)
		  cout<<"First win"<<endl;
		else
		  cout<<"Second win"<<endl;
	}
    return 0;
}