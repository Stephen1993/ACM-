#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
void jiecheng(int n)
{
	long x[10000];
	x[0]=1;
	int m=0,c;
	for(int i=1;i<=n;i++)
	{
	 c=0;
	 for(int j=0;j<=m;j++)
	 {
	  x[j]=x[j]*i+c;
	  c=x[j]/10000;
	  x[j]=x[j]%10000;
	 }
	 if(c>0)
	 {
 		m++;
 		x[m]=c;
 	 }
    }
    cout<<x[m];
    for(int i=m-1;i>=0;i--)
        cout<<setfill('0')<<setw(4)<<x[i];
    m=m*4+log10(x[m])+1;
    
    cout<<endl<<"Î»Êý:"<<m<<endl;
}
int main()
{
	int n;
	while(cin>>n)
	jiecheng(n);
	return 0;
}