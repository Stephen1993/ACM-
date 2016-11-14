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
#define INF 999999
using namespace std;
const int MAX=50005;
map<string,int>hat;
int main(){
	string s[MAX];
	int n=0;
	while(cin>>s[n]){
		hat[s[n++]]=1;
	}
	for(int i=0;i<n;++i){
		for(int j=1;j<s[i].size();++j){
			string s1(s[i],0,j);
			string s2(s[i],j);
			if(hat[s1]&&hat[s2]){
				cout<<s[i]<<endl;
				break;
			}
		}
	}
	return 0;
} 