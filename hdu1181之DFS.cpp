#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=27;
vector<char>s[MAX];
bool flag;
bool mark[MAX];
bool dfs(int x){
	for(int i=0;i<s[x].size();++i){
		if(mark[s[x][i]-'a'])continue;
		if(s[x][i]=='m')return true;
		mark[s[x][i]-'a']=true;
		flag=dfs(s[x][i]-'a');
		if(flag)return true;
	}
	return false;
}
int main(){
	string a;
	while(cin>>a){
		if(a=="0"){
			cout<<"No."<<endl;
			continue;
		}
		for(int i=0;i<26;++i)s[i].clear();
		s[a[0]-'a'].push_back(a[a.size()-1]);
		flag=false;
		memset(mark,false,sizeof mark);
		mark[1]=true;
		while(cin>>a,a!="0"){
			s[a[0]-'a'].push_back(a[a.size()-1]);
		}
		if(dfs(1))cout<<"Yes."<<endl;
		else cout<<"No."<<endl;
	}
	return 0;
}
 