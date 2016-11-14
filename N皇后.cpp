#include<iostream>
using namespace std;
int n,num;
int s[11][11],sum[11];
void dfs(int x,int y)
{
	int xx=x,yy=y;
	if(s[x][y])return;
	if(x==n){num++;return;}
	while(xx<=n){s[xx++][yy]++;}
	xx=x;yy=y;
	while(xx<=n&&yy>0){s[xx++][yy--]++;}
	xx=x;yy=y;
	while(xx<=n&&yy<=n){s[xx++][yy++]++;}
	for(int i=1;i<=n;++i)
	   dfs(x+1,i);
    xx=x;yy=y;
    while(xx<=n){s[xx++][yy]--;}
	xx=x;yy=y;
	while(xx<=n&&yy>0){s[xx++][yy--]--;}
	xx=x;yy=y;
	while(xx<=n&&yy<=n){s[xx++][yy++]--;}
	return;
}
int main()
{
	for(int i=1;i<11;++i)
	 {
       num=0;
       n=i;
	   for(int j=1;j<=i;++j)
	   {
   		  memset(s,0,sizeof(s));
   		  dfs(1,j);
   	   }
   	   sum[i]=num;
     }
     int m;
     while(cin>>m,m)
     cout<<sum[m]<<endl;
     return 0;
}