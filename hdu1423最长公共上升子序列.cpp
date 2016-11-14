#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=500+10;
int a[MAX],b[MAX],sum[MAX];

int main(){
	int t,n,m;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;++i)scanf("%d",&a[i]);
		scanf("%d",&m);
		for(int i=0;i<m;++i)scanf("%d",&b[i]);
		memset(sum,0,sizeof sum);
		for(int i=0;i<n;++i){
			int maxl=0;
			for(int j=0;j<m;++j){
				if(a[i] == b[j])sum[j]=max(sum[j],maxl+1);
				else if(a[i]>b[j])maxl=max(maxl,sum[j]);
			}
		}
		int maxl=0;
		for(int i=0;i<m;++i)maxl=max(maxl,sum[i]);
		printf("%d\n",maxl);
		if(t)printf("\n");
	}
	return 0;
}