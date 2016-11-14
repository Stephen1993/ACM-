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
const int MAX=100000;
typedef struct{
	int a;
	int b;
	double c;
}JavaBean;
JavaBean s[MAX];
bool cmp(const JavaBean &a,const JavaBean &b){
	return a.c>b.c;
}
int main(){
	int m,n;
	while(scanf("%d%d",&m,&n),m!=-1||n!=-1){
		for(int i=0;i<n;++i){
			scanf("%d%d",&s[i].a,&s[i].b);
			if(s[i].b!=0&&s[i].a!=0)
			s[i].c=s[i].a*1.0/s[i].b;
			else if(s[i].b==0)
			s[i].c=INF;//s[i].b==0则s[i].c无穷大. 
			else
			s[i].c=-INF;//s[i].a==0则s[i].c无穷小.
		}
		double sum=0;
		sort(s,s+n,cmp);
		for(int i=0;(m||s[i].b==0)&&n;++i){//n>0则才可以继续执行,防止所有的s[i].b==0无限执行下去,m==0但s[i].b==0时可以继续执行. 
			if(m>=s[i].b){
				sum+=s[i].a;
				m=m-s[i].b;
				n--;
			}
			else{
				sum+=m*1.0/s[i].b*s[i].a;
				m=0;
			}
		}
		cout<<fixed<<setprecision(3)<<sum<<endl;
	}
	return 0;
}
/*
0 1
1 0
1.000

1 0
0.000

5 4
10000 5
2000 2
100 0
300 0
10400.000
/*