#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int main()
{
    char name[16];
	int h0,m0,d0;
	int h1,m1,d1;
	int t,n;
	cin>>t;
	char minname[16],maxname[16];
	while(t--)
	{
		scanf("%d",&n);
		getchar();
		int hmin0=30,mmin0=70,dmin0=70;
		int hmin1=-1,mmin1=-1,dmin1=-1;
		for(int i=0;i<n;++i)
		{
			scanf("%s%d:%d:%d%d:%d:%d",name,&h0,&m0,&d0,&h1,&m1,&d1);
			if(h0<hmin0){strcpy(minname,name);hmin0=h0;mmin0=m0;dmin0=d0;}
			else
			 if(h0==hmin0)
			  if(m0<mmin0){strcpy(minname,name);hmin0=h0;mmin0=m0;dmin0=d0;}
			  else
			   if(m0==mmin0)
			    if(d0<dmin0){strcpy(minname,name);hmin0=h0;mmin0=m0;dmin0=d0;}
		    if(h1>hmin1){strcpy(maxname,name);hmin1=h1;mmin1=m1;dmin1=d1;}
			else
			 if(h1==hmin1)
			  if(m1>mmin1){strcpy(maxname,name);hmin1=h1;mmin1=m1;dmin1=d1;}
			  else
			   if(m1==mmin1)
			    if(d1>dmin1){strcpy(maxname,name);hmin1=h1;mmin1=m1;dmin1=d1;}
		}
		cout<<minname<<' '<<maxname<<endl;
	}
	return 0;
}