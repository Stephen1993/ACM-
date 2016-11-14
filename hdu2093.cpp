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
string problem[13];

typedef struct node{
	char name[12];
	int num;
	int time;
	node(){
		num=time=0;
	}
};
node s[MAX];

bool cmp(node a,node b){
	if(a.num == b.num){
		if(a.time == b.time){
			return strcmp(a.name,b.name)<0?1:0;
		}
		return a.time<b.time;
	}
	return a.num>b.num;
}

int main(){
	int n,m;
	while(cin>>n>>m){
		int k=0;
		while(cin>>s[k].name){
			for(int i=0;i<n;++i){
				cin>>problem[i];
				int p=1,a=0,b=0,j=0;
				bool flag=false;
				if((problem)[i][0] == '-')p=-1,j++;
				for(;j<problem[i].size();++j){
					if(problem[i][j] == '('){flag=true;continue;}
					if(!(problem[i][j]>='0' && problem[i][j]<='9'))continue;
					if(flag){
						b=b*10+problem[i][j]-'0';
					}
					else a=a*10+problem[i][j]-'0';
				}
				if(a && p>0){s[k].num++;s[k].time+=a+b*m;}
			}
			k++;
		}
		sort(s,s+k,cmp);
		for(int i=0;i<k;++i){
		     printf("%-10s %2d %4d\n",s[i].name,s[i].num,s[i].time);
		}
	}
	return 0;
}