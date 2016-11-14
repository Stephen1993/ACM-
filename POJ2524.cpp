#include<iostream>
using namespace std;

const int MAX=50005;
int father[MAX],rank[MAX];
int n,m;

void makeset(int num){
	for(int i=1;i<=num;++i){
		father[i]=i;
		rank[i]=1;
	}
}

int findset(int v){
	if(v!=father[v]){
		father[v]=findset(father[v]);
	}
	return father[v];
}

void Union(int x,int y){
	int a=findset(x);
	int b=findset(y);
	if(a==b)return;
	if(rank[a]>rank[b]){
		father[b]=a;
		rank[a]+=rank[b];
		n--;
	}
	else{
		father[a]=b;
		rank[b]+=rank[a];
		n--;
	}
}

int main(){
	int sum=1;
	while(cin>>n>>m,n){
		makeset(n);
		int c,d;
		for(int i=0;i<m;++i){
			cin>>c>>d;
			Union(c,d);
		}
		cout<<"Case "<<sum++<<": "<<n<<endl;
	}
	return 0;
}