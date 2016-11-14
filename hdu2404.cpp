//http://acm.hdu.edu.cn/showproblem.php?pid=2404
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
int s[MAX];

int main(){
	int n,a,j;
	while(scanf("%d",&n),n){ 
		memset(s,0,sizeof s);
		for(int i=1;i<=n;++i){
			scanf("%d",&a);
			int temp=0;
			for(j=1;j<=n;++j){
				if(!s[j])++temp;
				if(temp>a)break;
			}
			s[j]=i;
		}
		printf("%d",s[1]);
		for(int i=2;i<=n;++i){
			printf(",%d",s[i]);
		}
		printf("\n");
	}
	return 0;
}