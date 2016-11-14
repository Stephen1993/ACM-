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
int mark[MAX<<2];//��¼ĳ��������µױ߱��ϵױ߶�ĸ���
double sum[MAX<<2];//��¼ĳ�������µױ߱��ϵױ߶�ĸ����ܳ��� 
double hash[MAX];//�Ժ�����x��ɢ��

struct seg{//�߶� 
	double l,r,h;
	int d;
	seg(){}
	seg(double x1,double x2,double H,int D):l(x1),r(x2),h(H),d(D){}
	bool operator<(const seg &a)const{
		return h<a.h;
	}
}s[MAX];

void Upfather(int n,int left,int right){
	if(mark[n])sum[n]=hash[right+1]-hash[left];//��ʾ�����������߶γ��ȿ���Ϊ�ױ� 
	else if(left == right)sum[n]=0;//Ҷ�ӽ�����䳤��Ϊ0,��ױ߳���Ϊ0 
	else sum[n]=sum[n<<1]+sum[n<<1|1];
}

void Update(int L,int R,int d,int n,int left,int right){
	if(L<=left && right<=R){//�������ǵ�ǰɨ���߶ε�һ���� 
		mark[n]+=d;//�������µױ�֮�� 
		Upfather(n,left,right);//���¿��õױ߳� 
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
		else if(x[mid]>key)right=mid-1;
		else left=mid+1;
	}
	return -1;
}

int main(){
	double x1=0,y1=0,x2=0,y2=0;
	while(x1 != -2){
		int size=0;
		while(cin>>x1>>y1>>x2>>y2,x1>=0){
			if(x1>x2)swap(x1,x2);
			if(y1>y2)swap(y1,y2);
			hash[size]=x1;
			s[size++]=seg(x1,x2,y1,1);
			hash[size]=x2;
			s[size++]=seg(x1,x2,y2,-1);
		}
		sort(hash,hash+size);
		sort(s,s+size);
		int k=1;
		for(int i=1;i<size;++i){//ȥ�ظ��˵� 
			if(hash[i] != hash[i-1])hash[k++]=hash[i];
		}
		double ans=0;
		//memset(mark,0,sizeof mark);
		//memset(sum,0,sizeof sum);���������i<size-1��Ҫ��ʼ��,��Ϊ������Ե�size-1���߶�ɨ�費��ʹsum,markΪ0
		for(int i=0;i<size;++i){
			int L=search(s[i].l,hash,k);
			int R=search(s[i].r,hash,k)-1;
			Update(L,R,s[i].d,1,0,k-1);//ɨ���߶θ��¿��õױ߳� 
			ans+=sum[1]*(s[i+1].h-s[i].h);//��������� 
		}
		cout<<ans<<endl;
	}
	return 0;
}