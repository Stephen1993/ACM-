#include<iostream>
using namespace std;
int main()
{
	int floay[101][101];
	int n,m,a,b,c;
	while(cin>>n>>m,n,m)
	{
		for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		floay[i][j]=100000;
		for(int i=1;i<=m;++i)
		{
			cin>>a>>b>>c;
			floay[a][b]=floay[b][a]=c;
		}
		for(int i=2;i<n;++i)
		for(int j=1;j<n;++j)
		for(int k=1;k<=n;++k)
		if(floay[j][i]+floay[i][k]<floay[j][k])
		  floay[j][k]=floay[j][i]+floay[i][k];
        cout<<floay[1][n]<<endl;
	}
	return 0;
}