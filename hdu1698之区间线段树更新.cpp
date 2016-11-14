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

const int MAX=100000+10;
//sum��ʾ����left~right�ĺ�,mark��ʾ������Ƿ��Ѿ�����(���Ǻ���δ����) 
int sum[MAX<<2],mark[MAX<<2];

void BuildTree(int n,int left,int right){
	mark[n]=0,sum[n]=1;
	if(left == right)return;
	int mid=left+right>>1;
	BuildTree(n<<1,left,mid);
	BuildTree(n<<1|1,mid+1,right);
	sum[n]=sum[n<<1]+sum[n<<1|1];
}

void Upchild(int n,int len){
	if(mark[n]){//��ʾ���ڵ���¹����Ǻ���û�и��� 
		mark[n<<1]=mark[n<<1|1]=mark[n];//��ʾ���Ӹ����˵��Ǻ��ӵĺ���δ����
		sum[n<<1]=(len-(len>>1))*mark[n];//�������������
		sum[n<<1|1]=(len>>1)*mark[n];//�����Һ��������
		mark[n]=0;//��ʾ�Ѳ����ڸ��ڵ�����˵��Ǻ���δ���� 
	}
}

void Update(int L,int R,int date,int n,int left,int right){
	if(L<=left && right<=R){//����L~R�е�һ������left~right 
		sum[n]=(right-left+1)*date;
		mark[n]=date;//��ʾ�˽ڵ��Ѹ���,����δ�����Ӹ���
		return; 
	}
	Upchild(n,right-left+1);//�ڼ������ܸ��º���ǰ,�Ƚ���һ����Ҫ���º����ȸ��º�
	int mid=left+right>>1;
	if(L<=mid)Update(L,R,date,n<<1,left,mid);//����left~right�е�L~mid
	if(R>mid)Update(L,R,date,n<<1|1,mid+1,right);//����left~right�е�mid+1~R
	sum[n]=sum[n<<1]+sum[n<<1|1]; 
}

int main(){
	int t,n,m,a,b,c;
	scanf("%d",&t);
	for(int i=1;i<=t;++i){
		scanf("%d%d",&n,&m);
		BuildTree(1,1,n);
		while(m--){
			scanf("%d%d%d",&a,&b,&c);
			Update(a,b,c,1,1,n);
		}
		printf("Case %d: The total value of the hook is %d.\n",i,sum[1]);
	}
	return 0;
}
 