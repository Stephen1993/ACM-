/*���������ڱ�����µ�ʱ�����������
���Բ���ֱ��ȥһ�������������ڵĵ㣬�϶��ᳬʱ
����ÿ�θ���C(a,b,d)��ʾ����[a,b]�ڵ�ֵ����d
��ans[a]��ʾa~n����Ԫ�����ӵ�ֵ,���Զ���C(a,b,d)��:ans[a]+=d,ans[b+1]-=d;
��ÿ��ѯ�ʵ�ʱ��Q(a,b),��a~b�ĺ�SUM=sum(a,b)+ans[a]*(b-a+1)+ans[a+1]*(b-a)...+ans[b]//sum(a,b)��ʾa,b�ĺ� 
Sum=sum(a,b)+sum(ans[a+t]*(b-a-t+1))=sum(a,b)+sum(ans[i]*(b-i+1));a<=i<=b;
Sum=sum(a,b)+(b+1)*sum(ans[i])-sum(ans[i]*i);//1~b����(b+1)*sum(ans[i]),1~a-1��a*sum(ans[i]) 
���Կ�����������״����ֱ��ʾans[i]��ǰ׺�� �� ans[i]*i��ǰ׺�� 
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