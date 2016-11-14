#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#include<limits.h>
#define INF 999999
using namespace std;
const int MAX=1111;
int bus[MAX][MAX]={0};
int m;
map<string,int>road;
void floyd(){
	for(int k=1;k<m;++k){
		for(int i=1;i<m;++i){
			if(bus[i][k]!=INF){
				for(int j=1;j<m;++j){
					bus[i][j]=min(bus[i][j],bus[i][k]+bus[k][j]);
				}
			}
		}
	}
}
int main(){
	int n;
	char first[31],second[31],start[31],end[31];
	int length_;
	while(scanf("%d",&n),n!=-1){
		bool flag=false;
		road.clear();
		scanf("%s%s",start,end);
		for(int i=1;i<1100;++i){
			for(int j=i+1;j<=1100;++j){
				bus[i][j]=bus[j][i]=INF;
			}
		}
		road[start]=1;
		road[end]=2;
		if(!strcmp(start,end)){
             flag=true;
		}
		m=3;
		for(int i=0;i<n;++i){
			scanf("%s%s%d",first,second,&length_);
			if(!road[first]){
				road[first]=m++;
			}
			if(!road[second]){
				road[second]=m++;
			}
			bus[road[first]][road[second]]=bus[road[second]][road[first]]=min(bus[road[first]][road[second]],length_);
		}
		if(flag){
			cout<<"0\n";
			continue;
		}
		floyd();
		if(bus[1][2]!=INF)
		cout<<bus[1][2]<<endl;
		else cout<<"-1"<<endl;
	}
	return 0;
}