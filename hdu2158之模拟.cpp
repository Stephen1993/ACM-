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

const int MAX=100000+10;
int s[MAX],num[MAX],pos[MAX];//pos记录i的第一个位置
int mark[MAX];//标记 

int main(){
	int n,m,q,a;
	while(cin>>n>>m,n+m){
		memset(mark,0,sizeof mark);
		memset(pos,-1,sizeof pos);
		for(int i=0;i<n;++i){
			scanf("%d",&s[i]);
			if(pos[s[i]] == -1)pos[s[i]]=i;//记录s[i]的第一个位置 
		}
		s[n]=n;
		for(int i=1;i<=m;++i){
			scanf("%d",&q);
			int l=n,r=-1,maxlen=INF;
			for(int j=0;j<q;++j){
				scanf("%d",&a);
				num[a]=0;
				mark[a]=i;//标记a出现过 
				if(pos[a]>r)r=pos[a];//找到出现过的a的最右端位置 
				if(pos[a]<l)l=pos[a];//找到出现过的a的最左端位置 
			}
			for(int j=l;j<=r;++j)++num[s[j]];//在l,r之简单出现过多少a 
			maxlen=r-l+1;//初始化最短区间长度 
			while(r<n){
				--num[s[l]];//左端点向右移,出现过的a的次数减1 
				if(num[s[l]] == 0){//如果新的[l,r]没有了s[l]则右端点右移 
					while(++r<n && s[r] != s[l])++num[s[r]];//维护r使区间[l,r]包含m个数 
					num[s[r]]=1;//直到找到了s[l]=s[r],则个数+1 
				}
				while(++l<=r && mark[s[l]] != i);//l每次都到下一个输入过的点a
				if(r<n && maxlen>r-l+1)maxlen=r-l+1;//更新最短区间长度 
			}
			cout<<maxlen<<endl;
		}
	}
	return 0;
}