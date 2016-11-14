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

const int MAX=10001;
vector<int>Tree_Node[MAX];//记录每个节点的儿子. 
vector<int>Tree_length[MAX];//记录节点到它每个儿子之间的距离. 
int first_long[MAX],second_long[MAX],direction[MAX];//分别记录最长距离，次长距离，节点最长距离的方向 
template<typename T>T up_max(T a,T b,T c,T d){return a>b?a:(direction[c]=d,second_long[c]=a,b);}
int n;

void DFS(int x){//更新所有节点到它儿子的最大距离和次大距离. 
	int child,length=0;
	for(int i=0;i<Tree_Node[x].size();++i){
		child=Tree_Node[x][i];//相应的儿子 
		length=Tree_length[x][i];//相应的节点到该儿子之间的距离 
		DFS(child);
		second_long[x]=max(second_long[x],length+first_long[child]);//找寻节点到它所有儿子的最大距离和次大距离 
		first_long[x]=up_max(first_long[x],first_long[child]+length,x,child);
	}
}

void DFS2(int x,int father,int length){//通过节点的父亲来更新它的最大距离和次大距离 
	if(x!=1){
		if(direction[father]!=x){//如果节点的父亲的最长距离不包含该节点，则用该父亲的最长距离来更新 
			second_long[x]=max(second_long[x],min(first_long[x],first_long[father]+length));
			first_long[x]=up_max(first_long[x],first_long[father]+length,x,father);
		}
		else{//否则用次长距离来更新. 
			second_long[x]=max(second_long[x],min(first_long[x],second_long[father]+length));
			first_long[x]=up_max(first_long[x],second_long[father]+length,x,father);
		}
	}
	for(int i=0;i<Tree_Node[x].size();++i){
		DFS2(Tree_Node[x][i],x,Tree_length[x][i]);
	}
}

int main(){
	int a,b;
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;++i){
			first_long[i]=second_long[i]=direction[i]=0;
		}
		for(int i=1;i<=n;++i){
			Tree_length[i].clear();
			Tree_Node[i].clear();
		}
		for(int i=2;i<=n;++i){
			scanf("%d%d",&a,&b);
			Tree_Node[a].push_back(i);
			Tree_length[a].push_back(b);
		}
		DFS(1);
		DFS2(1,0,0);
		for(int i=1;i<=n;++i){
			cout<<first_long[i]<<endl;
		}
	}
	return 0;
}