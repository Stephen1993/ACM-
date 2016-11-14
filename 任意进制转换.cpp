#include<iostream>
using namespace std;
void sysconvert(char a[],int d1,int d2)
{
	__int64 num=0;
	__int64 sum=0;
	char b[1000];
	for(int i=0;a[i]!='\0';++i)
	{
		if(a[i]>='0'&&a[i]<='9')
		num=num*d1+a[i]-'0';
		else
		num=num*d1+a[i]-'A'+10;
	}
	int k=0;
	while(1)
	{
		sum=num%d2;
		if(sum>=0&&sum<=9)
		b[k++]=sum+'0';
		else
		b[k++]=sum-10+'A';
		num=num/d2;
		if(num==0)
		break;
	}
	int temp;
	for(int i=0;i<k/2;++i)
	{
		temp=b[i];
		b[i]=b[k-1-i];
		b[k-1-i]=temp;
	}
	b[k]='\0';
	cout<<b<<endl;
}
int main()
{
	char a[1000];
	int d1,d2;
	while(cin>>a>>d1>>d2)
	sysconvert(a,d1,d2);
	return 0;
}