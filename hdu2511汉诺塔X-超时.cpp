#include<iostream>
using namespace std;
__int64 num,m;
bool ture;
void move(int x1,int A,int B)
{
	num++;
	if(num==m)
	{
		ture=true;
		cout<<x1<<' '<<A<<' '<<B<<endl;
	}
}
void digui(__int64 n,int a,int b,int c)
{
	if(ture)return;
	if(n==1)
	{
	   move(n,a,c);	
    }
 else
 {
	digui(n-1,a,c,b);
	move(n,a,c);
	if(ture)return;
	digui(n-1,b,a,c);
  }
}
int main()
{
	__int64 t,n;
	cin>>t;
	while(t--)
	{
		num=0;
		ture=false;
		cin>>n>>m;
		digui(n,1,2,3);
	}
	return 0;
}