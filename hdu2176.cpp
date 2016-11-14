#include<iostream>
using namespace std;	
int s[200005];
int main()
{
   int m;
   while(cin>>m,m)
   {
   	  int x=0,flag=1;
   	  for(int i=0;i<m;i++)
   	  {
  	   	 scanf("%d",&s[i]);
  	   	 x^=s[i];
      }
      for(int i=0;i<m;++i)
      {
      	if(s[i]>(x^s[i]))
      	{
	      	if(flag)
	      	{
	      		cout<<"Yes"<<endl;
	      		flag=0;
	      	}
	      	cout<<s[i]<<' '<<(x^s[i])<<endl;
        }
      }
      if(flag)
      cout<<"No"<<endl;
   }
   return 0;
}