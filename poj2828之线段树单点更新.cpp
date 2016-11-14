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

const int MAX=200000+10;
int sum[MAX<<2];//��ʾ�����ں��п�λ�ĸ���
int s[MAX][2];//��¼�տ�ʼѧ���Ĳ���λ�ú�val
int val[MAX];//��¼������Ӧλ��ѧ����val 

void BuildTree(int n,int left,int right){
	sum[n]=right-left+1;
	if(left == right)return;
	int mid=left+right>>1;
	BuildTree(n<<1,left,mid);
	BuildTree(n<<1|1,mid+1,right);
}

int Update(int pos,int n,int left,int right){
	--sum[n];//���ڸ�����ĳ��λ�ò������Կ�λ��1 
	if(left == right)return left;
	int mid=left+right>>1;
	if(sum[n<<1]>=pos)return Update(pos,n<<1,left,mid);//������ӵĿ�λ>=pos������ڵ�pos��λ�ò�������� 
	else return Update(pos-sum[n<<1],n<<1|1,mid+1,right); 
}
/*
ע�������pos,����ʱҪ���뵽posλ����ǰpos��λ��һ���Ѿ���������,�������ڵ�������Ҫ��Ԥ��pos-1��λ�ø���Щ�˲���
����Ҫ��pos���뵽����,��sum[n<<1]>=pos
���sum[n<<1]<pos��˵���ڵ�������ʱ�����˲��뵽��pos����,���м����˲��뵽posǰ��pos��Ҫ���˼�����
����posӦ�ò������ұߵĴ�mid+1��ʼ�ĵ�pos-sum[n<<1]��λ�� 
*/

int main(){
	int n,pos;
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<n;++i){
			scanf("%d%d",&s[i][0],&s[i][1]);
		}
		BuildTree(1,1,n);//������Ϊ�˸���sum 
		for(int i=n-1;i>=0;--i){//��������ʹ�Ȳ���Ĳ��ܺ�����Ӱ�� 
			pos=Update(s[i][0]+1,1,1,n);//pos��ʾ���ѧ�����յ�λ��
			val[pos]=s[i][1]; 
		}
		for(int i=1;i<n;++i)printf("%d ",val[i]);
		printf("%d\n",val[n]);
	}
	return 0;
} 