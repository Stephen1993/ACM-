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

const int MAX=50000+10;
int sum[MAX<<2];//sum��ʾĳ���ڵ������� 

void BuildTree(int n,int left,int right){
	if(left == right){
		scanf("%d",sum+n);
		return;
	}
	int mid=left+right>>1;
	BuildTree(n<<1,left,mid);
	BuildTree(n<<1|1,mid+1,right);//n<<1|1�ȼ���n*2+1
	sum[n]=sum[n<<1]+sum[n<<1|1]; 
}

void Update(int a,int add,int n,int left,int right){
	if(left == right){sum[n]+=add;return;}//left == right��ʾ�����Ѿ���a��
	int mid=left+right>>1;
	if(a<=mid)Update(a,add,n<<1,left,mid);
	else Update(a,add,n<<1|1,mid+1,right);
	sum[n]=sum[n<<1]+sum[n<<1|1];//��������� 
}

int Query(int L,int R,int n,int left,int right){
	if(L<=left && right<=R)return sum[n];//��������L~R�е�һ��left~right�ĺ�
	int mid=left+right>>1,ans=0;
	if(L<=mid)ans+=Query(L,R,n<<1,left,mid);//����L~R��mid��ߵļ�L~mid�ú� 
	if(R>mid)ans+=Query(L,R,n<<1|1,mid+1,right);//����l~R��mid�ұ߼�mid+1~R�ĺ� 
	return ans; 
	/*
	if(R<=mid)return Query(L,R,n<<1,left,mid);
	else if(L>mid)return Query(L,R,n<<1|1,mid+1,right);
	else return Query(L,mid,n<<1,left,mid)+Query(mid+1,R,n<<1|1,mid+1,right);
	*/
}

int main(){
	int t,n,num=0,a,b;
	char s[10];
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		BuildTree(1,1,n);
		printf("Case %d:\n",++num);
		while(scanf("%s",s),s[0] != 'E'){
			scanf("%d%d",&a,&b);
			if(s[0] == 'A')Update(a,b,1,1,n);
			if(s[0] == 'S')Update(a,-b,1,1,n);
			if(s[0] == 'Q')printf("%d\n",Query(a,b,1,1,n));
		}
	}
	return 0;
} 