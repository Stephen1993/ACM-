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

const int MAX=501;
int father[MAX],rank1[MAX];
bool mark[MAX];

void makeset(int num){
	for(int i=1;i<=num;++i){
		father[i]=i;
		rank1[i]=1;
	}
}

int findset(int v){
	if(v != father[v]){
		father[v]=findset(father[v]);
	}
	return father[v];
}

void Union(int x,int y){
	int a=findset(x);
	int b=findset(y);
	if(x==y)return;
	if(rank1[a]>rank1[b]){
		father[b]=a;
		rank1[a]+=rank1[b];
	}
	else{
		father[a]=b;
		rank1[b]+=rank1[a];
	}
	return;
}

int main(){
	int n,m,a;
	while(scanf("%d%d",&n,&m)!=EOF){
		makeset(n);
		int sum=0;
		//memset(mark,false,sizeof(bool)*(n+1));
	   /*
	   ������վÿ���ظ�ִ�д���,��̬�����������г���ʱ�Զ���ֵfalse,���Բ���Ҫ���,��������Ҫwhile. 
	   �ڹ�����վ���붼���ظ�ִ��,���Բ���ҪwhileҲ���ظ�����,һЩ��̬�����Ͳ���Ҫ�����ϴεĽ��Ӱ��.
	  */ 
		for(int i=1;i<=n;++i){
			for(int j=0;j<m;++j){
				scanf("%d",&a);
				if(a != i){
					Union(a,i);
					sum++;
					mark[a]=true;
				}
			}
		}
		for(int i=1;i<=n;++i){
			if(mark[i] && father[i] == i){
				sum++;//�м������ͼӼ���. 
			}
		}
		sum--;//������֮��ż�һ��.
		if(sum<0)sum=0;
		cout<<sum<<endl;
	}
	return 0;
}