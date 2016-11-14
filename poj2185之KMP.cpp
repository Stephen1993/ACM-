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

const int MAX=10000+10;
char s[MAX][77];
int rnum[77],next[MAX];

int get_next(int n){
	int i=-1,j=0;
	next[0]=-1;
	while(j<n){
		if(i == -1 || strcmp(s[i],s[j]) == 0)next[++j]=++i;//把每一行看成一个字符求next 
		else i=next[i];
	}
	return n-next[n];
}

int main(){
	int r,w,x,y;
	while(cin>>r>>w){
		memset(rnum,0,sizeof rnum);
		for(int i=0;i<r;++i){
			cin>>s[i];
			for(int j=1;j<=w;++j){
				for(x=0,y=j;y<w;++x,++y){
					if(s[i][x%j] != s[i][y])break;//判断是否是循环周期 
				}
				if(y == w)++rnum[j];//统计所有循环周期长度的个数,如aaaaa就有a,aa,aaa,aaaa,aaaaa多个循环周期 
			}
		}//求y也可以和列一样求法,但是比较每一列字符串却比较难,所以用暴力统计(上面是暴利统计)去求 
		for(y=1;y<=w;++y)if(rnum[y] == r)break;//求所有行共同最小周期y,0~y-1为一个周期 
		for(int i=0;i<r;++i)s[i][y]='\0';
		x=get_next(r);//求0~y列共同最小周期x,0~x-1为一个周期 
		cout<<x*y<<endl;
	}
	return 0;
}