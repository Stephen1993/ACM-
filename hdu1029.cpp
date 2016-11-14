#include<iostream>
using namespace std;
int s[1000000];
int main()
{
	int n,a;
	while(scanf("%d",&n)!=EOF)
	{
		int sum;
		memset(s,0,sizeof(s));
		for(int i=0;i<n;++i)
		{
		  scanf("%d",&a);//×¢ÒâÒªÓÃscanf; 
		  s[a]++;
		  if(s[a]>=(n+1)/2)
		  {
  			sum=a;
		  }
		}
		printf("%d\n",sum);
	}
	return 0;
}