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

const int MAX=10000+1;
char op[10];
int p[MAX],rear[MAX];

struct People{
	char name[22];
	int RP;
	bool operator<(const People &a)const{
		if(RP == a.RP)return strcmp(name,a.name)<0;//字典序从大到小排序
		return RP>a.RP;//从小到大排序,队首是最小的
	}
}s,temp;
priority_queue<People>q[MAX];

void Free(int &n){
    for(int i=1;i<=n;++i){
        while(!q[i].empty())q[i].pop();
    }
}

int main(){
	int n,m,k,xi,xj;
	while(cin>>n>>m){
		for(int i=1;i<=n;++i){
			scanf("%d",&k);
			for(int j=0;j<k;++j){
				scanf("%s%d",s.name,&s.RP);
				q[i].push(s);
			}
			p[i]=i;//p表示合并后的车辆,p[i]=j表示车辆i后面连着车辆j
			rear[i]=i;//记录p[i]的末尾
		}
		for(int i=0;i<m;++i){
			scanf("%s",op);
			if(op[4] == 'N'){
				scanf("%d%s%d",&xi,s.name,&s.RP);
				q[xi].push(s);
			}else if(op[4] == 'U'){
				scanf("%d",&xi);
				xj=k=xi;
				s=q[xi].top();
				while(p[k] != k){
					temp=q[p[k]].top();
					if(temp.RP<s.RP || (temp.RP == s.RP && strcmp(temp.name,s.name)>0))s=temp,xj=p[k];
					k=p[k];
				}
				temp=q[p[k]].top();
				if(temp.RP<s.RP || (temp.RP == s.RP && strcmp(temp.name,s.name)>0))s=temp,xj=p[k];
				q[xj].pop();
				printf("%s\n",s.name);
			}else{
				scanf("%d%d",&xi,&xj);
				p[rear[xi]]=xj;
				rear[xi]=rear[xj];
			}
		}
		Free(n);
	}
	return 0;
}
