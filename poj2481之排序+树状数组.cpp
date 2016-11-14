/*题意大意：
FJ有n头牛(编号为1~n)，每一头牛都有一个测验值（S，E），对于牛i和牛j来说，
如果它们的测验值满足下面的条件则表示牛i比牛j强壮：Si <= Sj and Ej <= Ei and Ei - Si > Ej - Sj。
现在已知每一头牛的测验值，要求输出每头牛有几头牛比其强壮。

分析:对n个数根据ei>ej或者ei == ej && si<sj进行排序，这样排完序后只要按顺序扫描数组
对于s[j]前面的数组e[k]>=e[j],所以只要求出在s[j]之前有多少s[k]<=s[j]即可，
另外如果e[k]=e[j]还需要减去s[k]=s[j]的个数，这个个数可以在扫描数组的过程中进行统计
具体看代码 
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=100000+10;
int n;
int num[MAX],c[MAX];

struct Node{
	int s,e,id;
	bool operator<(const Node &a)const{
		if(e == a.e)return s<a.s;
		return e>a.e;
	}
}s[MAX];

int lowbit(int x){
	return x&(-x);
}

void Update(int x){
	while(x<MAX){
		c[x]+=1;
		x+=lowbit(x);
	}
}

int Query(int x){
	int sum=0;
	while(x>0){
		sum+=c[x];
		x-=lowbit(x);
	}
	return sum;
}

int main(){
	while(~scanf("%d",&n),n){
		memset(c,0,sizeof c); 
		for(int i=0;i<n;++i){
			scanf("%d%d",&s[i].s,&s[i].e);
			++s[i].s,++s[i].e;
			s[i].id=i;
		}
		sort(s,s+n);
		num[s[0].id]=0;
		Update(s[0].s);
		int ans=0;//ans记录在i之前s[k] == s[i]的个数
		if(s[0].e == s[1].e && s[0].s == s[1].s)++ans;
		for(int i=1;i<n;++i){
			int sum=Query(s[i].s)-ans;
			if(s[i].e == s[i+1].e && s[i].s == s[i+1].s)++ans;
			else ans=0;
			num[s[i].id]=sum;
			Update(s[i].s);
		}
		/*for(int i=1;i<n;++i){
			if(s[i].e == s[i-1].e && s[i].s == s[i-1].s)num[s[i].id]=num[s[i-1].id];
			else num[s[i].id]=Query(s[i].s);
			Update(s[i].s);
		}*/
		printf("%d",num[0]);
		for(int i=1;i<n;++i)printf(" %d",num[i]);
		printf("\n");
	}
	return 0;
}
