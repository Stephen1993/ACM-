/*分析:对于字符串a,b,c，由于c的长度一定是a和b的长度之和,所以对于用c匹配a,b到位置i,j
而匹配到i,j的方式可能很多,但是不管怎么匹配到i,j的,c剩余的字符一样,a,b剩余的也一样,
所以i,j后的匹配结果一样 
所以可以记忆化搜索防止重复去求匹配i,j后的结果
mark[i][j]记忆a,b在i,j后的匹配情况,0表示没匹配,1表示匹配成功,2表示匹配不成功 
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
	mark[i][j]=2;//2表示访问过但是不存在 
	if(a[i] == c[k])mark[i][j]=dfs(i+1,j,k+1);
	if(b[j] == c[k] && mark[i][j] != 1)mark[i][j]=dfs(i,j+1,k+1);//1表示访问过且存在 
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