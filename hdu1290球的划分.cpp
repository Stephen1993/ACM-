#include<iostream>
using namespace std;

const int MAX=1001;
int g[MAX]={0,2},f[MAX]={1,2};

void calculate(){
	for(int i=2;i<=1000;++i){
		g[i]=g[i-1]+f[i-1];
		f[i]=f[i-1]+i;
	}
}

int main(){
	int n;
	calculate();
	while(cin>>n){
		cout<<g[n]<<endl;
	}
	return 0;
}
/*
①n条直线把平面分割成的区域数： f(n)=f(n-1)+n=n(n+1)/2+1;
②把空间分割为最多的区域数的时候，第n个平面与前(n-1)个平面相交，
且无三面共线，所以此时该平面与前(n-1)个平面有(n-1)条交线。
这些交线把第n个平面分割为f(n-1)个区域，于是这个平面将原有空间一分为二，
故增加了f(n-1)个空间，得递推公式：g(n)=g(n-1)+f(n-1)=(n^3+5n)/6+1。
*/