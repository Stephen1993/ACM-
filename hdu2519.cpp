/*#include<iostream>
using namespace std;
int num=0;
int s[24][24],sum[24];
void dfs(int n)
{
	if(n>24)return;
	else
	{
		for(int i=0;i<2;++i)
		{
			s[1][n]=i;
			num+=i;
			for(int j=2;j<=n;++j)
			{
				s[j][n-j+1]=s[j-1][n-j+1]^s[j-1][n-j+2];
				num+=s[j][n-j+1];
			}
			if(n*(n+1)/2==num*2)
			{
				sum[n]++;
			}
			dfs(n+1);
			for(int i=1;i<=n;++i)
			num-=s[i][n-i+1];
		}
	}
	return;
}
int main()
{
  memset(sum,0,sizeof(sum));
  memset(s,0,sizeof(s));
  dfs(1);
  for(int i=1;i<25;i++)
  cout<<sum[i]<<' ';
  cout<<endl;
  return 0;
}*/
#include<iostream>
using namespace std;
int main()
{
   int n;
   int s[25]={0,0,0,4,6,0,0,12,40,0,0,171,410,0,0,1896,5160,0,0,32757,59984,0,0,431095,822229};
   while(cin>>n,n)
   {
   	 cout<<n<<' '<<s[n]<<endl;
   }
   return 0;	
}
//ÉîËÑ+´ò±í 