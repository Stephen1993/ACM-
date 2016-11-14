/*分析：由给定的数据我们从后往前进行求解s[n-1],s[n-2]...s[0]
当我们求解s[k]的时候，由于s[k+1]...s[n-1]已求到,所以只要确定了s[k]
就能确定s[k+1]~s[n-1]中比s[k]小的个数num,从而k-1-num就是s[k]前面比s[k]小的个数
如果s[k]-1-num == a[k](既输入的值),则该点可以是s[k],而如何确定s[k]呢?在这可以用二分来确定s[k]
如何确定num呢?在这用树状数组来求num
二分时：
如果s[k]-1-num>=a[k]则right=mid,表示s[k]可以继续变小
否则left=mid+1,表示s[k]必须变大才可能满足
注意到这里的s[k]-1-num>=a[k]则right=mid,为什么不直接s[k]-1-num == a[k]时直接得到s[k]呢?
解释:这是因为满足的s[k]可能不止一个值
比如:
5       1      2
1       3      4
2   =>  5 或者 5
1       3      3
0       1      1
显然第一种求到的结果也满足输入的值但是却不正确
所以s[k]-1-num>=a[k]则right=mid,这样假如s[k]满足并且原来s[k+1]~s[n-1]已经有s[k]的话
那么s[k]-1也一定满足,就会一直right=mid,直到s[k+1]~s[n-1]没有s[k]并且s[k]满足,这个s[k]就是需要求得s[k] 
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

const int MAX=8000+10;
int n;
int c[MAX],a[MAX];

int lowbit(int x){
	return x&(-x);
}

void Update(int x){
	while(x<=n){
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

int search(int x){
	int left=1,right=n,mid;
	while(left<right){
		mid=left+right>>1;
		int num=Query(mid);
		if(mid-1-num>=x)right=mid;
		else left=mid+1;
	}
	return left;
}

int main(){
	while(~scanf("%d",&n)){
		a[0]=0;
		for(int i=1;i<n;++i)cin>>a[i];
		for(int i=n-1;i>=0;--i){
			int x=search(a[i]);//查询哪个数能够满足条件
			a[i]=x; 
			Update(x);
		}
		for(int i=0;i<n;++i)printf("%d\n",a[i]);
	}
	return 0;
}