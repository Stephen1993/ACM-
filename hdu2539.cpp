#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char people[200];
	char s[2][100];
	int num;
	int sum[2];
	int n;
	while(cin>>n,n)
	{
		getchar();
		num=0;
		sum[0]=sum[1]=0;
		for(int i=0;i<n;++i)
		{
			if(i%2==0)
			num++;
			gets(people);
			if(people[strlen(people)-6]=='o'&&people[strlen(people)-7]=='n'&&people[strlen(people)-8]==' ')
			  s[i%2][num]='X';
			else
			{
			  s[i%2][num]='O';
			  sum[i%2]++;
	        }
		}
		if(n%2==1)
		s[1][num]='-';
		for(int i=1;i<=num;++i)
		cout<<i<<' ';
		cout<<"Score"<<endl;
		for(int i=1;i<=num;++i)
		cout<<s[0][i]<<' ';
		cout<<sum[0]<<endl;
		for(int i=1;i<=num;++i)
		cout<<s[1][i]<<' ';
		cout<<sum[1]<<endl;
	}
	return 0;
}