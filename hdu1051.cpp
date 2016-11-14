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
const int MAX=5001;
typedef struct{
	int length;
	int weight;
	bool mark;
}point;
point s[MAX];
bool cmp(const point &a,const point &b){
	if(a.length==b.length){
		return a.weight<b.weight;
	}
	return a.length<b.length;
}
int main(){
	int t,n,weight;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;++i){
			scanf("%d%d",&s[i].length,&s[i].weight);
			s[i].mark=false;
		}
		sort(s,s+n,cmp);
		int num=0;
		for(int i=0;i<n;++i){
			if(!s[i].mark){
				num++;
				weight=s[i].weight;
				for(int j=i+1;j<n;++j){
					if(s[j].weight>=weight&&!s[j].mark){
						s[j].mark=true;
						weight=s[j].weight;
					}
				}
			}
		}
		cout<<num<<endl;
	}
	return 0;
}