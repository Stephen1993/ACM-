#include<iostream>
#include<string>
#include<set>
using namespace std;
int main()
{
   set<string>s1;
   set<string>s2;
   set<string>::iterator it;
   string a,b;
   int n;
   while(cin>>n,n)
   {
   	 for(int i=0;i<n;++i)
   	 {
 	   	cin>>a>>b;
 	   	s1.insert(a);
 	   	s1.insert(b);
 	   	s2.insert(b);
     }
     if(s1.size()-s2.size()==1)
      cout<<"Yes"<<endl;
     else
      cout<<"No"<<endl;
     s1.clear();
     s2.clear();
   }
   return 0;	
}