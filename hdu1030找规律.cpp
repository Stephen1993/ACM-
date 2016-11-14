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
int n,m,n_x,n_y,n_z,m_x,m_y,m_z;
int calculate_x(int x){//����x���� 
	return (int)sqrt(double(x-1))+1;
}
int calculate_y(int x,int y){//����y���� 
	return abs((x-1)*(x-1)+1-y)/2+1;
}
int calculate_z(int x,int z){//����z���� 
	return abs(x*x-z)/2+1;
}
int main(){
	while(scanf("%d%d",&n,&m)!=EOF){
		n_x=calculate_x(n);
		n_y=calculate_y(n_x,n);
		n_z=calculate_z(n_x,n);
		m_x=calculate_x(m);
		m_y=calculate_y(m_x,m);
		m_z=calculate_z(m_x,m);
		printf("%d\n",abs(n_x-m_x)+abs(n_y-m_y)+abs(n_z-m_z));
	}
	return 0;
}
/*
��ν��x,y,z������,x����������µڼ��㣬y��������������µڼ���,z��������������µڼ���. 
��1(1,1,1),2(2,1,2)
x����Ϊsqrt(n-1)+1;
y�������x������������˵ĵ�Ȼ��-n����2����+1
z����ͬ��.
*/ 