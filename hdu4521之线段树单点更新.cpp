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
int sum[MAX<<2];//��ʾ��������Ҷ��ֵ�������������
int len[MAX];//��ʾ�Ե�i�����������������
int s[MAX];

void Update(int pos,int date,int n,int left,int right){
	if(left == right){sum[n]=date;return;}
	int mid=left+right>>1;
	if(pos<=mid)Update(pos,date,n<<1,left,mid);
	else Update(pos,date,n<<1|1,mid+1,right);
	sum[n]=max(sum[n<<1],sum[n<<1|1]);//�����������������(��ĳ��Ҷ�ӽ���������) 
}

int Query(int L,int R,int n,int left,int right){
	if(L<=left && right<=R)return sum[n];
	int mid=left+right>>1,lmax=0,rmax=0;
	if(L<=mid)lmax=Query(L,R,n<<1,left,mid);
	if(R>mid)rmax=Query(L,R,n<<1|1,mid+1,right);
	return max(lmax,rmax);//������������ڵ�������� 
}

int main(){//O(nlogn)���Ӷ� 
	int n,d;
	while(cin>>n>>d){
		memset(sum,0,sizeof sum);
		int maxlen=0;
		for(int i=1;i<=n;++i){
			scanf("%d",s+i);
			if(i-d-1>0)Update(s[i-d-1],len[i-d-1],1,0,MAX);//����ǡ�������i��λ�õ���i-d-1 
			if(s[i]>0)len[i]=Query(0,s[i]-1,1,0,MAX)+1;//��ѯ��s[i]����֮ǰ���ֵ������Ը���������������� 
			else len[i]=1;//��s[i]֮ǰ���ֵ���s[k]һ������i-k>d,��Ϊ����(����)��ʱ���Ǹ���i-d-1���µ�,i-(k-d-1)=d+1+(i-k)>d
			maxlen=max(maxlen,len[i]);
		}
		cout<<maxlen<<endl;
	}
	return 0;
} 