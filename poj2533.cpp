#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#define INF 999999
using namespace std;
const int MAX=1004;
int length[MAX],s[MAX]; 
int main(){
	int n,a;
	while(scanf("%d",&n)!=EOF){
		int max=0;
		fill(length,length+n+3,1);
		for(int i=1;i<=n;++i){
			scanf("%d",&s[i]);
			for(int j=1;j<i;++j){
				if(s[i]>s[j]){
					length[i]=length[i]>(length[j]+1)?length[i]:(length[j]+1);
				}
			}
			max=max>length[i]?max:length[i];
		}
		cout<<max<<endl;
	}
	return 0;
}