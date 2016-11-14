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
const int MAX=1002;
int x[MAX],y[MAX],link[MAX];
bool mark[MAX];
int n;
bool find(int j){
	for(int i=1;i<=n;++i){
		if(!mark[i]&&x[j]>y[i]){
			mark[i]=true;
			if(!link[i]||find(link[i])){//判断是否可以增广路径. 
				link[i]=j;
				return true;
			}
		}
	}
	return false;
}
int hungarian_algorithm(){
	int num=0;
	for(int i=1;i<=n;++i){
		memset(mark,false,sizeof mark);
		if(find(i))num++;
	}
	return num;
}
int main(){
	while(scanf("%d",&n),n){
		memset(link,0,sizeof link);
		for(int i=0;i<n;++i){
			scanf("%d",&x[i]);
		}
		for(int i=0;i<n;++i){
			scanf("%d",&y[i]);
		}
		cout<<(2*hungarian_algorithm()-n)*200<<endl;
	}
	return 0;
}