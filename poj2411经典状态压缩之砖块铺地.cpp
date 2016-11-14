/*分析：用1*2的砖去恰好铺满n*m的空间,对于第k行第j列,有3种情况将该点铺满
1:由第k-1行第j列砖竖着铺将第k行第j列铺满
2:由第k行第j列被横铺砖铺满
3:第k行第j列砖竖着铺将该点铺满
所以对于每一列的情况其实有两种(1,0)表示该点铺砖还是不铺
而对于每一列必须到达的状态只有一种，就是被铺满(1)
但是由上述3种情况将铺满方式分成两种:
0和1表示被k-1行j列竖铺铺满和在k-1行被横铺铺满 
对于每一行列举每一种到达的状态j,dp[j]表示到达该状态有多少种情况
分析对于第k-1行状态j:10000111
需要到达第k行状态i:  01111011
如果需要到达第k行j列状态是0，则必须第k-1行该点状态不能是0，否则一定是连续两列竖放冲突
所以到达第k-1行该点只能是1，也就是说i|j一定每一位是1,也可以一步步判断是否满足第k行j列是0第k-1行j列是1 
如果需要到达第k行状态j列是1，则假如第k-1行该点是0，则该点状态可以到达，继续判断j+1列
假如第k-1行该点是1，则第k行j列的1一定是横铺到达的,所以k行第j+1列一定也被铺满为1
从而第k-1行j+1列一定不能竖铺，必须被横铺铺满，所以也是1.
于是综合的第k行j列和第k-1行j列的关系(每一行每一列都表示到达的状态)
1:下面这种情况从第j列继续去判断j+1列 
  1
  0
2:下面这种情况从第j列继续去判断j+1列 
  0
  1
3:下面这种情况从第j列判断第j+1列是否全是1,然后继续判断第j+2列
  1
  1 
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

const int MAX=(1<<11)+10;
int n,m;
LL temp[MAX],dp[MAX],bin[15];
bool mark[MAX];

bool check(int i){
	while(i){
		if(i&1){
			i>>=1;
			if(!(i&1))return false;//第j列是1则第j+1列必须是1 
			i>>=1;//继续判断下一列 
		}else i>>=1;//继续判断下一列 
	}
	return true;
}

void Init(){
	memset(mark,false,sizeof mark);
	memset(temp,0,sizeof temp);
	for(int i=0;i<bin[m];++i){//初始化第一行和可以到达什么状态 
		if(check(i))temp[i]=1,mark[i]=true;
	}
}

void DP(){
	for(int k=2;k<=n;++k){
		for(int i=0;i<bin[m];++i)dp[i]=0;
		for(int i=0;i<bin[m];++i){
			for(int j=0;j<bin[m];++j){
				if((i|j) != bin[m]-1)continue;//每一位或之后必须每一位是1(综合前面3种情况和分析可知)
				if(!mark[i&j])continue;//由初始化和前面分析三种情况分析可知i&j必须得到和初始化可以到达的状态一样才行
				dp[i]+=temp[j];//i可以从j到达,则增加j的方案数 
			}
		}
		for(int i=0;i<bin[m];++i)temp[i]=dp[i];
	}
}

int main(){
	bin[0]=1;
	for(int i=1;i<12;++i)bin[i]=2*bin[i-1];
	while(~scanf("%d%d",&n,&m),n+m){
		if(n<m)swap(n,m);//始终保持m<n,提高效率 
		Init();
		DP();
		printf("%lld\n",temp[bin[m]-1]);//输出最后一行到达时的状态必须全部是1 
	}
	return 0;
}