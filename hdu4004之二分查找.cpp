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

const int MAX=500000+10;
int s[MAX];

int search(int left,int right,int v){//查找最右端<=v的数 
	while(left+1<right){//剩下两个元素的时候另外判段,如果left<right可能会无限循环 
		int mid=left+right>>1;
		if(s[mid]<=v)left=mid;
		else right=mid-1;
	}
	if(s[right]<=v)return right;
	return left;
}

int judge(int v,int n,int m){
	int num=0,left=0;
	while(left<n && ++num<=m)left=search(left,n,s[left]+v);//用left记录每次能跳到的最右端距离的序号作为新区间的左端点 
	return num;
}

int main(){
	int L,n,m;
	while(scanf("%d%d%d",&L,&n,&m)!=EOF){
		for(int i=1;i<=n;++i)scanf("%d",s+i);
		sort(s,s+n+1);
		s[n+1]=L;
		int left=0,right=L,mid;
		while(left<right){//对于青蛙可能跳的距离进行二分 
			mid=left+right>>1;
			if(judge(mid,n+1,m)<=m)right=mid;//判断青蛙以跳跃距离mid最少跳几次到L和题目要求的次数m进行比较 
			else left=mid+1;
		}
		cout<<right<<endl;
	}
	return 0;
} 