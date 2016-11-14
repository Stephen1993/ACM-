#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int MAX=1111;
int valume[MAX][2],valuee[MAX]={0};
int main(){
	int n,m,t;
	cin>>t;
	while(t--){
		memset(valuee,0,sizeof(valuee));
		cin>>n>>m;
		for(int i=0;i<n;++i){
			scanf("%d",&valume[i][0]);
		}
		for(int i=0;i<n;++i){
			scanf("%d",&valume[i][1]);
		}
		for(int i=0;i<n;++i){
			for(int j=m;j>=0;--j){
				if(j<valume[i][1]){
					valuee[j]=valuee[j];
				}
				else{
					valuee[j]=max(valuee[j],valuee[j-valume[i][1]]+valume[i][0]);
				}
			}
		}
		printf("%d\n",valuee[m]);
	}
	return 0;
}