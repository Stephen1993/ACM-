#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 999999999
using namespace std;

const int MAX=1001;
char s[MAX][2];

int dfs(char a,char b,char c,int num,char d){
	if(a == b && a == c)return 0;
	if(b == d || c == d)return num;
	int sum=0;
	if(a != b)sum=dfs(b,s[b][0],s[b][1],num+1,d);
	if(!sum)
	if(a != c)sum=dfs(c,s[c][0],s[c][1],num+1,d);
	return sum;
}

int main(){
	int n,m;
	char a,b,c;
	while(cin>>n>>m,n || m){
		for(int i=0;i<MAX;++i)s[i][0]=s[i][1]=i;
		for(int i=0;i<n;++i){
			cin>>a>>b>>c;
			s[a][0]=b,s[a][1]=c;
		}
		for(int i=0;i<m;++i){
			cin>>a>>b;
			int num=0;
			num=dfs(a,s[a][0],s[a][1],1,b);
			if(num){
				if(num == 1)cout<<"child"<<endl;
				while(num >= 3)cout<<"great-",--num;
				if(num == 2)cout<<"grandchild"<<endl;
			}
			else{
				num=dfs(b,s[b][0],s[b][1],1,a);
				if(!num)cout<<"-"<<endl;
				if(num == 1)cout<<"parent"<<endl;
				while(num >= 3)cout<<"great-",--num;
				if(num == 2)cout<<"grandparent"<<endl;
			}
		}
	}
	return 0;
}