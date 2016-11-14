#include<iostream>
#include<stack>
using namespace std;
int main()
{
	int n;
	char in[10],out[10],s1[20];
	while(cin>>n)
	{
		memset(s1,0,sizeof(s1));
		stack<char>s;
		cin>>in>>out;
		int j=0,k=0;
		for(int i=0;i<n;++i)
		{
			s.push(in[i]);
			s1[k]=1;
			k++;
			while(!s.empty())
			{
				if(s.top()==out[j])
				{
                    s1[k]=0;
					k++;
					j++;
					s.pop();
				}
				else
				  break;
			}
		}
	   if(s.empty())
	   {
	   	   cout<<"Yes."<<endl;
   		   for(int i=0;i<2*n;++i)
   		   if(s1[i])
   		   cout<<"in"<<endl;
   		   else
   		   cout<<"out"<<endl;
   	   }
   	   else
   	     cout<<"No."<<endl;
       cout<<"FINISH"<<endl;
  }
  return 0;
}