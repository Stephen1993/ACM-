#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int s[35]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73,79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149};
	int x[200],y[200];
	int c,n;
	cin>>c;
	while(c--)
	{
		cin>>n;
		memset(x,0,sizeof(x));
		memset(y,0,sizeof(y));
		y[0]=1;
		for(int i=0;i<35;++i)
		 {for(int j=0;j<=n;++j)
		  for(int k=0;k+j<=n;k+=s[i])
		   x[j+k]+=y[j];
	    memcpy(y,x,sizeof(x));
	    memset(x,0,sizeof(x));}
	    cout<<y[n]<<endl;
	}
	return 0;
}