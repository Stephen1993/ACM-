#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=10001;
bool prime[MAX];
int s[501];
void Prime(){
	for(int i=2;i<=MAX/2;++i)prime[2*i]=true;
	for(int i=3;i*i<=MAX;i+=2){
		if(!prime[i]){
			for(int j=i*i;j<=MAX;j+=2*i){
				prime[j]=true;
			}
		}
	}
}
int main(){
	int n,k=0;
	Prime();
	while(scanf("%d",&n),n){
		s[k++]=n;
	}
	for(int i=0;i<k;++i){
		int num=0;
		for(int j=2;j<=s[i]/2;++j){
			if(!prime[j]&&!prime[s[i]-j]){
				if(j!=s[i]-j){
					num++;
				}
			}
		}
		cout<<num<<endl;
	}
	return 0;
}