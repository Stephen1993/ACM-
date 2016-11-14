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

const int MAX=1<<15;
bool mark[MAX];
int s[MAX];

int main(){
	int n,m,k,a;
	while(cin>>n>>m){
		m=1<<(m+1);
		memset(s,0,sizeof s);
		memset(mark,false,sizeof mark);
		mark[0]=true;
		for(int i=0;i<n;++i){
			cin>>k;
			while(k--){
				cin>>a;
				s[i]=s[i]|(1<<a);
			}
			for(int j=0;j<m;++j){
				if(mark[j])mark[s[i]|j]=true;
			}
		}
		int num=0;
		for(int j=1;j<m;++j)num+=mark[j];
		cout<<num<<endl;
	}
	return 0;
}