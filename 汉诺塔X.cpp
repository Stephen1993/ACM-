#include <stdio.h>
#include <math.h>
int a,b,n1;
void fuc(int x,int y,int n,__int64 m)
{
    __int64 s;
    s=pow(2.0,n-1);
    if(m<s)
     {
      int i;
      for(i=1;i<=3;i++)
      if(i!=x&&i!=y)
        break;
      fuc(x,i,n-1,m);
     }
    if(m==s)
     {
      a=x;
      b=y;
      n1=n;
     }
    if(m>s)
     {
      int i;  
      for(i=1;i<=3;i++)
      if(i!=x&&i!=y)
         break;
      fuc(i,y,n-1,m-s);
     }
}
int main()
{
   int t;
   scanf("%d",&t);
   for(int te=0;te<t;te++)
    {
      int n;
    __int64 m;
      scanf("%d%I64d",&n,&m);
      fuc(1,3,n,m);
      printf("%d %d %d\n",n1,a,b);
    }
return 0;
}
