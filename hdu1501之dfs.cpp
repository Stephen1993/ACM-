/*����:�����ַ���a,b,c������c�ĳ���һ����a��b�ĳ���֮��,���Զ�����cƥ��a,b��λ��i,j
��ƥ�䵽i,j�ķ�ʽ���ܺܶ�,���ǲ�����ôƥ�䵽i,j��,cʣ����ַ�һ��,a,bʣ���Ҳһ��,
����i,j���ƥ����һ�� 
���Կ��Լ��仯������ֹ�ظ�ȥ��ƥ��i,j��Ľ��
mark[i][j]����a,b��i,j���ƥ�����,0��ʾûƥ��,1��ʾƥ��ɹ�,2��ʾƥ�䲻�ɹ� 
*/
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

const int MAX=200+10;
char a[MAX],b[MAX],c[2*MAX];
int mark[MAX][MAX];

int dfs(int i,int j,int k){
	if(mark[i][j])return mark[i][j];
	if(c[k] == '\0')return 1;
	mark[i][j]=2;//2��ʾ���ʹ����ǲ����� 
	if(a[i] == c[k])mark[i][j]=dfs(i+1,j,k+1);
	if(b[j] == c[k] && mark[i][j] != 1)mark[i][j]=dfs(i,j+1,k+1);//1��ʾ���ʹ��Ҵ��� 
	return mark[i][j];
}

int main(){
	int t,num=0;
	scanf("%d",&t);
	while(t--){
		scanf("%s%s%s",a,b,c);
		memset(mark,0,sizeof mark);
		if(dfs(0,0,0) == 1)printf("Data set %d: yes\n",++num);
		else printf("Data set %d: no\n",++num);
	}
	return 0;
}