#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#include<cmath>
#define INF 99999999
using namespace std;
const int MAX=100;
int main(){
	double h1,r1,x1,y1,z1,a,b,c;
	double h2,r2,x2,y2,z2,x3,y3,z3;
	int t;
	cin>>t;
	while(t--){
		cin>>h1>>r1>>x1>>y1>>z1;
		cin>>h2>>r2>>x2>>y2>>z2>>x3>>y3>>z3;
		z1+=h1-r1;
		z2+=h2*0.9-r2;
		double x=x1-x2,y=y1-y2,z=z1-z2;
		a=y*z3-z*y3;//手枪的方向向量与警察与土匪连线的差乘  
        b=z*x3-x*z3;  
        c=x*y3-y*x3;  
		double l=sqrt((pow(a,2)+pow(b,2)+pow(c,2))/(x3*x3+y3*y3+z3*z3));
		double flag=x3*x+y3*y+z3*z;
		if(l<=r1&&flag>0){
			cout<<"YES"<<endl;
		}
		else cout<<"NO"<<endl;
	}
	return 0;
}
/*a*b=1/2|a||b|sin(&)
l=asin(&)=a*b*2/|b|
用叉积计算点到直线的距离(即等面积做).
*/ 