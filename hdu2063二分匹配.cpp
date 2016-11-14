#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<iomanip>
#define INF 999999
using namespace std;
const int MAX=1111;
bool marry[MAX][MAX],mark[MAX];//marry[i][j]��ʾi��j����ƥ��,mark[i]��ʾ��ǿ���ƥ���i���Ƿ�ƥ���.
int link[MAX];//link[i]��ʾi��link[i]ƥ��.
int k,n,m;
bool find(int x){
	for(int i=1;i<=n;++i){//Ѱ��i�Ƿ���Ժ�xƥ�� 
		if(!mark[i]&&marry[x][i]){
			mark[i]=true;
			if(!link[i]||find(link[i])){
				link[i]=x;//��ʾx��iƥ�䡣 
				return true;
			}
		}
	}
	return false;
}
int hungarian_algorithm(){
	int num=0;
	for(int i=1;i<=m;++i){
		memset(mark,false,sizeof mark);
		if(find(i))num++;
	}
	return num;
} 
int main(){
	while(cin>>k,k){
		int a,b;
		cin>>m>>n;
		memset(link,0,sizeof link);
		memset(marry,false,sizeof marry);
		for(int i=0;i<k;++i){
			scanf("%d%d",&a,&b);
			marry[a][b]=true;
		}
		int sum=hungarian_algorithm();
		cout<<sum<<endl;
	}
	return 0;
} 