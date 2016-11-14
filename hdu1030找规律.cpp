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
int calculate_x(int x){//计算x坐标 
	return (int)sqrt(double(x-1))+1;
}
int calculate_y(int x,int y){//计算y坐标 
	return abs((x-1)*(x-1)+1-y)/2+1;
}
int calculate_z(int x,int z){//计算z坐标 
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
所谓的x,y,z坐标是,x代表从上往下第几层，y代表从左上往右下第几层,z代表从右上往左下第几层. 
如1(1,1,1),2(2,1,2)
x坐标为sqrt(n-1)+1;
y坐标根据x坐标来算最左端的点然后-n除于2的商+1
z坐标同理.
*/ 