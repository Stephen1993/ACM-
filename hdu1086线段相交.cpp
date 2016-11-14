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
const int MAX=101;
typedef struct{
	double x1;
	double y1;
	double x2;
	double y2;
}noto;
noto segments[MAX];
int n;
bool panduan(noto a,noto b){
	double k,c;
	bool flag1=false,flag2=false;
	if(a.x1!=a.x2){
		k=(a.y2-a.y1)/(a.x2-a.x1);
		c=a.y1-k*a.x1;
		if((b.y1-k*b.x1<=c&&b.y2-k*b.x2>=c)||(b.y1-k*b.x1>=c&&b.y2-k*b.x2<=c)){
			flag1=true;
		}
	}
	else{
		if((b.x1<=a.x1&&b.x2>=a.x1)||(b.x2<=a.x1&&b.x1>=a.x1)){
			flag1=true;
		}
	}
	if(b.x1!=b.x2){
		k=(b.y2-b.y1)/(b.x2-b.x1);
		c=b.y1-k*b.x1;
		if((a.y1-k*a.x1<=c&&a.y2-k*a.x2>=c)||(a.y1-k*a.x1>=c&&a.y2-k*a.x2<=c)){
			flag2=true;
		}
	}
	else{
		if((a.x1<=b.x1&&a.x2>=b.x1)||(a.x2<=b.x1&&a.x1>=b.x1)){
			flag2=true;
		}
	}
	if(flag1&&flag2)return true;
	return false;
}
int main(){
	while(cin>>n,n){
		int num=0;
		for(int i=0;i<n;++i){
			cin>>segments[i].x1>>segments[i].y1>>segments[i].x2>>segments[i].y2;
		}
		for(int i=0;i<n-1;++i){
			for(int j=i+1;j<n;++j){
				if(panduan(segments[i],segments[j])){
					num++;
				}
			}
		}
		cout<<num<<endl;
	}
	return 0;
}