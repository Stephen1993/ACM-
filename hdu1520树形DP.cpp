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
typedef struct{//��������ֵܷ�����
	int father;//����(���ڵ�) 
	int child;//����(�ӽڵ�) 
	int brother;//�ֵ�,����ͬһ������(���ڵ�). 
	int attend;//������ļ�ֵ 
	int not_attend;//��������ļ�ֵ 
	int max(){//�Ƚ����벻��ʱ�����ֵ 
		return attend>not_attend?attend:not_attend;
	}
	void init(){//��ʼ�� 
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
			Tree_Node[a].brother=Tree_Node[b].child;//������һ��b�ĺ���1->4->5->0. 
			Tree_Node[b].child=a;//b�������һ������b->1. 
		}
		int sum=0;//����ֵ. 
		for(int i=1;i<=n;++i){
			if(Tree_Node[i].father==0){//����ýڵ��Ǹ��ڵ�. 
				DFS(i);
				sum+=Tree_Node[i].max();//sum+=DFS(i)��������������ֵ(�����ж����). 
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}