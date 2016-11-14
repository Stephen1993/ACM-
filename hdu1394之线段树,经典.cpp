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

const int MAX=5000+10;
int sum[MAX<<2],s[MAX];//��ʾsum[i]�����������left~right�Ѿ����ֵ����ĸ���

//�߶����ҵļ����Ϊ:�õ�(sum[i])ȥӳ������left~right,Ȼ�����ʹ�õ�sum[i]��¼����left~right��ĳЩ���Բ����Լ��� 
//�����߶����������Ǽ��������������,��ȷ�е�˵�Ǽ�������left~right���ֵ�������,��������left������������ 
void BuildTree(int n,int left,int right){//������������ 
	sum[n]=0;//��ʼ����������ֵĸ���Ϊ0
	if(left == right)return;
	int mid=left+right>>1;
	BuildTree(n<<1,left,mid);
	BuildTree(n<<1|1,mid+1,right); 
}

void Update(int date,int n,int left,int right){//��������left~right���ֵ����ĸ��� 
	if(left == right){++sum[n];return;}
	int mid=left+right>>1;
	if(date<=mid)Update(date,n<<1,left,mid);
	else Update(date,n<<1|1,mid+1,right);
	sum[n]=sum[n<<1]+sum[n<<1|1];//���¸�������ֵ����ĸ��� 
}

int Query(int L,int R,int n,int left,int right){//��ѯ����L~R���ֵ����ĸ��� 
	if(L<=left && right<=R)return sum[n];
	int mid=left+right>>1,ans=0;
	if(L<=mid)ans+=Query(L,R,n<<1,left,mid);//����L~R��left~mid�ڵ�����L~mid���ֵ����ĸ��� 
	if(R>mid)ans+=Query(L,R,n<<1|1,mid+1,right);//����L~R��mid+1~R�ڵ�����mid+1~R���ֵ����ĸ��� 
	return ans; 
}

int main(){
	int n,ans;
	while(scanf("%d",&n)!=EOF){
		BuildTree(1,0,n-1);
		ans=0;
		for(int i=0;i<n;++i){
			scanf("%d",s+i);
			ans+=Query(s[i],n-1,1,0,n-1);//ͳ�������������,Query�����ǲ�ѯs[i]~n-1���ֵ����ĸ���(��ͳ����s[i]������������)
			Update(s[i],1,0,n-1);//����0~n-1���ֵ����ĸ��� 
		}
		int temp=ans;
		for(int i=0;i<n-1;++i){//���ݹ�ʽ���������е������� 
			ans=ans-s[i]+n-1-s[i];//s[i]��ʾ��s[i]С�����ĸ���,n-1-s[i]��ʾ��s[i]������ĸ���
			temp=temp<ans?temp:ans; 
		}
		printf("%d\n",temp);
	}
	return 0;
} 