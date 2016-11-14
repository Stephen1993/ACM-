#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n,n)
	{
		int k=0;
		for(int i=0;i<8;++i)
		 {
 			k+=((n>>i)&1);
 			if(k==1)
 			{
			   cout<<pow(2,i)<<endl;
			   break; 	
		    }
 		 }
	}
	return 0;
}