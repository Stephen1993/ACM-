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

const int MAX=11;

typedef struct{
	string name;
	int mm;
	int ss;
}node;
node s[MAX];

bool cmp(node a,node b){
	if(a.mm == b.mm){
		if(a.ss == b.ss)return a.name<b.name;
		return a.ss<b.ss;
	}
	return a.mm<b.mm;
}

int main(){
	int n,num=1;
	while(cin>>n,n){
		if(num != 1)cout<<endl;
		for(int i=0;i<n;++i){
			cin>>s[i].name;
			scanf("%d:%d",&s[i].mm,&s[i].ss);
		}
		sort(s,s+n,cmp);
		int k=1;
		cout<<"Case #"<<num++<<endl;
		cout<<s[0].name<<" 1"<<endl;
		for(int i=1;i<n;++i){
			if(s[i].mm == s[i-1].mm && s[i].ss == s[i-1].ss){
				cout<<s[i].name<<' '<<k<<endl;
			}
			else{
				cout<<s[i].name<<' '<<i+1<<endl;
				k=i+1;
			}
		}
	}
	return 0;
}