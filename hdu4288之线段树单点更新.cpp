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
思路:由于要计算排序后位置mod%5为3的所有数的和,
所以先对所有的数排序后再插入就行了，同时由于插入/删除数,
所以插入/删除的位置的右边的mod%5=[0~4]的值需要变,可以通过左孩子数的个数来维护 
*/ 
const int MAX=100000+10;
int sum[MAX<<2];//表示含有数的个数
__int64 num[MAX<<2][5];//表示mod%5=[0~4]的位置数总和
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
int sum[MAX<<2];//表示区间内数的个数 
__int64 num[MAX<<2][mod];//表示区间内所有%mod=[0~4]的和
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
				s[k++]=x[i];//相当于x[i]大区间hash到k这个小区间 
			}
		}
		sort(s,s+k);//s是确定每个数的位置
		//for(int i=1;i<k;++i)if(s[i] != s[i-1])s[m++]=s[i];k=m;
		BuildTree(1,1,k);//memset(sum,0,sizeof sum),memset(num,0,sizeof num);
		for(int i=0;i<n;++i){
			if(oper[i][0] == 's')printf("%I64d\n",num[1][3]);
			else{
				int pos=search(x[i],s,k);//查询第一个小于等于x[i]的数的位置 
				Update(pos,x[i],oper[i][0] == 'a',1,1,k);
			}
		} 
	}
	return 0;
} 
*/ 