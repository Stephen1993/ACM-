#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	__int64 a,b;
    while(cin>>hex>>a>>b)
    {
    	if(a+b<0)
    	cout<<'-'<<hex<<setiosflags(ios::uppercase)<<-(a+b)<<endl;
    	else
    	cout<<hex<<setiosflags(ios::uppercase)<<(a+b)<<endl;
    }
    return 0;
}