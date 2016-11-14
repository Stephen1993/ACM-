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

const int MAX=50000+10;
const int mod=300;
int father[MAX],dist[MAX],sum;

void makeset(int num){
	for(int i=0;i<=num;++i){
		father[i]=i,dist[i]=0;
	}
}

int findset(int v){
	if(v == father[v])return father[v];
	int temp=findset(father[v]);
	dist[v]=(dist[v]+dist[father[v]])%mod;//�ڵݹ���ݵ�ʱ�����ӽڵ㵽���ڵ�ľ��� 
	father[v]=temp;
	return father[v]; 
}

void Union(int x,int y,int l){
	int a=findset(x);
	int b=findset(y);
	if(a == b){
		if((dist[y]-dist[x]+mod)%mod != l)++sum;
	}
	else{
		dist[b]=dist[x]+l-dist[y];//y�ĸ��ڵ�b��a�ľ���
		if(dist[b]<0)dist[b]+=300;//b��a����� 
		if(dist[b]>=mod)dist[b]%=mod;//b����λ��˳ʱ��һ��Ȧ�ƻ�ȥ�� 
		father[b]=a; 
	}
}

int main(){
	int n,m,a,b,c;
	while(scanf("%d%d",&n,&m)!=EOF){
		makeset(n);
		sum=0;
		for(int i=0;i<m;++i){
			scanf("%d%d%d",&a,&b,&c);
			Union(a,b,c);
		}
		cout<<sum<<endl;
	}
	return 0;
} 