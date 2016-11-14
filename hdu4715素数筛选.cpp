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

const int MAX=1000000+10;
bool prime[MAX];
int s[200]={2},size;

void Prime(){//ËØÊýÉ¸Ñ¡ 
	for(int i=2;2*i<MAX;++i)prime[2*i]=true;
	for(int i=3;i*i<MAX;i+=2){
		if(!prime[i]){
			s[++size]=i;
			for(int j=i*i;j<MAX;j+=i)prime[j]=true;
		}
	}
}

int main(){
	Prime();
	int t,n,m,i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		m=n>0?n:-n;
		for(i=0;i<=size;++i){
			if(!prime[s[i]+m])break;
		}
		if(n>0)printf("%d %d\n",s[i]+m,s[i]);
		else printf("%d %d\n",s[i],s[i]+m);
	}
	return 0;
}