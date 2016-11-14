#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=1000000+10;
int q,size;
int c[MAX];
char s[2][MAX];

int lowbit(int x){
	return x&(-x);
}

void Update(int x,int d){
	while(x<MAX){
		c[x]+=d;
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

int search(int left,int right){
	int l=left,ans=Query(left-1);
	while(left<=right){
		int mid=left+right>>1;
		int sum=Query(mid)-ans;
		if((mid-l+1)*2 == sum)left=mid+1;
		else right=mid-1;
	}
	return left-l;//right-l+1
}

int main(){
	int t,x,y,op,num=0;
	char ch[3];
	scanf("%d",&t);
	while(t--){
		memset(c,0,sizeof c);
		scanf("%s%s",s[0],s[1]);
		size=0;
		while(s[0][size] && s[1][size]){
			Update(size+1,1);
			if(s[0][size] == s[1][size])Update(size+1,1);
			++size;
		}
		scanf("%d",&q);
		printf("Case %d:\n",++num);
		for(int i=0;i<q;++i){
			scanf("%d",&op);
			if(op == 1){
				scanf("%d%d%s",&x,&y,ch);
				--x;
				if(s[x][y] != s[x^1][y] && ch[0] == s[x^1][y])Update(y+1,1);
				if(s[x][y] == s[x^1][y] && ch[0] != s[x][y])Update(y+1,-1);
				s[x][y]=ch[0];
			}else{
				scanf("%d",&y);
				printf("%d\n",search(y+1,size));
			}
		}
	}
	return 0;
}