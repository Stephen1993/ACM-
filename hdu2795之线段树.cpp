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

const int MAX=200000+10;//����n<=200000,���߶������Ҫn���� 
int sum[MAX<<2],h,w;//��ʾsum[i]�����������left~right�����Ŀ�� 

void BuildTree(int n,int left,int right){
	sum[n]=w;
	if(left == right)return;
	int mid=left+right>>1;
	BuildTree(n<<1,left,mid);
	BuildTree(n<<1|1,mid+1,right);
}

int Query(int wi,int n,int left,int right){
	if(left == right){
		sum[n]-=wi;//�ڸø߶������,����Ӧ�Ŀ����Ҫ����
		return left; 
	}
	int mid=left+right>>1;
	int hi=sum[n<<1]>=wi?Query(wi,n<<1,left,mid):Query(wi,n<<1|1,mid+1,right);//����Ѱ�Ҹ߶�С��λ�÷��ù�� 
	sum[n]=sum[n<<1]>sum[n<<1|1]?sum[n<<1]:sum[n<<1|1];//����������������ȱ���,���Ը��������
	return hi; 
}

int main(){
	int n,wi;
	while(~scanf("%d%d%d",&h,&w,&n)){
		if(h>n)h=n;//if h>n,�������Ҫ�߶�n���ܷ���n�����
		BuildTree(1,1,h);
		for(int i=0;i<n;++i){
			scanf("%d",&wi);
			int hi=sum[1]>=wi?Query(wi,1,1,h):-1;//sum[1]��ʾ�������������� 
			printf("%d\n",hi);
		} 
	}
	return 0;
}