#include<iostream>
using namespace std;
int c(int &a,int &b){
	return a<b?a=b,1:0;
}
int main(){
	double a=-3.5;
	int b=int(a)+(a-int(a)>0?1:0);//����ȡ��. 
	cout<<b<<endl;
	return 0;
}