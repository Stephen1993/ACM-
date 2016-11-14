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
int mark[MAX<<2];//记录某个区间的下底边比上底边多的个数
double sum[MAX<<2];//记录某个区间下底边比上底边多的个数总长度 
double hash[MAX];//对横坐标x离散化

struct seg{//线段 
	double l,r,h;
	int d;
	seg(){}
	seg(double x1,double x2,double H,int D):l(x1),r(x2),h(H),d(D){}
	bool operator<(const seg &a)const{
		return h<a.h;
	}
}s[MAX];

void Upfather(int n,int left,int right){
	if(mark[n])sum[n]=hash[right+1]-hash[left];//表示该区间整个线段长度可作为底边 
	else if(left == right)sum[n]=0;//叶子结点区间长度为0,则底边长度为0 
	else sum[n]=sum[n<<1]+sum[n<<1|1];
}

void Update(int L,int R,int d,int n,int left,int right){
	if(L<=left && right<=R){//该区间是当前扫描线段的一部分 
		mark[n]+=d;//更新上下底边之差 
		Upfather(n,left,right);//更新可用底边长 
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
		for(int i=1;i<size;++i){//去重复端点 
			if(hash[i] != hash[i-1])hash[k++]=hash[i];
		}
		double ans=0;
		//memset(mark,0,sizeof mark);
		//memset(sum,0,sizeof sum);如果下面是i<size-1则要初始化,因为如果不对第size-1条线段扫描不会使sum,mark为0
		for(int i=0;i<size;++i){
			int L=search(s[i].l,hash,k);
			int R=search(s[i].r,hash,k)-1;
			Update(L,R,s[i].d,1,0,k-1);//扫描线段更新可用底边长 
			ans+=sum[1]*(s[i+1].h-s[i].h);//新增加面积 
		}
		cout<<ans<<endl;
	}
	return 0;
}