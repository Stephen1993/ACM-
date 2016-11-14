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
const int MAX=1001;
typedef struct{
	int x;
	int y;
	int pos;
	int last;
}noto;
noto s[MAX];
bool cmp(noto a,noto b){
	if(a.x==b.x){
		return a.y>b.y;
	}
	return a.x<b.x;
}
int n=0,sum[MAX];
int main(){
	while(cin>>s[n].x>>s[n].y){s[n].last=-1;s[n].pos=n+1;n++;}
	fill(sum,sum+n,1);
	sort(s,s+n,cmp);
	for(int i=1;i<n;++i){
		for(int j=0;j<i;++j){//DP，用集合的思想,i能加入哪个集合且使得该集合为元素最多. 
			if(s[j].y>s[i].y&&sum[i]<sum[j]+1&&s[i].x>s[j].x){
				sum[i]=sum[j]+1;
				s[i].last=j;
			}
		}
	}
	int k=0;
	for(int i=1;i<n;++i){
		if(sum[i]>sum[k]){
			k=i;
		}
	}
	cout<<sum[k]<<endl;
	int num=0;
	while(k!=-1){sum[num++]=s[k].pos;k=s[k].last;}
	while((--num)>=0)cout<<sum[num]<<endl;
	return 0;
}