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
const int MAX=6002;
int n;
typedef struct{//左二子右兄弟法建树
	int father;//父亲(父节点) 
	int child;//孩子(子节点) 
	int brother;//兄弟,即有同一个父亲(父节点). 
	int attend;//拿这个的价值 
	int not_attend;//不拿这个的价值 
	int max(){//比较拿与不拿时的最大值 
		return attend>not_attend?attend:not_attend;
	}
	void init(){//初始化 
		father=child=brother=attend=not_attend=0;
	}
}Kd_Trees;
Kd_Trees Tree_Node[MAX];
void DFS(int x){
	int child=Tree_Node[x].child;
	while(child){
		DFS(child);
		Tree_Node[x].attend+=Tree_Node[child].not_attend;
		Tree_Node[x].not_attend+=Tree_Node[child].max();
		child=Tree_Node[child].brother;
	}
	return;
}
int main(){
	int a,b;
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;++i){
			Tree_Node[i].init();
			scanf("%d",&Tree_Node[i].attend);
		}
		while(scanf("%d%d",&a,&b),a||b){
			Tree_Node[a].father=b;
			Tree_Node[a].brother=Tree_Node[b].child;//连接上一个b的孩子1->4->5->0. 
			Tree_Node[b].child=a;//b连接最后一个孩子b->1. 
		}
		int sum=0;//最大价值. 
		for(int i=1;i<=n;++i){
			if(Tree_Node[i].father==0){//如果该节点是根节点. 
				DFS(i);
				sum+=Tree_Node[i].max();//sum+=DFS(i)求的所有树的最大值(可能有多棵树). 
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}