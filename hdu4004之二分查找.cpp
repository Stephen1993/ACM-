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

int search(int left,int right,int v){//�������Ҷ�<=v���� 
	while(left+1<right){//ʣ������Ԫ�ص�ʱ�������ж�,���left<right���ܻ�����ѭ�� 
		int mid=left+right>>1;
		if(s[mid]<=v)left=mid;
		else right=mid-1;
	}
	if(s[right]<=v)return right;
	return left;
}

int judge(int v,int n,int m){
	int num=0,left=0;
	while(left<n && ++num<=m)left=search(left,n,s[left]+v);//��left��¼ÿ�������������Ҷ˾���������Ϊ���������˵� 
	return num;
}

int main(){
	int L,n,m;
	while(scanf("%d%d%d",&L,&n,&m)!=EOF){
		for(int i=1;i<=n;++i)scanf("%d",s+i);
		sort(s,s+n+1);
		s[n+1]=L;
		int left=0,right=L,mid;
		while(left<right){//�������ܿ������ľ�����ж��� 
			mid=left+right>>1;
			if(judge(mid,n+1,m)<=m)right=mid;//�ж���������Ծ����mid���������ε�L����ĿҪ��Ĵ���m���бȽ� 
			else left=mid+1;
		}
		cout<<right<<endl;
	}
	return 0;
} 