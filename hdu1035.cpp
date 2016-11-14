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
const int MAX=12;
char s[MAX][MAX];
int mark[MAX][MAX];
int n,m,start;
int main(){
	int x,y;
	while(cin>>n>>m,n&&m){
		cin>>start;
		memset(mark,0,sizeof mark);
		for(int i=0;i<n;++i){
			cin>>s[i];
		}
		int sum=0;
		bool flag=false;
		x=(start-1)/m;
		y=(start-1)%m;
		while(x>=0&&y>=0&&x<n&&y<m){
			if(mark[x][y]){
				sum++;
				flag=true;
				break;
			}
			mark[x][y]=sum+1;
			sum=mark[x][y];
			if(s[x][y]=='N'){
				x--;
			}
			else if(s[x][y]=='S'){
				x++;
			}
			else if(s[x][y]=='E'){
				y++;
			}
			else{
				y--;
			}
		}
		if(flag){
			cout<<mark[x][y]-1<<" step(s) before a loop of "<<sum-mark[x][y]<<" step(s)"<<endl;
		}
		else{
			cout<<sum<<" step(s) to exit"<<endl;
		}
	}
	return 0;
}