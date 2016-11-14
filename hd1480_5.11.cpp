#include<iostream>
#include<limits.h>
#include<math.h>
#include<float.h>
using namespace std;
int main()
{
    __int64 num[27]={0},one[27],two[27];
    one[2]=0;
    two[2]=0;
    for(int i=3;i<26;i++)
    {
        one[i]=one[i-1]+two[i-1]*4+((__int64)pow(2,i-1)-2)*6+((__int64)pow(2,i-2)-1)*4;
        two[i]=one[i-1]*2+two[i-1]*4+((__int64)pow(2,i-1)-2)*9;
        num[i]=one[i]*2+two[i]*4;
        cout<<"N="<<i<<':'<<' '<<num[i]<<endl;
    }
    return 0;
}
