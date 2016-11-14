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
int lsum[MAX<<2],rsum[MAX<<2];//�ֱ��¼���������������ׯ,������������ׯ,�Ҷ����������ׯ
int s[MAX],size,n,m,a;//s��¼�ƻ��Ĵ�ׯ��� 
char ch[2];
bool mark[MAX];//mark��Ǵ�ׯ�Ƿ��ƻ�,0��ʾû�ƻ�,1��ʾ�ƻ� 

void Upfather(int n,int m){//�����������Ҷ�������ׯ���� 
	lsum[n]=lsum[n<<1];
	rsum[n]=rsum[n<<1|1];
	if(lsum[n] == m-(m>>1))lsum[n]+=lsum[n<<1|1];
	if(rsum[n] == m>>1)rsum[n]+=rsum[n<<1];
}

void BuildTree(int left,int right,int n){
	lsum[n]=rsum[n]=right-left+1;
	if(left == right)return;
	int mid=left+right>>1;
	BuildTree(left,mid,n<<1);
	BuildTree(mid+1,right,n<<1|1);
}

void Update(int p,int date,int left,int right,int n){
	if(left == right){lsum[n]=(rsum[n]+=date);return;}
	int mid=left+right>>1;
	if(p<=mid)Update(p,date,left,mid,n<<1);
	else Update(p,date,mid+1,right,n<<1|1);
	Upfather(n,right-left+1);
}

int QueryL(int L,int R,int left,int right,int n){//��ѯa~n�����������ׯ���� 
	if(L<=left && right<=R)return lsum[n];
	int mid=left+right>>1,lans,rans;
	if(L<=mid)lans=QueryL(L,R,left,mid,n<<1);
	if(R>mid)rans=QueryL(L,R,mid+1,right,n<<1|1);
	if(R<=mid)return lans;
	if(L>mid)return rans;
	if(lans == mid-L+1)return lans+rans;
	return lans;
}
/*��һ��д������������
int QueryL(int L,int R,int left,int right,int n){
	if(L<=left && right<=R)return lsum[n];
	int mid=left+right>>1,lans,rans;
	if(R<=mid)return QueryL(L,R,left,mid,n<<1);
	else if(L>mid)return QueryL(L,R,mid+1,right,n<<1|1);
	else{
		lans=QueryL(L,mid,left,mid,n<<1);
		rans=QueryL(mid+1,R,mid+1,right,n<<1|1);
		if(lans == mid-L+1)return lans+rans;
		return lans;
	}
} 
*/

int QueryR(int L,int R,int left,int right,int n){//��ѯ1~a�Ҷ˴�ׯ�������� 
	if(L<=left && right<=R)return rsum[n];
	int mid=left+right>>1,lans,rans;
	if(L<=mid)lans=QueryR(L,R,left,mid,n<<1);
	if(R>mid)rans=QueryR(L,R,mid+1,right,n<<1|1);
	if(R<=mid)return lans;
	if(L>mid)return rans;
	if(rans == R-mid)return lans+rans;
	return rans;
}
/*��һ��д������������
int QueryR(int L,int R,int left,int right,int n){
	if(L<=left && right<=R)return rsum[n];
	int mid=left+right>>1,lans,rans;
	if(R<=mid)return QueryR(L,R,left,mid,n<<1);
	else if(L>mid)return QueryR(L,R,mid+1,right,n<<1|1);
	else{
		lans=QueryR(L,mid,left,mid,n<<1);
		rans=QueryR(mid+1,R,mid+1,right,n<<1|1);
		if(rans == R-mid)return lans+rans;
		return rans;
	}
}
*/

int main(){
	while(~scanf("%d%d",&n,&m)){
		BuildTree(1,n,1);
		size=0;
		memset(mark,false,sizeof(bool)*(n+2));
		mark[0]=true;
		for(int i=0;i<m;++i){
			scanf("%s",ch);
			if(ch[0] == 'D'){
				scanf("%d",&a);
				s[++size]=a;
				if(!mark[a])Update(a,-1,1,n,1),mark[a]=true;
			}else if(ch[0] == 'R'){
				while(!mark[s[size]])--size;//�Ѿ����޸����˾��޸���һ��,����3 2 2,��һ���޸�2,�����޸�3������2 
				if(size)Update(s[size],1,1,n,1),mark[s[size--]]=false;
			}else{
				scanf("%d",&a);
				int temp=QueryL(a,n,1,n,1)+QueryR(1,a,1,n,1);
				printf("%d\n",temp>0?temp-1:0);
			}
		}
	}
	return 0;
}