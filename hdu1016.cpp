#include<iostream>
using namespace std;
int n,s[21],biaoji[21];
bool susu(int a)
{
	for(int i=2;i*i<=a;++i)
	if(a%i==0)
	return false;
	return true;
}
void dfs(int m)
{
	if(m==n+1&&susu(s[m-1]+1))
	{
		cout<<s[1];
		for(int i=2;i<=n;++i)
		   cout<<' '<<s[i];
		cout<<endl;
		return;
	}
	for(int i=2;i<=n;++i)
	{
		if(susu(s[m-1]+i)&&biaoji[i]==0)
		{
			biaoji[i]=1;
			s[m]=i;
			dfs(m+1);
			biaoji[i]=0;
		}
	}
	return;
}
int main()
{
	int k=0;
	while(cin>>n)
	{
		if(n%2==1)continue;
		cout<<"Case "<<++k<<':'<<endl;
		s[1]=1;
		memset(biaoji,0,sizeof(biaoji));
		dfs(2);
		cout<<endl;
	}
	return 0;
}