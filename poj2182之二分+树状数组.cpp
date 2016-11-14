/*�������ɸ������������ǴӺ���ǰ�������s[n-1],s[n-2]...s[0]
���������s[k]��ʱ������s[k+1]...s[n-1]����,����ֻҪȷ����s[k]
����ȷ��s[k+1]~s[n-1]�б�s[k]С�ĸ���num,�Ӷ�k-1-num����s[k]ǰ���s[k]С�ĸ���
���s[k]-1-num == a[k](�������ֵ),��õ������s[k],�����ȷ��s[k]��?��������ö�����ȷ��s[k]
���ȷ��num��?��������״��������num
����ʱ��
���s[k]-1-num>=a[k]��right=mid,��ʾs[k]���Լ�����С
����left=mid+1,��ʾs[k]������ſ�������
ע�⵽�����s[k]-1-num>=a[k]��right=mid,Ϊʲô��ֱ��s[k]-1-num == a[k]ʱֱ�ӵõ�s[k]��?
����:������Ϊ�����s[k]���ܲ�ֹһ��ֵ
����:
5       1      2
1       3      4
2   =>  5 ���� 5
1       3      3
0       1      1
��Ȼ��һ���󵽵Ľ��Ҳ���������ֵ����ȴ����ȷ
����s[k]-1-num>=a[k]��right=mid,��������s[k]���㲢��ԭ��s[k+1]~s[n-1]�Ѿ���s[k]�Ļ�
��ôs[k]-1Ҳһ������,�ͻ�һֱright=mid,ֱ��s[k+1]~s[n-1]û��s[k]����s[k]����,���s[k]������Ҫ���s[k] 
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
			int x=search(a[i]);//��ѯ�ĸ����ܹ���������
			a[i]=x; 
			Update(x);
		}
		for(int i=0;i<n;++i)printf("%d\n",a[i]);
	}
	return 0;
}