#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=50000+10;
int s[MAX],rmqmax[MAX][32],rmqmin[MAX][32];

void InitRMQ(int n){//n是数组长度 
	for(int i=0;i<n;++i)rmqmax[i][0]=rmqmin[i][0]=s[i];
	int l=log(n*1.0)/log(2.0);//2*l<=n
	for(int j=1;j<=l;++j){
		for(int i=0;i<n+1-(1<<j);++i){//i+2^j-1<n
			rmqmax[i][j]=max(rmqmax[i][j-1],rmqmax[i+(1<<(j-1))][j-1]);//i~i+2^(j-1)-1,i+2^(j-1)~i+2^j-1
			rmqmin[i][j]=min(rmqmin[i][j-1],rmqmin[i+(1<<(j-1))][j-1]);//i~i+2^(j-1)-1,i+2^(j-1)~i+2^j-1
		}
	}
}

int lcpmax(int a,int b){
	int j=log(b-a+1.0)/log(2.0);//2^j<=b-a+1
	return max(rmqmax[a][j],rmqmax[b+1-(1<<j)][j]);
}

int lcpmin(int a,int b){
	int j=log(b-a+1.0)/log(2.0);
	return min(rmqmin[a][j],rmqmin[b+1-(1<<j)][j]);
}

int main(){
	//freopen("stdin.txt","r",stdin);
	//freopen("stdout.txt","w",stdout);
	int n,m,a,b;
	while(cin>>n>>m){
		for(int i=0;i<n;++i)scanf("%d",&s[i]);//cin>>s[i];
		InitRMQ(n);
		for(int i=0;i<m;++i){
			scanf("%d%d",&a,&b);//cin>>a>>b;
			printf("%d\n",lcpmax(a-1,b-1)-lcpmin(a-1,b-1));//cout<<lcpmax(a-1,b-1)-lcpmin(a-1,b-1)<<endl;
		}
	}
	return 0;
}