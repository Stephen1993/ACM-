#include<iostream>
#include<string.h>
using namespace std;
char A[50000],B[50000];
void jisuan()
{
	int sum[80000]={0};
	int la,lb,num=0,c=0;
	la=strlen(A);
	lb=strlen(B);
	for(int i=la-1,k1=0;i>=0;--i,++k1)
	   {
	   num=0;
	   for(int j=lb-1,k2=0;j>=0;--j,++k2)
          {
          	sum[k1+k2]=(A[i]-'0')*(B[j]-'0')+num+sum[k1+k2];
          	num=sum[k1+k2]/10;
          	sum[k1+k2]=sum[k1+k2]%10;
          	c=k1+k2;
          }
       }
       if(num>0)
       {
       	c=c+1;
       	sum[c]=num;
       }
       for(int k=c;k>=0;--k)
       printf("%d",sum[k]);
       cout<<endl;
}
int main()
{
	while(scanf("%s%s",A,B)!=EOF)
	{
		jisuan();
	}
	return 0;
}