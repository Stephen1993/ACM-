#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 999999
using namespace std;

const int MAX=100;
string child[MAX];
int n,w,s;

int main(){
	int num;
	while(cin>>n){
		for(int i=1;i<=n;++i){
			cin>>child[i];
		}
		scanf("%d,%d",&w,&s);
		while(n){//n����С��δ���ӵ����� 
			for(int i=1;i<s;++i){//��wλ�ÿ�ʼ��С�� 
				w++;
				if(w>n){//���������һ��С������һλʱ��Ϊ��һ��С��. 
					w=1;
				}
			}
			cout<<child[w]<<endl;
			for(int i=w;i<n;++i){//ÿ�γ���һ���򽫸ó���С�����С��ǰ��. 
				child[i]=child[i+1];
			}
			n--;//С��������1. 
		}
	}
	return 0;
}


