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
��ʽ��
ŷ�������幫ʽ������������׵�������
V=sqrt((4*a*a*b*b*c*c-a*a*(b*b+c*c-m*m)*(b*b+c*c-m*m)-b*b*(c*c+a*a-n*n)*(c*c+a*a-n*n)-c*c*(a*a+b*b-l*l)*(a*a+b*b-l*l)+(a*a+b*b-l*l)*(b*b+c*c-m*m)*(c*c+a*a-n*n)))/12;

������׵OABC��OΪ���㣬ABCΪ����������
��
a��OA (�߶�OA �ĳ���Ϊ a)
b��OB (OB ��Ϊ b)
c��OC (.....)
l��AB
m��BC
n��CA
*/