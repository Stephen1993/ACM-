#include<iostream>
using namespace std;
int main()
{
	int s[121][121]={0};
	for(int i=1;i<=120;++i)
	  for(int j=1;j<=120;++j)
	    {
    		if(i==1||j==1)
    		  s[i][j]=1;
  		    if(i<j)
  		      s[i][j]=s[i][i];
            if(i==j)
              s[i][j]=s[i][j-1]+1;
            if(i>j)
              s[i][j]=s[i][j-1]+s[i-j][j];
    	}
  	int n;
  	while(cin>>n)
  	cout<<s[n][n]<<endl;
  	return 0;
}
