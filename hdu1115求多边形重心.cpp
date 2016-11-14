/*
摘自：KIDxの博客 
求多边形重心的题目大致有这么几种： 
1、质量集中在顶点上 
    n个顶点坐标为(xi,yi)，质量为mi，则重心 
　　X = ∑( xi×mi ) / ∑mi 
　　Y = ∑( yi×mi ) / ∑mi 
　　特殊地，若每个点的质量相同，则 
　　X = ∑xi / n 
　　Y = ∑yi / n 
2、质量分布均匀 
　　特殊地，质量均匀的三角形重心： 
　　X = ( x0 + x1 + x2 ) / 3 
　　Y = ( y0 + y1 + y2 ) / 3 
3、质量分布不均匀 
    只能用函数多重积分来算，不太会 
这题的做法： 
将n边形分成多个三角形，分别求出重心坐标以及质量m【因为质量分布均匀，所以可以设密度为1，则面积就是质量】 
因为质量都集中在重心 
所以把所有求出来的重心按逆时针连接起来又是一个多边形 
但是这个多边形的质量集中在顶点上 
所以可以利用上面公式进行计算 
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=100;
int main(){
	int t,n,a,x1,y1,x2,y2,x3,y3;
	double s,S=0,X=0,Y=0;
	cin>>t;
	while(t--){
		S=X=Y=0;
		cin>>n;
		cin>>x1>>y1>>x2>>y2;
		for(int i=2;i<n;++i){
			cin>>x3>>y3;
			s=0.5*((x1-x3)*(y1-y2)-(x1-x2)*(y1-y3));//叉积求面积 
			X+=s*(x1+x2+x3);//(x1+x2+x3)/3,是三角形重心x坐标，除于3留到最后除. 
			Y+=s*(y1+y2+y3);
			S+=s;
			x2=x3;
			y2=y3;
		}
		X=X/(3*S);
		Y=Y/(3*S);
		cout<<fixed<<setprecision(2)<<X<<' '<<Y<<endl;
	}
	return 0;
}