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

const int MAX=10+10;
bool mark[MAX][MAX];
int n,m,k,a,sum;
int father[MAX];

void dfs(int id,int num){
	if(num>m)return;
	if(sum != -1)return;
	if(id == n){sum=num;return;}
	dfs(id+1,num+1);
	for(int i=0;i<id;++i){
		if(father[i] != i)continue;//�Ҽ��ϵĸ� 
		int temp=1;
		for(int j=i;j<id && temp;++j){
			if(father[j] == i)temp=mark[id][j];//�жϸõ��Ƿ��ܽ��뼯��i(���Ƿ�ͼ����е��˻���ϲ��) 
		}
		if(temp){father[id]=i;dfs(id+1,num);}//���������õ���Խ��뼯�� 
	}
	father[id]=id;
}

void Init(int &n){
	memset(mark,false,sizeof mark);
	for(int i=0;i<n;++i)father[i]=i;
}

int main(){
	while(cin>>n>>m){
		Init(n);
		for(int i=0;i<n;++i){
			cin>>k;
			while(k--){
				cin>>a;
				mark[i][a]=true;
			}
		}
		sum=-1;
		dfs(1,1);//��ѯ��һ�����������Ϻ����м������� 
		if(sum != -1)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}