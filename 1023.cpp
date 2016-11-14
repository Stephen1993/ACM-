#include<iostream>
using namespace std;
int s[101][100]={0};
void catalan()
{
	s[1][0]=1;
	int len=1;
	for(int i=2;i<=100;++i)
      {
      	 int r=0;
	     for(int j=0;j<len;++j)
	       {
		     s[i][j]=s[i-1][j]*(4*i-2)+r;
		     r=s[i][j]/10;
		     s[i][j]=s[i][j]%10;
           }
         while(r)
           {
           	  s[i][len]=r%10;
           	  r=r/10;
           	  len++;
           }
         r=0;
         for(int j=len-1;j>=0;j--)
           {
           	  s[i][j]=s[i][j]+r*10;
           	  r=s[i][j]%(i+1);
           	  s[i][j]=s[i][j]/(i+1);
           }
         while(!s[i][len-1])
           len--;
      }
}
int main()
{
	int n;
	catalan();
	while(cin>>n)
	{
		int k;
		for(k=99;!s[n][k];k--);
		  for(;k>=0;k--)
		    cout<<s[n][k];
        cout<<endl;
	}
	return 0;
}