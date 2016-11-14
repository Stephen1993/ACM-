#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<iomanip>
#include<algorithm>
#include<queue>
#include<limits.h>
#include<iomanip>
using namespace std;
const int MAX=3;
__int64 v[MAX][MAX];
void matrix_mul(){
	__int64 a=(v[0][0]*v[0][0]+v[0][1]*v[1][0])%10000;
	__int64 b=(v[0][0]*v[0][1]+v[0][1]*v[1][1])%10000;
	__int64 c=(v[1][0]*v[0][0]+v[1][1]*v[1][0])%10000;
	__int64 d=(v[1][0]*v[0][1]+v[1][1]*v[1][1])%10000;
	v[0][0]=a;v[0][1]=b;v[1][0]=c;v[1][1]=d;
}
void matrix_prow(__int64 num){
	if(num==1)return;
	matrix_prow(num/2);//A^4=A*A*A*A=A^2*A^2=>A^n=A^n/2*A^n/2; 
	if(!(num&1)){
		matrix_mul();
	}
	else{
		matrix_mul();
		v[0][1]=(v[0][1]+v[0][0])%10000;//若num为奇数则还要再乘一个{{0，1}{1,1}}矩阵. 
		v[0][0]=(v[0][1]+10000-v[0][0])%10000;
		v[1][1]=(v[1][1]+v[1][0])%10000;
		v[1][0]=(v[1][1]+10000-v[1][0])%10000;
	}
}
int main(){
	__int64 n;
	while(cin>>n,n>=0){
		if(n==0){
			cout<<'0'<<endl;
			continue;
		}
		else if(n==1||n==2){
			cout<<'1'<<endl;
			continue;
		}
		v[0][0]=0;v[0][1]=1;v[1][0]=1;v[1][1]=1;
		matrix_prow(n-2);
		cout<<(v[0][1]+v[1][1])%10000<<endl;
	}
	return 0;
}