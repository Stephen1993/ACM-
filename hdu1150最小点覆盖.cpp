#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<iomanip>
#define INF 999999
using namespace std;
const int MAX=1111;
int link[MAX];
bool marry[MAX][MAX],mark[MAX];
int k,m,n;
bool find(int x){
	for(int i=0;i<m;++i){
		if(!mark[i]&&marry[x][i]){
			mark[i]=true;
			if(link[i]==-1||find(link[i])){
				link[i]=x;
				return true;
			}
			//mark[i]=false;
		}
	} 
	return false;
}
int hungarian_algorithm(){
	int num=0;
	for(int i=0;i<n;++i){
		memset(mark,false,sizeof mark);
		if(find(i))num++;
	}
	return num;
}
int main(){
	int a,b,c;
	while(scanf("%d",&n),n){
		cin>>m>>k;
		memset(link,-1,sizeof link);
		memset(marry,false,sizeof marry);
		for(int i=0;i<k;++i){
			scanf("%d%d%d",&a,&b,&c);//每一个任务其实就是一条边b-c，而一个点就是一个模式，所以只要求最小点覆盖就行.
			if(b&&c)marry[b][c]=true;//状态为零的不需要重启. 
		}
		int sum=hungarian_algorithm();
		cout<<sum<<endl;
	}
	return 0;
} 