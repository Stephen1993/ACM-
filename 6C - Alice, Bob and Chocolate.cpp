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
const int MAX=100001;
int s[MAX];
int main(){
	int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;++i){
			scanf("%d",&s[i]);
		}
		int a=0,b=0,time_a=0,time_b=0,i=0;
		while(1){
			if(time_a<=time_b){
				time_b-=time_a;
				time_a=s[i];
				a++;
				i++;
				if(i>=n)break;
			}
			else{
				time_a-=time_b;
				time_b=s[n-1];
				b++;
				n--;
				if(i>=n)break;
			}
		}
		cout<<a<<' '<<b<<endl;
	}
	return 0;
}