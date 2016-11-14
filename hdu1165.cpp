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
const int MAX=10;
int n,m;
__int64 A(int a,int b){
	if(b==0)return A(a-1,1);
	if(a==1)return b+2;
	if(a==2)return 2*b+3;
	return 2*A(a,b-1)+3; 
}
int main(){
	while(cin>>m>>n){
		cout<<A(m,n)<<endl;
	}
	return 0;
} 