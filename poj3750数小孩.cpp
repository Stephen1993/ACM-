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
		while(n){//n代表小孩未出队的数量 
			for(int i=1;i<s;++i){//从w位置开始数小孩 
				w++;
				if(w>n){//当数到最后一个小孩的下一位时则为第一个小孩. 
					w=1;
				}
			}
			cout<<child[w]<<endl;
			for(int i=w;i<n;++i){//每次出队一个则将该出队小孩后的小孩前移. 
				child[i]=child[i+1];
			}
			n--;//小孩数量减1. 
		}
	}
	return 0;
}


