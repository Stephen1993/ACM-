#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<vector>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=501;
int indegree[MAX],s[MAX];//记录点的入度和点拓扑排序后的顺序. 
//vector<int>marry[MAX];
bool marry[MAX][MAX];
int n,m;

void toposort(){
	int sum=-1,k=0;
	while(k<n && sum!=k){//sum!=k是判断是否剩下的点构成环,若构成环则无入度为0的点,则k不增加. 
		sum=k;
		for(int i=1;i<=n;++i){//int i=1,while(!indegree[i]) ++i;
			if(indegree[i]==0){
				indegree[i]--;//删除该点.
				s[k++]=i;
				for(int j=1;j<=n;++j){
					if(marry[i][j])indegree[j]--;//i连到的点入度减1. 
				}
				break; 
			}
		}
	} 
	if(k<n)cout<<"该有向图存在环!"<<endl;//有环则拓扑排序后的点不是全部的点. 
}

int main(){
	int a,b;
	while(cin>>n>>m){
		memset(indegree,0,sizeof(int)*(n+1));
		//for(int i=1;i<=n;++i)marry[i].clear();
		memset(marry,false,sizeof marry);
		for(int i=0;i<m;++i){
			cin>>a>>b;
			if(!marry[a][b]){//非重边则匹配且b的入度增加1. 
				indegree[b]++;
				marry[a][b]=true;
			}
			//marry[a].push_back(a);
		}
		toposort();
		cout<<s[0];
		for(int i=1;i<n;++i)cout<<' '<<s[i];
		cout<<endl;
	}
	return 0;
}
/*
可以用优先队列:
1.入度为空的入队,然后一个个出队输出.
2.与出队的那个点有相连的点的入度减1.//在减1之后就判断是否入度为0,为0就入队. 
3.循环执行1,2直到队列为空. 
*/
/*
可以用栈,但是无法按数字大小排序输出. 
1.先0入度的点入栈.
2.while(!stack.empty()){
	point=pop(s,i);cout<<point;++num;//输出i号并计数. 
	for(p=G.vertices[i].first;p;p=p->next){
		k=p->date;
		if(!(--indegree[k]))push(s,k);//若入度减为0,则入栈. 
	}
} 
if(num<G.num)return ERROR;//该图为有向图. 
*/
/*
tuopu排序，但是要求按序号排出，按普通的拓扑排序不行，所以就只有从前往后
扫描，每一趟只排一条边
以下是另一种拓扑排序,但在本题不能用,无法按数字大小排序输出. 
vector<int>g[N];//邻接表存储  
int vis[N],topo[N],cnt;  
  
bool dfs(int u)  
{  
    vis[u] = -1;//-1用来表示顶点u正在访问  
    for(int i = 0 ; i < g[u].size() ; i ++)  
    {  
        if(vis[g[u][i]] == -1)//表示这个点进入了两次，肯定出现了环  
            return false;  
        else if(vis[g[u][i]] == 0)  
        {  
            dfs(g[u][i]);  
        }  
    }  
    vis[u] = 1;  
    topo[cnt++] = u;//放到结果数组里，输出的时候记得倒序输出，（回溯的原因）  
    return true;  
}  
  
bool toposort(int n)  
{  
    memset(vis,0,sizeof(vis));  
    for(int i = 1 ; i <= n ; i ++)  
    {  
        if(!vis[i])  
        {  
            if(!dfs(i)) return false;//huan  
        }  
    }  
    return true;  
}  
*/