#include<iostream>
#include <algorithm>
using namespace std;
bool cmp(int a,int b)
{
  return a>b;
}  
int main()
{
    int m,n,num;
    int s[20000][2],c[20000];
    int p1[101][2],p2[101][2];
   // while(cin>>m>>n)
    //{
    	cin>>m>>n;
    	for(int i=0;i<m;++i)
    	cin>>s[i][0]>>s[i][1];
    	for(int i=0;i<n;++i)
    	cin>>p1[i][0]>>p1[i][1]>>p2[i][0]>>p2[i][1];
    	for(int i=0;i<m;++i)
    	   {
    	   	 num=0;
		     for(int j=0;j<n;++j)
		        if(s[i][0]>=p1[j][0]&&s[i][0]<=p2[j][0]&&s[i][1]>=p1[j][1]&&s[i][1]<=p2[j][1])
		        {
        			num=2*(p2[j][0]-p1[j][0])+2*(p2[j][1]-p1[j][1]);
        			break; 
        		}
        		c[i]=num;
           }
           sort(c,c+m,cmp);
           for(int i=0;i<m;++i)
		   cout<<c[i]<<endl; 
    // }
     return 0;
} 