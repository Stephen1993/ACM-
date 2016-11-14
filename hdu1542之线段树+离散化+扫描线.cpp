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

const int MAX=200+10;
int mark[MAX<<2];//��¼ĳ��������µױ߸���
double sum[MAX<<2];//��¼ĳ��������µױ��ܳ���
double hash[MAX];//��x������ɢ��,����xΪ�������Һܴ��޷������߶��� 

//�Ժ�������Ϊ�߶�(����),�Ժ������߶ν���ɨ��
//ɨ���������ÿ�θ����µױ��ܳ��Ⱥ��µױ߸���,��������� 
struct seg{//�߶� 
	double l,r,h;
	int d;
	seg(){}
	seg(double x1,double x2,double H,int c):l(x1),r(x2),h(H),d(c){}
	bool operator<(const seg &a)const{
		return h<a.h;
	}
}s[MAX];

void Upfather(int n,int left,int right){
	if(mark[n])sum[n]=hash[right+1]-hash[left];//��ʾ�����������߶γ��ȿ�����Ϊ�ױ� 
	else if(left == right)sum[n]=0;//Ҷ�ӽ����ױ߳���Ϊ0(�������߶γ���Ϊ0) 
	else sum[n]=sum[n<<1]+sum[n<<1|1];
}

void Update(int L,int R,int d,int n,int left,int right){
	if(L<=left && right<=R){//�������ǵ�ǰɨ���߶ε�һ����,��������µױ��ܳ��Լ����µױ߸�������� 
		mark[n]+=d;//���µױ�������� 
		Upfather(n,left,right);//���µױ߳� 
		return;
	}
	int mid=left+right>>1;
	if(L<=mid)Update(L,R,d,n<<1,left,mid);
	if(R>mid)Update(L,R,d,n<<1|1,mid+1,right);
	Upfather(n,left,right);
}

int search(double key,double *x,int n){
	int left=0,right=n-1;
	while(left<=right){
		int mid=left+right>>1;
		if(x[mid] == key)return mid;
		if(x[mid]>key)right=mid-1;
		else left=mid+1;
	}
	return -1;
}

int main(){
	int n,num=0;
	double x1,x2,y1,y2;
	while(cin>>n,n){
		int k=0;
		for(int i=0;i<n;++i){
			cin>>x1>>y1>>x2>>y2;
			hash[k]=x1;
			s[k++]=seg(x1,x2,y1,1);
			hash[k]=x2;
			s[k++]=seg(x1,x2,y2,-1);
		}
		sort(hash,hash+k);
		sort(s,s+k);
		int m=1;
		for(int i=1;i<k;++i)//ȥ�ظ��˵� 
		    if(hash[i] != hash[i-1])hash[m++]=hash[i];
        double ans=0;
        //memset(mark,0,sizeof mark);
        //memset(sum,0,sizeof sum);���������i<k-1��Ҫ��ʼ��,��Ϊ����Ե�k-1���߶�ɨ��ʱ��ʹ��mark,sumΪ0�Ų��ó�ʼ���� 
		for(int i=0;i<k;++i){//ɨ���߶� 
			int L=search(s[i].l,hash,m);
			int R=search(s[i].r,hash,m)-1;
			Update(L,R,s[i].d,1,0,m-1);//ɨ���߶�ʱ���µױ߳��Ⱥ͵ױ�������
			ans+=sum[1]*(s[i+1].h-s[i].h);//��������� 
		}
		printf("Test case #%d\nTotal explored area: %.2lf\n\n",++num,ans);
	}
	return 0;
}
/*
����ע����ɨ���߶�ʱr-1:int R=search(s[i].l,hash,m)-1;
����ױ߳�ʱr+1:if(mark[n])sum[n]=hash[right+1]-hash[left];
����:����������һ���߶���˵���l=0,�Ҷ˵���r=m-1
������ȥ���µ�ʱ��,���㵽sum[1]=hash[mid]-hash[left]+hash[right]-hash[mid+1]
�����ĵ��ĵױ߳�sum�Ǵ����,why?��Ϊ������mid~mid+1�ľ���,����������������
��ɢ���������ʾ�߶�,����mid~mid+1֮�����г��ȵ�,����hash[3]=1.2,hash[4]=5.6,mid=3
����������r-1,r+1�ͺܺ������ 
*/ 