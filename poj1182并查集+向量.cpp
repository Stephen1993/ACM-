#include<iostream>
#include<cstdio>
using namespace std;

const int MAX=50005;
int father[MAX],rank[MAX]={0};

void makeset(int num){
	for(int i=1;i<=num;++i){
		father[i]=i;
	}
}

int findset(int v){
	if(father[v]!=v){
		int t=father[v];
		father[v]=findset(father[v]);
		rank[v]=(rank[v]+rank[t])%3;//v->t=rank[v],t->n=rank[t]=>v->n=rank[v]+rank[t]; 
	}
	return father[v];
}

void Union(int s,int t,int D){
	int A=findset(s);
	int B=findset(t);
	father[A]=findset(B);
	rank[A]=(rank[t]-rank[s]+D+3)%3;//运用向量四则运算 
}

int main(){
	int sum=0;
	int n,m,d,x,y;
	scanf("%d%d",&n,&m);
	//cin>>n>>m;
	makeset(n);
	for(int i=0;i<m;++i){
		scanf("%d%d%d",&d,&x,&y);
		//cin>>d>>x>>y;
		if(x>n||y>n||(d==2&&x==y)){
			sum++;
		}
		else{
			int a=findset(x);
			int b=findset(y);
			if(a==b){
				if((rank[x]-rank[y]+3)%3!=d-1){//x->n=rank[x],y->n=rank[y]=>x->=rank[x]-rank[y]; 
					sum++;
				}
			}
			else{
				Union(x,y,d-1);
			}
		}
	}
	printf("%d\n",sum);
	//cout<<sum<<endl;
	return 0;
}