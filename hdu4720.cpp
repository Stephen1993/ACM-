#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=10;

void check(double x1,double y1,double x2,double y2,double x3,double y3,double &x,double &y,double &R){
	x1=(x1+x2)/2,y1=(y1+y2)/2,x3=x1-x3,y3=y1-y3;
	double r=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
	if(r>=x3*x3+y3*y3 && r<R)x=x1,y=y1,R=r;
}

int main(){
	int t,num=0;
	double x1,x2,x3,x4,y1,y2,y3,y4,x,y,R,a1,a2,b1,b2,c1,c2;
	cin>>t;
	while(t--){
		cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
		a1=2*x2-2*x1,b1=2*y2-2*y1,c1=x1*x1-x2*x2+y1*y1-y2*y2;
		a2=2*x3-2*x2,b2=2*y3-2*y2,c2=x2*x2-x3*x3+y2*y2-y3*y3;
		y=(a2*c1-a1*c2)/(a1*b2-a2*b1),x=(-b1*y-c1)/a1,R=(x1-x)*(x1-x)+(y1-y)*(y1-y);
		check(x1,y1,x2,y2,x3,y3,x,y,R);
		check(x1,y1,x3,y3,x2,y2,x,y,R);
		check(x2,y2,x3,y3,x1,y1,x,y,R);
		cout<<"Case #"<<++num<<": ";
		if((x4-x)*(x4-x)+(y4-y)*(y4-y)<=R)cout<<"Danger"<<endl;
		else cout<<"Safe"<<endl;
	}
	return 0;
}