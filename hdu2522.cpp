#include<iostream>
using namespace std;
int main()
{
    int n,m,num,ture[100001];
    char sum[100001];
    sum[0]='0';
    sum[1]='.';
    cin>>n;
    while(n--)
    {
    	cin>>m;
    	num=1;
    	memset(ture,0,sizeof(ture));
		ture[0]=ture[num]=1;
    	if(m==1)
    	{
    		cout<<m<<endl;
    		continue;
	    }
	    if(m<0)
	    {
    		cout<<'-';
    		m=-m;
    	}
    	for(int i=2;;++i)
    	{
    		num=num*10;
	    	sum[i]=num/m+48;
	    	num=num%m;
	    	if(ture[num])
	    	{
    		  sum[i+1]='\0';
			  break;
		    }
	    	ture[num]=1;
	    }
	    cout<<sum<<endl;
    }
    return 0;
}