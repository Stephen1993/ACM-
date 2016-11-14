#include<iostream>
using namespace std;
const int MAX=30010;
int father[MAX],rank[MAX];

void makset(int num){
	for(int i=0;i<num;++i){
		father[i]=i;
	    rank[i]=1;
	}
}

int find_set(int v){
	if(v!=father[v]){
		father[v]=find_set(father[v]);
	}
	return father[v];
}

void Union(int x,int y){
	int a=find_set(x);
	int b=find_set(y);
	if(a==b)return;
	if(rank[a]>rank[b]){
		father[b]=a;
		rank[a]+=rank[b];
	}
	else{
		father[a]=b;
		rank[b]+=rank[a];
	}
}

int main(){
	int n,m,reg,first,next;
	while(cin>>n>>m,n){
		makset(n);
		for(int i=0;i<m;++i){
			cin>>reg>>first;
			for(int j=1;j<reg;++j){
				cin>>next;
				Union(first,next);
			}
		}
		cout<<rank[find_set(0)]<<endl;
	}
	return 0;
}