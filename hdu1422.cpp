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

const int MAX=100001;
int s[MAX][2];

int main(){
	int n;
	while(cin>>n){
		int num=0,sum=0,all=0;
		int j=-1;
		for(int i=0;i<n;++i){
			scanf("%d%d",&s[i][0],&s[i][1]);
			sum+=s[i][0]-s[i][1];
			if(sum<0){
				all=max(num,all);
				num=sum=0;
				j=i;
			}
			else num++;
		}
		if(j != -1 && sum>=0){
			for(int i=0;i<=j;++i){
				sum+=s[i][0]-s[i][1];
			    if(sum<0)break;
			    else num++;
			}
		}
		all=max(num,all);
		cout<<all<<endl;
	}
	return 0;
} 