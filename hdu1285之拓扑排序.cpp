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
int indegree[MAX],s[MAX];//��¼�����Ⱥ͵�����������˳��. 
//vector<int>marry[MAX];
bool marry[MAX][MAX];
int n,m;

void toposort(){
	int sum=-1,k=0;
	while(k<n && sum!=k){//sum!=k���ж��Ƿ�ʣ�µĵ㹹�ɻ�,�����ɻ��������Ϊ0�ĵ�,��k������. 
		sum=k;
		for(int i=1;i<=n;++i){//int i=1,while(!indegree[i]) ++i;
			if(indegree[i]==0){
				indegree[i]--;//ɾ���õ�.
				s[k++]=i;
				for(int j=1;j<=n;++j){
					if(marry[i][j])indegree[j]--;//i�����ĵ���ȼ�1. 
				}
				break; 
			}
		}
	} 
	if(k<n)cout<<"������ͼ���ڻ�!"<<endl;//�л������������ĵ㲻��ȫ���ĵ�. 
}

int main(){
	int a,b;
	while(cin>>n>>m){
		memset(indegree,0,sizeof(int)*(n+1));
		//for(int i=1;i<=n;++i)marry[i].clear();
		memset(marry,false,sizeof marry);
		for(int i=0;i<m;++i){
			cin>>a>>b;
			if(!marry[a][b]){//���ر���ƥ����b���������1. 
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
���������ȶ���:
1.���Ϊ�յ����,Ȼ��һ�����������.
2.����ӵ��Ǹ����������ĵ����ȼ�1.//�ڼ�1֮����ж��Ƿ����Ϊ0,Ϊ0�����. 
3.ѭ��ִ��1,2ֱ������Ϊ��. 
*/
/*
������ջ,�����޷������ִ�С�������. 
1.��0��ȵĵ���ջ.
2.while(!stack.empty()){
	point=pop(s,i);cout<<point;++num;//���i�Ų�����. 
	for(p=G.vertices[i].first;p;p=p->next){
		k=p->date;
		if(!(--indegree[k]))push(s,k);//����ȼ�Ϊ0,����ջ. 
	}
} 
if(num<G.num)return ERROR;//��ͼΪ����ͼ. 
*/
/*
tuopu���򣬵���Ҫ������ų�������ͨ�����������У����Ծ�ֻ�д�ǰ����
ɨ�裬ÿһ��ֻ��һ����
��������һ����������,���ڱ��ⲻ����,�޷������ִ�С�������. 
vector<int>g[N];//�ڽӱ�洢  
int vis[N],topo[N],cnt;  
  
bool dfs(int u)  
{  
    vis[u] = -1;//-1������ʾ����u���ڷ���  
    for(int i = 0 ; i < g[u].size() ; i ++)  
    {  
        if(vis[g[u][i]] == -1)//��ʾ�������������Σ��϶������˻�  
            return false;  
        else if(vis[g[u][i]] == 0)  
        {  
            dfs(g[u][i]);  
        }  
    }  
    vis[u] = 1;  
    topo[cnt++] = u;//�ŵ��������������ʱ��ǵõ�������������ݵ�ԭ��  
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