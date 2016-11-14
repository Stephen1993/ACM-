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

//��������һ������Ϳ��ɫ,������ܿ���������ɫ
const int MAX=10000+10;
int hash[MAX*4];//��ɢ���������,��ν��ɢ����������ѹ������,��������ӳ��ɶ�����
int color[MAX<<4];//��¼���ڵ㱻Ⱦ��ɫ���Ǻ���δ����
int s[MAX][2];//�������
bool mark[MAX];//�ڲ�ѯʱ�����ɫ�Ƿ��Ѿ�Ѱ�ҵ���
int sum;//ͳ���ܹ��ж��ٿ�

void Upchild(int n){
	if(color[n]){
		color[n<<1]=color[n<<1|1]=color[n];
		color[n]=0;
	}
}

void Update(int L,int R,int c,int n,int left,int right){
	if(L<=left && right<=R){color[n]=c;return;}
	Upchild(n);//���θ���ǰ�ȸ�����һ�ο����еĸ���(�����ڵ�����˶�����δ����)
	int mid=left+right>>1;
	if(L<=mid)Update(L,R,c,n<<1,left,mid);
	if(R>mid)Update(L,R,c,n<<1|1,mid+1,right);
}

void Query(int n,int left,int right){
	if(color[n]){//��ʾ�ÿ��ѱ�Ⱦ��һ����ɫ
		if(!mark[color[n]])++sum;
		mark[color[n]]=true;
		return;
	}
	if(left == right)return;
	int mid=left+right>>1;
	Query(n<<1,left,mid);
	Query(n<<1|1,mid+1,right);
}

int Search(int key,int n,int x[]){
	int left=0,right=n-1;
	while(left<=right){
		int mid=left+right>>1;
		if(x[mid] == key)return mid;
		if(x[mid]<key)left=mid+1;
		else right=mid-1;
	}
	return -1;
}

int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int k=0;
		for(int i=1;i<=n;++i){
			scanf("%d%d",&s[i][0],&s[i][1]);
			hash[k++]=s[i][0];//��ʼ��ɢ��
			hash[k++]=s[i][1];
		}
		sort(hash,hash+k);
		int m=1;
		for(int i=1;i<k;++i){//����ͬ������,��ͬ��Ӧ��ӳ��Ϊͬһ�㲢�һ����Լ��ٽ���������
			if(hash[i] != hash[i-1])hash[m++]=hash[i];
		}
		/* 1-10,1-4,5-10��1-10,1-4,6-10����ӳ���1,2,3,4��1-4,1-2,3-4,
		   ��ֻ����2��(1-2,3-4),����ǰ�߿���2��(1-4,5-10),�����ܿ���3��(1-4,5-5,6-10)
		   ���Բ��ø����˼����������������Ϊ1�������������1����,�������1-10,1-4,5-10����ӳ���1-4,1-2,3-4
		   ��1-10,1-4,6-10���ӳ���1-5,1-2,4-5,����4��6����1���м����һ����5ӳ��Ϊ3,��������𰸲�����ȷ��
		*/
		for(int i=m-1;i>=1;--i){
			if(hash[i] != hash[i-1]+1)hash[m++]=hash[i-1]+1;
		}
		sort(hash,hash+m);//��������(ʹ�������������и��������)
		//BuildTree(1,0,m-1);�����𲻵��κ�����,������ʵ����ʹ�����,ƽʱ������Ϊ�˳�ʼ��һЩ��������
		memset(color,0,sizeof color);
		for(int i=1;i<=n;++i){
			int L=Search(s[i][0],m,hash);
			int R=Search(s[i][1],m,hash);
			Update(L,R,i,1,0,m-1);
		}
		sum=0;
		memset(mark,false,sizeof mark);
		Query(1,0,m-1);
		printf("%d\n",sum);
	}
	return 0;
}
