/*分析：由于本题更新的时候是区间更新
所以不能直接去一个个更新区间内的点，肯定会超时
对于每次更新C(a,b,d)表示区间[a,b]内的值增加d
用ans[a]表示a~n区间元素增加的值,所以对于C(a,b,d)有:ans[a]+=d,ans[b+1]-=d;
则每次询问的时候Q(a,b),求a~b的和SUM=sum(a,b)+ans[a]*(b-a+1)+ans[a+1]*(b-a)...+ans[b]//sum(a,b)表示a,b的和 
Sum=sum(a,b)+sum(ans[a+t]*(b-a-t+1))=sum(a,b)+sum(ans[i]*(b-i+1));a<=i<=b;
Sum=sum(a,b)+(b+1)*sum(ans[i])-sum(ans[i]*i);//1~b所以(b+1)*sum(ans[i]),1~a-1则a*sum(ans[i]) 
所以可以用两个树状数组分别表示ans[i]的前缀和 和 ans[i]*i的前缀和 
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
LL n,q;
LL sum[MAX],c1[MAX],c2[MAX];

LL lowbit(LL x){
	return x&(-x);
}

void Update(LL x,LL d,LL *c){
	while(x<=n){
		c[x]+=d;
		x+=lowbit(x);
	}
}

LL Query(LL x,LL *c){
	LL sum=0;
	while(x>0){
		sum+=c[x];
		x-=lowbit(x);
	}
	return sum;
}

int main(){
	char op[3];
	LL x,y,d;
	while(~scanf("%lld%lld",&n,&q)){
		memset(c1,0,sizeof c1);
		memset(c2,0,sizeof c2);
		for(int i=1;i<=n;++i)scanf("%lld",sum+i),sum[i]+=sum[i-1];
		for(int i=0;i<q;++i){
			scanf("%s",op);
			if(op[0] == 'C'){//ans[x]+=d,ans[y+1]-=d
				scanf("%lld%lld%lld",&x,&y,&d);
				Update(x,d,c1);
				Update(y+1,-d,c1);
				Update(x,x*d,c2);
				Update(y+1,-(y+1)*d,c2);
			}else{
				scanf("%lld%lld",&x,&y);
				printf("%lld\n",sum[y]-sum[x-1]+Query(y,c1)*(y+1)-Query(x-1,c1)*x-Query(y,c2)+Query(x-1,c2));
			}
		}
	}
	return 0;
}