#include<iostream>
#include<algorithm>
using namespace std;
int d[11111];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;++i){
			scanf("%d",&d[i]);
		}
		sort(d,d+n);
		for(int i=0;i<=n/2-1;++i){
			if(i)printf(" ");
			printf("%d %d",d[n-1-i],d[i]);
		}
		if(n&1)printf(" %d",d[(n-1)/2]);
		printf("\n");
	}
	return 0;
}