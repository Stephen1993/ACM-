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
	   由于网站每次重复执行代码,静态变量定义运行程序时自动赋值false,所以不需要这个,甚至不需要while. 
	   在国外网站代码都是重复执行,所以不需要while也会重复运行,一些静态变量就不需要担心上次的结果影响.
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
				sum++;//有几个环就加几次. 
			}
		}
		sum--;//两个环之间才加一次.
		if(sum<0)sum=0;
		cout<<sum<<endl;
	}
	return 0;
}