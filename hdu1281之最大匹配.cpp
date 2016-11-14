//行和列匹配,第i行和第j列成功匹配则第i行和第j列不能使用.
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#include<vector>
#define INF 99999999
using namespace std;

const int MAX=111;
int link[MAX],n,m,k;
bool mark[MAX],marry[MAX][MAX];
int s[MAX*MAX][2];
//vector<int>marry[MAX];

bool find(int v){
	for(int i=1;i<=m;++i){
		if(!mark[i] && marry[v][i]){
			mark[i]=true;
			if(!link[i] || find(link[i])){
				link[i]=v;
				return true;
			}
		}
	}
	return false;
}

int xiongyali(){
	int num=0;
	for(int i=1;i<=n;++i){
		memset(mark,false,sizeof(bool)*(m+1));
		if(find(i))num++;
	}
	return num;
}

void output(int sum,int t){
	int num=0;
	for(int i=0;i<k;++i){//寻找关键点. 
     	memset(link,0,sizeof(int)*(m+1));
		marry[s[i][0]][s[i][1]]=false;
		if(xiongyali()<sum)num++;//如果改点是关键点则最大匹配数应该减少. 
		marry[s[i][0]][s[i][1]]=true;
	}
	cout<<"Board "<<t<<" have "<<num<<" important blanks for "<<sum<<" chessmen."<<endl;
	return;
}

int main(){
	int a,b,t=0;
	while(cin>>n>>m>>k){
		//for(int i=1;i<=n;++i)marry[i].clear();
		memset(link,0,sizeof(int)*(m+1));
		/*for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				marry[i][j]=false;
			}
		}*/
		memset(marry,false,sizeof marry);
		for(int i=0;i<k;++i){
			cin>>a>>b;
			//marry[i].push_back(b);
			marry[a][b]=true;
			s[i][0]=a,s[i][1]=b;
		}
		int sum=xiongyali(); 
		output(sum,++t);
	}
	return 0;
}

