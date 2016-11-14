#include<iostream>
#include<cstdio>
using namespace std;
const int MAX=10000001;
int s[MAX];
int main(){
	s[0]=-2;
	s[1]=-1;
   for(int i=2;i<MAX;++i){
       for(int j=2;j<=MAX/i;++j){
	      s[i*j]++;
       }
	}
	int max_shu=-2;
	int MAX_i=1;
	for(int i=1;i<MAX;++i){
		if(s[i]>max_shu){
			max_shu=s[i];
			MAX_i=i;
		}
		s[i]=MAX_i;
	}
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%d\n",s[n]);
	}
	return 0;
}