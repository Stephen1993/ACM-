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
const int MAX=111;
int people[MAX][MAX]={0};
int n;
void floyd(){
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			if(people[i][k]!=INF){
				for(int j=1;j<=n;++j){
					if(people[k][j]!=INF&&people[i][j]>people[i][k]+people[k][j]){
						people[i][j]=people[i][k]+people[k][j];
					}
				}
			}
		}
	}
}
int main(){
	int m,time,name;
	while(scanf("%d",&n),n){
		for(int i=1;i<n;++i){
			for(int j=i+1;j<=n;++j){
				people[i][j]=people[j][i]=INF;
			}
		}
		for(int i=1;i<=n;++i){
		    scanf("%d",&m);
		    for(int j=0;j<m;++j){
					scanf("%d%d",&name,&time);
					people[i][name]=time;
				}
		}
			floyd();
			int temp=INF;
			int sum=0;
			int x=0;
			int max_time,y;
			bool flag;
			for(int i=1;i<=n;++i){
				sum=0;
				y=0;
				flag=true;
				for(int j=1;j<=n;++j){
					if(people[i][j]==INF){
						flag=false;
						break;
					}
					y=max(y,people[i][j]);
					sum+=people[i][j];
				}
				if(temp>sum&&flag){
					temp=sum;
					x=i;
					max_time=y;
				}
			}
		if(temp==INF){
			cout<<"disjoint"<<endl;
		}
		else cout<<x<<' '<<max_time<<endl;
	}
	return 0;
}