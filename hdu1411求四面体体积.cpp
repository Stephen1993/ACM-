#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
	double a,b,c,l,m,n;
	while(cin>>a>>b>>c>>l>>m>>n){
		double sum=sqrt(4*a*a*b*b*c*c-c*c*(a*a+b*b-l*l)*(a*a+b*b-l*l)-
		b*b*(a*a+c*c-m*m)*(a*a+c*c-m*m)-a*a*(b*b+c*c-n*n)*(b*b+c*c-n*n)+
		(a*a+b*b-l*l)*(a*a+c*c-m*m)*(b*b+c*c-n*n))/12;
		cout<<fixed<<setprecision(4)<<sum<<endl;
	}
	return 0;
}
/*
公式：
欧拉四面体公式，用来求三棱椎的体积。
V=sqrt((4*a*a*b*b*c*c-a*a*(b*b+c*c-m*m)*(b*b+c*c-m*m)-b*b*(c*c+a*a-n*n)*(c*c+a*a-n*n)-c*c*(a*a+b*b-l*l)*(a*a+b*b-l*l)+(a*a+b*b-l*l)*(b*b+c*c-m*m)*(c*c+a*a-n*n)))/12;

如三棱椎OABC，O为顶点，ABC为底面三角形
则
a－OA (线段OA 的长度为 a)
b－OB (OB 长为 b)
c－OC (.....)
l－AB
m－BC
n－CA
*/