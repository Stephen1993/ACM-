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
const int MAX=100001;
int n;
double max_d;
typedef struct{
	double x;
	double y;
}point;
point pos[MAX];
int cmpx(const void *a,const void *b){
	point *c=(point*)a;
	point *d=(point*)b;
	if((*c).x==(*d).x){
		return (*c).y-(*d).y;
	}
	return (*c).x-(*d).x;
}
int cmpy(const void *a,const void *b){
	point *c=(point*)a;
	point *d=(point*)b;
	if((*c).y==(*d).y){
		return (*c).x-(*d).x;
	}
	return (*c).y-(*d).y;
}
void calculate(){
	for(int i=0;i<n-1;++i){
		for(int j=i+1;j<n&&j<i+40;++j){
			max_d=min(max_d,(pos[i].x-pos[j].x)*(pos[i].x-pos[j].x)+(pos[i].y-pos[j].y)*(pos[i].y-pos[j].y));
		}
	}
}
int main(){
	while(scanf("%d",&n),n){
		for(int i=0;i<n;++i){
			scanf("%lf%lf",&pos[i].x,&pos[i].y);
		}
		max_d=INF;
		qsort(pos,n,sizeof(point),cmpx);
		calculate();
		qsort(pos,n,sizeof(point),cmpy);
		calculate();
		cout<<fixed<<setprecision(2)<<sqrt(max_d)/2<<endl;
	}
	return 0;
}
