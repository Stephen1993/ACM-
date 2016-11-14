#include<iostream>
using namespace std;
int main()
{
	int t,n,m;
	cin>>t;
	while(t--)
	{
	    int k=0;
		while(cin>>n>>m,n||m)
		{
			
			int num=0;
			for(int i=1;i<n;++i)
			  for(int j=i+1;j<n;++j)
			    if((i*i+j*j+m)%(i*j)==0)
			       num++;
            cout<<"Case "<<++k<<": "<<num<<endl;
		}
		if(t)
		cout<<endl;
	}
	return 0;
}