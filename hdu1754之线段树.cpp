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

const int MAX=200000+10;
int sum[MAX<<2];//sum��ʾ��i���ڵ��ʾ����������ֵ

void BuildTree(int n,int left,int right){//����һ����������ֱ���ڵ��������Ԫ�ظ���Ϊ1 
	if(left == right){scanf("%d",&sum[n]);return;}
	int mid=left+right>>1;
	BuildTree(n<<1,left,mid);//��������ֽ��������� 
	BuildTree(n<<1|1,mid+1,right);//��������ֽ��������� 
	sum[n]=sum[n<<1]>sum[n<<1|1]?sum[n<<1]:sum[n<<1|1];//����������ֵ 
}

void Update(int a,int date,int n,int left,int right){
	if(left == right){sum[n]=date;return;}//��������a~a��ֵ
	int mid=left+right>>1;
	if(a<=mid)Update(a,date,n<<1,left,mid);//a��mid����� 
	else Update(a,date,n<<1|1,mid+1,right);//a��mid���ұ�
	sum[n]=sum[n<<1]>sum[n<<1|1]?sum[n<<1]:sum[n<<1|1];//������������ֵ 
}

int Query(int L,int R,int n,int left,int right){
	if(L<=left && right<=R)return sum[n];//�ҵ�����L~R�е�һ��left~right�����ֵ
	int mid=left+right>>1,a=0,b=0;
	if(L<=mid)a=Query(L,R,n<<1,left,mid);//Ѱ��L~R��mid��߼�L~mid�����ֵ
	if(R>mid)b=Query(L,R,n<<1|1,mid+1,right);//Ѱ��L~R��mid�ұ߼�mid+1~R�����ֵ
	return a>b?a:b; 
}

int main(){
	int n,m,a,b;
	char s[2];
	while(scanf("%d%d",&n,&m)!=EOF){
		BuildTree(1,1,n);
		for(int i=0;i<m;++i){
			scanf("%s%d%d",s,&a,&b);
			if(s[0] == 'U')Update(a,b,1,1,n);
			else printf("%d\n",Query(a,b,1,1,n));
		}
	}
	return 0;
} 