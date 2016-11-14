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

const int MAX=100001;
int len[MAX],node[MAX];//len记录点i距离起始点长度,node记录距离起始点相应长度的点
vector<int>e[MAX];

int main(){
	int n,m,k,a,b;
	while(cin>>n>>m>>k){
		for(int i=1;i<=n;++i)e[i].clear();
		for(int i=0;i<m;++i){
			scanf("%d%d",&a,&b);
			e[a].push_back(b);
			e[b].push_back(a);
		}
		for(int i=1;i<=n;++i)len[i]=0;
		int u=1;
		for(int l=1;;++l){//l代表寻找当前长度的点 
			for(int i=0;i<e[u].size();++i){
				int v=e[u][i];
				if(len[v]){//改点已被连接过,即此时构成了一个环 
					int L=l-len[v];
					if(L>=k+1){
						cout<<L<<endl;
						for(int j=len[v];j<l;++j){//输出环上的所有点(所有长度对应的点)
							printf("%d%c",node[j],j == l-1 ? '\n' : ' ');
						}
						return 0;
					}
				}
				else{
					len[v]=l;
					node[l]=u=v;
					break;
				}
			}
		}
		cout<<endl;
	}
	return 0;
} 