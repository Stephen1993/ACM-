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
vector<int>Tree_Node[MAX];//��¼ÿ���ڵ�Ķ���. 
vector<int>Tree_length[MAX];//��¼�ڵ㵽��ÿ������֮��ľ���. 
int first_long[MAX],second_long[MAX],direction[MAX];//�ֱ��¼����룬�γ����룬�ڵ������ķ��� 
template<typename T>T up_max(T a,T b,T c,T d){return a>b?a:(direction[c]=d,second_long[c]=a,b);}
int n;

void DFS(int x){//�������нڵ㵽�����ӵ�������ʹδ����. 
	int child,length=0;
	for(int i=0;i<Tree_Node[x].size();++i){
		child=Tree_Node[x][i];//��Ӧ�Ķ��� 
		length=Tree_length[x][i];//��Ӧ�Ľڵ㵽�ö���֮��ľ��� 
		DFS(child);
		second_long[x]=max(second_long[x],length+first_long[child]);//��Ѱ�ڵ㵽�����ж��ӵ�������ʹδ���� 
		first_long[x]=up_max(first_long[x],first_long[child]+length,x,child);
	}
}

void DFS2(int x,int father,int length){//ͨ���ڵ�ĸ�������������������ʹδ���� 
	if(x!=1){
		if(direction[father]!=x){//����ڵ�ĸ��׵�����벻�����ýڵ㣬���øø��׵������������ 
			second_long[x]=max(second_long[x],min(first_long[x],first_long[father]+length));
			first_long[x]=up_max(first_long[x],first_long[father]+length,x,father);
		}
		else{//�����ôγ�����������. 
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