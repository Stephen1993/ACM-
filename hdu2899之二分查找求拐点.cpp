#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<cmath>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=10;
const double eps=1e-6;

double F(double x,double y){
	return 6*pow(x,7)+8*pow(x,6)+7*pow(x,3)+5*pow(x,2)-y*x;
}

double f(double x){
	return 42*pow(x,6)+48*pow(x,5)+21*pow(x,2)+10*x;
}

int main(){
	int t;
	double y;
	cin>>t;
	while(t--){
		cin>>y;
		double left=0,right=100;
		while(right-left>eps){
			double mid=(left+right)/2;
			if(f(mid)<y)left=mid;
			else right=mid;
		}
		cout<<fixed<<setprecision(4)<<F(left,y)<<endl;
	}
	return 0;
}