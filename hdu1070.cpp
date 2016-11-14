#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
typedef struct
{
	string name;
	double value_;
	int height;
}point;
point s[102];
bool cmp(point a,point b) 
{
	if(a.value_!=b.value_)
	return a.value_>b.value_;
	return a.height>b.height;
}
int main()
{
	int n,p,v,t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;++i)
		{
			cin>>s[i].name>>p>>v;
			s[i].height=v;
			v=v-v%200;
			if(v>1000)
			s[i].value_=1000*1.0/p;
			else
			s[i].value_=v*1.0/p;
		}
		sort(s,s+n,cmp);
		cout<<s[0].name<<endl;
	}
	return 0;
}