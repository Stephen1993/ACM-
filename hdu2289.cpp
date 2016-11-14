#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<math.h>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=10;
const double PI=acos(-1.0);

int main(){
	int t;
	double r,R,H,V,h;
	cin>>t;
	while(t--){
		cin>>r>>R>>H>>V;
		if(r == R){//圆柱体,直接求高 
			h=V/PI/r/r;
		}else{//圆台,补全为圆锥求按比例求高 
			h=r*H/(R-r);//补全的那部分圆锥高
			double v=PI*r*r*h/3;//补全那部分圆锥的体积
			h=pow((v+V)/v,1.0/3)*h-h;//有水那部分高 
		}
		if(h>H)h=H;
		cout<<fixed<<setprecision(6)<<h<<endl;
	}
	return 0;
}
/*****************************************************/
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<math.h>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=10;
const double PI=acos(-1.0);
const double eps=1e-7;
double r,R,H,V;

double volume(double h){//计算圆台的体积
	double Ro=(r*H-r*h+R*h)/H;//用梯形面积求半径,不用圆锥高之比求半径是因为r可能等于R 
	return PI*h*(r*r+Ro*Ro+Ro*r)/3;//求圆台面积 
}

double search(double &key,double &h){
	double left=0,right=h;
	while(right-left>eps){
		double mid=(left+right)/2;
		double v=volume(mid);
		if(fabs(v-key)<eps)return mid;
		else if(v<key)left=mid;
		else right=mid;
	}
	return right;//水的体积超过整个杯子的体积则高为H 
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>r>>R>>H>>V;
		double h=search(V,H);
		cout<<fixed<<setprecision(6)<<h<<endl;
	}
	return 0;
}