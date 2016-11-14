#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;
typedef struct 
{
	int p;
	int h;
}point;
point s[1001];
bool cmp(point a,point b)
{
	return a.p<b.p;
}
int main()
{
	int c,m,n;
	cin>>c;
	while(c--)
	{
		cin>>n>>m;
		double v=0,max=0;
		for(int i=0;i<m;++i)
		cin>>s[i].p>>s[i].h;
	    sort(s,s+m,cmp);
	    for(int i=0;i<m;++i)
	    if(v+s[i].p*s[i].h<=n)
	    {
    		max+=s[i].h;
    		v+=s[i].p*s[i].h;
    	}
    	else
    	{
	    	max+=(n-v)/s[i].p;
	    	break;
	    }
	    cout<<fixed<<setprecision(2)<<max<<endl;
	}
	return 0;
}