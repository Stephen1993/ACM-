#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct point 
{
	string number;
	int n,s[11],sum;
}student[1002];
bool cmp(point a,point b)
{
	if(a.sum!=b.sum)return a.sum>b.sum;
	return a.number<b.number;
}
int main()
{
	int m,num,grade[11],mingrade,student_num;
	while(cin>>m,m)
	{
	    cin>>num>>mingrade;
		student_num=0;
		for(int i=1;i<=num;++i)
		 cin>>grade[i];
		for(int i=0;i<m;++i)
		{
			cin>>student[i].number>>student[i].n;
			student[i].sum=0;
			for(int j=0;j<student[i].n;++j)
			 {
			   cin>>student[i].s[j];
			   student[i].sum+=grade[student[i].s[j]];
	         }
	         if(student[i].sum>=mingrade)
		      student_num++;
		}
		sort(student,student+m,cmp);
		cout<<student_num<<endl;
		for(int i=0;i<student_num;++i)
		cout<<student[i].number<<' '<<student[i].sum<<endl;
	}
	return 0;
}