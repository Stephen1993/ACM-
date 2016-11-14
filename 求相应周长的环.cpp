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
int len[MAX],node[MAX];//len��¼��i������ʼ�㳤��,node��¼������ʼ����Ӧ���ȵĵ�
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
		for(int l=1;;++l){//l����Ѱ�ҵ�ǰ���ȵĵ� 
			for(int i=0;i<e[u].size();++i){
				int v=e[u][i];
				if(len[v]){//�ĵ��ѱ����ӹ�,����ʱ������һ���� 
					int L=l-len[v];
					if(L>=k+1){
						cout<<L<<endl;
						for(int j=len[v];j<l;++j){//������ϵ����е�(���г��ȶ�Ӧ�ĵ�)
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