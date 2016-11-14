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

/*
˼·:����Ҫ���������λ��mod%5Ϊ3���������ĺ�,
�����ȶ����е���������ٲ�������ˣ�ͬʱ���ڲ���/ɾ����,
���Բ���/ɾ����λ�õ��ұߵ�mod%5=[0~4]��ֵ��Ҫ��,����ͨ���������ĸ�����ά�� 
*/ 
const int MAX=100000+10;
int sum[MAX<<2];//��ʾ�������ĸ���
__int64 num[MAX<<2][5];//��ʾmod%5=[0~4]��λ�����ܺ�
char op[MAX][4];
int s[MAX],hash[MAX];

void Update(int pos,int date,bool flag,int n,int left,int right){
	if(flag)++sum[n];
	else --sum[n];
	if(left == right){num[n][1]=(flag?date:0);return;}
	int mid=left+right>>1;
	if(pos<=mid)Update(pos,date,flag,n<<1,left,mid);
	else Update(pos,date,flag,n<<1|1,mid+1,right);
	for(int i=0;i<5;++i){
		num[n][i]=num[n<<1][i]+num[n<<1|1][(i+5-sum[n<<1]%5)%5];//sum[n<<1]%5+x=i+5=>x=i+5-....
	}
}

int search(int key,int x[],int n){
	int left=1,right=n-1;
	while(left<right){
		int mid=left+right>>1;
		if(x[mid]<key)left=mid+1;
		else right=mid;
	}
	return left;
}

int main(){
	int n;
	while(cin>>n){
		int k=0;
		for(int i=0;i<n;++i){
			scanf("%s",op[i]);
			if(op[i][0] != 's'){
				scanf("%d",&s[i]);
				hash[k++]=s[i];
			}
		}
		int m=1;
		sort(hash,hash+k);
		for(int i=1;i<k;++i)if(hash[i] != hash[i-1])hash[m++]=hash[i];
		memset(sum,0,sizeof sum);
		memset(num,0,sizeof num);
		for(int i=0;i<n;++i){
			if(op[i][0] == 's')printf("%I64d\n",num[1][3]);
			else{
				int pos=search(s[i],hash,m);
				Update(pos,s[i],op[i][0] == 'a',1,1,m);
			}
		}
	}
	return 0;
} 
/*
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
const int mod=5;
int sum[MAX<<2];//��ʾ���������ĸ��� 
__int64 num[MAX<<2][mod];//��ʾ����������%mod=[0~4]�ĺ�
int s[MAX],x[MAX];
char oper[MAX][4];

void BuildTree(int n,int left,int right){
	sum[n]=0;
	for(int i=0;i<mod;++i)num[n][i]=0;
	if(left == right)return;
	int mid=left+right>>1;
	BuildTree(n<<1,left,mid);
	BuildTree(n<<1|1,mid+1,right);
}

void Upfather(int n){
	for(int i=0;i<mod;++i){
		num[n][i]=num[n<<1][i]+num[n<<1|1][(i+mod-sum[n<<1]%mod)%mod];//sum[n<<1]%mod+x=i+mod*n(n=0,1,2,...),x=i+mod-...
	} 
}

void Update(int pos,int date,bool flag,int n,int left,int right){
	if(flag)++sum[n];
	else --sum[n];
	if(left == right){num[n][1]=(flag?date:0);return;}
	int mid=left+right>>1;
	if(pos<=mid)Update(pos,date,flag,n<<1,left,mid);
	else Update(pos,date,flag,n<<1|1,mid+1,right);
	Upfather(n);
}

int search(int key,int hash[],int n){//lower_bound
	int left=0,right=n-1;
	while(left<right){
		int mid=left+right>>1;
		if(hash[mid]<key)left=mid+1;
		else right=mid;
	}
	return left;
}

int main(){
	int n;
	while(cin>>n){
		int k=0;
		for(int i=0;i<n;++i){
			scanf("%s",oper[i]);
			if(oper[i][0] != 's'){
				scanf("%I64d",&x[i]);
				s[k++]=x[i];//�൱��x[i]������hash��k���С���� 
			}
		}
		sort(s,s+k);//s��ȷ��ÿ������λ��
		//for(int i=1;i<k;++i)if(s[i] != s[i-1])s[m++]=s[i];k=m;
		BuildTree(1,1,k);//memset(sum,0,sizeof sum),memset(num,0,sizeof num);
		for(int i=0;i<n;++i){
			if(oper[i][0] == 's')printf("%I64d\n",num[1][3]);
			else{
				int pos=search(x[i],s,k);//��ѯ��һ��С�ڵ���x[i]������λ�� 
				Update(pos,x[i],oper[i][0] == 'a',1,1,k);
			}
		} 
	}
	return 0;
} 
*/ 