#include<iostream>
#include<string.h>
using namespace std;
int zhuanhuan(char a[])
{
	if(strcmp(a,"one")==0)return 1;
	if(strcmp(a,"two")==0)return 2;
	if(strcmp(a,"three")==0)return 3;
	if(strcmp(a,"four")==0)return 4;
	if(strcmp(a,"five")==0)return 5;
	if(strcmp(a,"six")==0)return 6;
	if(strcmp(a,"seven")==0)return 7;
	if(strcmp(a,"eight")==0)return 8;
	if(strcmp(a,"night")==0)return 9;
	return 0;
}
int main()
{
	char A[20],B[20];
	char c[10];
	while(gets(A))
	{
		int num1=0;
		int num2=0;
		bool ture=true;
		for(int i=0,j=0;A[i]!='=';++i,j++)
		{
			if(A[i]!=' '&&A[i]!='+')
			c[j]=A[i];
			if(A[i]=='+')
			ture=false;
			if(A[i+1]==' '&&ture)
			{
				c[j+1]='\0';
				num1=num1*10+zhuanhuan(c);
				j=-1;
			}
			if(A[i+1]==' '&&!ture)
			{
				c[j+1]='\0';
				num2=num2*10+zhuanhuan(c);
				j=-1;
			}
		}
		if(num1==0&&num2==0)
			break;
		else
			cout<<num1+num2<<endl;
	}
	return 0;
}