#include<iostream>
#include<string>
using namespace std;
int main()
{
   string s;
   int n;
   while(cin>>n,n)
   {
   	  cin>>s;
   	  int l=s.size();
   	  for(int i=0;i<n;++i)
   	  {
  	   	int p=i;
  	   	int step=2*n-1-2*i;
  	   	while(p<l)
  	   	{
	   	  	cout<<s[p];
	   	  	p=p+step;
	   	  	step=2*n-step;
   	    }
      }
      cout<<endl;
   }	
   return 0;
}