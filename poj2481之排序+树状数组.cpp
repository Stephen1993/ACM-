/*������⣺
FJ��nͷţ(���Ϊ1~n)��ÿһͷţ����һ������ֵ��S��E��������ţi��ţj��˵��
������ǵĲ���ֵ����������������ʾţi��ţjǿ׳��Si <= Sj and Ej <= Ei and Ei - Si > Ej - Sj��
������֪ÿһͷţ�Ĳ���ֵ��Ҫ�����ÿͷţ�м�ͷţ����ǿ׳��

����:��n��������ei>ej����ei == ej && si<sj�������������������ֻҪ��˳��ɨ������
����s[j]ǰ�������e[k]>=e[j],����ֻҪ�����s[j]֮ǰ�ж���s[k]<=s[j]���ɣ�
�������e[k]=e[j]����Ҫ��ȥs[k]=s[j]�ĸ������������������ɨ������Ĺ����н���ͳ��
���忴���� 
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
		int ans=0;//ans��¼��i֮ǰs[k] == s[i]�ĸ���
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
