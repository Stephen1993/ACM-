/*
对可能的面积进行二分，然后判断可以分成多少块这样的面积和人数比较就行 
*/
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

const int MAX=10000+10;
const double PT=3.14159265358979323846;
double s[MAX];
int t,n,m;

bool search(double v){
	int sum=0;
	for(int i=0;i<n;++i){
		sum+=(int)(s[i]/v);
	}
	if(sum>=m)return true;
	else return false;
} 

int main(){
	cin>>t;
	while(t--){
		cin>>n>>m;
		++m;
		double maxs=-INF,mins=0,mid=0;
		for(int i=0;i<n;++i){
			cin>>s[i];
			s[i]=PT*s[i]*s[i];
			maxs=max(maxs,s[i]*1.0);
		}
		while(fabs(mins-maxs)>1e-6){
			mid=(mins+maxs)/2;
			if(search(mid))mins=mid;
			else maxs=mid;
		}
		cout<<fixed<<setprecision(4)<<mid<<endl;
	}
	return 0;
} 