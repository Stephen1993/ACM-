/*�Ż������� 
���ڸ������γ�������֮�䲻��ѡ֮��û������Լ������
����ÿһ�е�״̬�Լ�״̬����ʵ��һ���ģ����ԾͲ���1~n��ÿ�ζ�����е�״̬�Լ�״̬��
ֻҪ��һ�߼���,Ȼ���״̬�Լ�״̬������ò��Ҷ���״̬i,���ڽӾ��󴢴��״̬i�����״̬
Ȼ����ڵ�k�е�i��״̬,ֻ��Ҫ�����ڽӱ�ö�ٺ�i�����״̬����dp[k][i]���� 
*/
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=17711+10;
int n,nowsize,size;
int dp[MAX],temp[MAX],ans[MAX],now[MAX];
int w[22][22],head[MAX];

struct Edge{
	int v,next;
	Edge(){}
	Edge(int V,int NEXT):v(V),next(NEXT){}
}edge[3000000];

void Init(){
	memset(dp,0,sizeof dp);
	memset(temp,0,sizeof temp);
	memset(head,-1,sizeof head);
	size=nowsize=0;
}

void InsertEdge(int u,int v){
	edge[size]=Edge(v,head[u]);
	head[u]=size++;
}

void dfs(int k,int p){
	if(k>=n){now[++nowsize]=p;return;}
	dfs(k+2,p|(1<<k));
	dfs(k+1,p);
}

int cal(int k,int p){
	int sum=0;
	for(int i=0;i<20;++i){
		if(p & (1<<i))sum+=w[k][i];
	}
	return sum;
}

void DP(){
	dfs(0,0);
	for(int i=1;i<=nowsize;++i){//�˴����Ż�,�����ڽӱ���״̬ 
		for(int j=i+1;j<=nowsize;++j){
			if(now[i] & now[j])continue;
			InsertEdge(i,j);
			InsertEdge(j,i);
		}
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=nowsize;++i){
			ans[i]=cal(k,now[i]);
			for(int j=head[i];j != -1;j=edge[j].next){
				dp[i]=max(dp[i],temp[edge[j].v]+ans[i]);
			}
		}
		for(int i=1;i<=nowsize;++i)temp[i]=dp[i],dp[i]=0;
	}
}

int main(){
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;++i){
			for(int j=0;j<n;++j)scanf("%d",&w[i][j]);
		}
		Init();
		DP();
		int sum=0;
		for(int i=1;i<=nowsize;++i)sum=max(sum,temp[i]);
		printf("%d\n",sum);
	}
	return 0;
}
/*δ�Ż��ģ�
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=17711+10;
int n,nowsize,lastsize;
int now[MAX],last[MAX];
int dp[MAX],temp[MAX],ans[MAX];
int w[22][22];

void dfs(int id,int k,int p,int sum){
	if(k>=n){now[++nowsize]=p;ans[nowsize]=sum;return;}
	dfs(id,k+2,p|(1<<k),sum+w[id][k]);
	dfs(id,k+1,p,sum);
}

void DP(){
	for(int k=1;k<=n;++k){
		nowsize=0;
		dfs(k,0,0,0);
		for(int i=1;i<=nowsize;++i)dp[i]=0;
		for(int i=1;i<=nowsize;++i){
			for(int j=1;j<=lastsize;++j){
				if(now[i] & last[j])continue;
				dp[i]=max(dp[i],temp[j]+ans[i]);
			}
		}
		for(int i=1;i<=nowsize;++i)temp[i]=dp[i];
		for(int i=1;i<=nowsize;++i)last[i]=now[i];
		lastsize=nowsize;
	}
}

int main(){
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;++i){
			for(int j=0;j<n;++j)scanf("%d",&w[i][j]);
		}
		temp[1]=last[1]=0;
		lastsize=1;
		DP();
		int sum=0;
		for(int i=1;i<=lastsize;++i)sum=max(sum,temp[i]);
		printf("%d\n",sum);
	}
	return 0;
} 
*/ 