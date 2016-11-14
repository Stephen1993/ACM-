#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<map>
#include<iomanip>
#include<cmath>
#define INF 9999999
using namespace std;
const int MAX=4001;
bool prime[MAX];
void Prime(){
	for(int i=2;i<=MAX/2;++i)prime[i*2]=true;
	for(int i=3;i<=(int)sqrt(MAX*1.0);i+=2){
		if(!prime[i]){
			for(int j=i*i;j<=MAX;j+=2*i){
				prime[j]=true;
			}
		}
	}
}
int main(){
	Prime();
	int a,b,m;
	while(cin>>m>>a>>b,a||b||m){
		int MAX_pq[2]={1,1};
		int d=(int)sqrt(m*1.0);
		for(int p=d;p>=2;--p){
			if(!prime[p]){
				for(int q=p;q<=(int)(b*1.0/a*p)&&q<MAX&&q<=m/p;++q){
					if(!prime[q])
					if(p*q>MAX_pq[0]*MAX_pq	[1]){
						MAX_pq[0]=p;
						MAX_pq[1]=q;
					}
				}
			}
		}
		cout<<MAX_pq[0]<<' '<<MAX_pq[1]<<endl;
	}
	return 0;
}