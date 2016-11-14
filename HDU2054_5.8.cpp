#include<iostream>
#include<string>
using namespace std;
void change_back(string &str)
{
	int l=str.size()-1;
	while(str[l]=='0')
	l--;
	while(str[l]=='.')
	l--;
	str.erase(l+1);
	//cout<<"back:"<<str<<endl;
}
void change_front(string &str)
{
	int la=0;
	int lb=0;
	if(str[0]=='-')
	{
	  la++;
	  lb=la;
    }
	while(str[la]=='0')
	la++;
	str.erase(lb,la-lb);
	//cout<<"front:"<<str<<endl;
}
int main()
{
	string A,B;
	int ln,lm;
	while(cin>>A>>B)
	{
		change_front(A);
		change_front(B);
		ln=A.size()-1;
		lm=B.size()-1;
		for(int i=ln;i>=0;i--)
		{
			if(A[i]=='.')
			{
			change_back(A);
			break;
			}
		}
		for(int j=lm;j>=0;j--)
		{
			if(B[j]=='.')
			{
			change_back(B);
			break;
			}
		}
		if(A==B)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}