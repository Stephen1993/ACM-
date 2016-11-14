#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=100;
typedef struct{
	string name;
	int grade;
	int net_goal;
	int all_ball;
}noto;
map<string,int>mark;
bool cmp(noto a,noto b){
	if(a.grade==b.grade){
		if(a.net_goal==b.net_goal){
			if(a.all_ball==b.all_ball){
				return a.name<b.name;
			}
			return a.all_ball>b.all_ball;
		}
		return a.net_goal>b.net_goal;
	}
	return a.grade>b.grade;
}
int main(){
	int n,c,d;
	char a[MAX],b[MAX];
	while(cin>>n){
		int k=1;
		mark.clear();
		noto *s=(noto*)new noto[n+2];
		for(int i=1;i<=(n-1)*n;++i){
			scanf("%s VS %s %d:%d",a,b,&c,&d);
			if(!mark[a]){
				mark[a]=k;
				if(c>d)s[k].grade=3;
				else if(c==d)s[k].grade=1;
				else s[k].grade=0;
				s[k].name=a;
				s[k].net_goal=c-d;
				s[k++].all_ball=c;
			}
			else{
				if(c>d)s[mark[a]].grade+=3;
				if(c==d)s[mark[a]].grade+=1;
				s[mark[a]].net_goal+=c-d;
				s[mark[a]].all_ball+=c;
			}
			if(!mark[b]){
				mark[b]=k;
				if(c<d)s[k].grade=3;
				else if(c==d)s[k].grade=1;
				else s[k].grade=0;
				s[k].name=b;
				s[k].net_goal=d-c;
				s[k++].all_ball=d;
			}
			else{
				if(c<d)s[mark[b]].grade+=3;
				if(c==d)s[mark[b]].grade+=1;
				s[mark[b]].net_goal+=d-c;
				s[mark[b]].all_ball+=d;
			}
		}
		sort(&s[1],s+n+1,cmp);
		for(int i=1;i<=n;++i){
			cout<<s[i].name<<" "<<s[i].grade<<endl;
		}
		cout<<endl;
	}
	return 0;
}