#include<iostream>
using namespace std;
int main()
{
    int t,n,m;
    cin>>t;
    __int64 num;
    while(t--)
    {
        cin>>n>>m;
        num=1;
        for(int i=1;i<=m;++i)
        num=num*(n-i+1)/i;
        cout<<num<<endl;
    }
    return 0;
}