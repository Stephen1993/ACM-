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

const int MAX=100+10;
double s[MAX][2];

double calculate(int i,int j,int k){
	return fabs((s[j][0]-s[i][0])*(s[k][1]-s[i][1])-(s[k][0]-s[i][0])*(s[j][1]-s[i][1]))/2;
}

int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;++i)scanf("%lf%lf",&s[i][0],&s[i][1]);
		double sum=INF*1.0;
		for(int i=0;i<n;++i){
			for(int j=i+1;j<n;++j){
				for(int k=j+1;k<n;++k){
					if(s[i][1] == s[j][1] && s[j][1] == s[k][1])continue;
					if((s[j][1]-s[i][1])/(s[j][0]-s[i][0]) == (s[k][1]-s[j][1])/(s[k][0]-s[j][0]))continue;
					sum=min(sum,calculate(i,j,k));
				}
			}
		}
		if(sum == INF*1.0)printf("Impossible\n");
		else printf("%.2lf\n",sum);
	}
	return 0;
}