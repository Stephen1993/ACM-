#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 999999999
using namespace std;

const int MAX=100001;
//s��ʾԭ����,tree��ʾ��i��Ԫ������,sum��ʾ��i��L~j�ֵ���������Ԫ�ظ��� 
int s[MAX],tree[20][MAX],sum[20][MAX];
int n,m;

void BuildTree(int deep,int left,int right){
	if(left == right)return;
	int mid=(left+right)>>1,ln=left,rn=mid+1;//ln��ʾ����������ʼ���±�,rn��ʾ����������ʼ���±� 
	int lnum=mid-left+1;//num��ʾ������Ԫ�صĸ���
	for(int i=left;i<=mid;++i){
		if(s[i]<s[mid])--lnum;//lnumʣ����پʹ����ж���������Ԫ�غ�s[mid]��� 
	}
	for(int i=left;i<=right;++i){
		sum[deep][i]=sum[deep][i-1];//��ʾ1~i�Ļ��ֵ��������ĸ��� 
		if(tree[deep][i]<s[mid]){
			++sum[deep][i];
			tree[deep+1][ln++]=tree[deep][i];
		} 
		else if(tree[deep][i]>s[mid]){
			tree[deep+1][rn++]=tree[deep][i];
		}
		else{
			if(lnum){
				--lnum;
				++sum[deep][i];
				tree[deep+1][ln++]=tree[deep][i];
			}
			else tree[deep+1][rn++]=tree[deep][i];
		}
	} 	
	BuildTree(deep+1,left,mid);//�ݹ��Ⱥ�˳���ܱ�,��Ϊsum��������Ҽ�¼���� 
	BuildTree(deep+1,mid+1,right);
}

int Query(int deep,int left,int right,int L,int R,int k){
	if(left == right)return tree[deep][left];
	int a,b;//a����[left,L)�ڱ����ֵ��������ĸ���,b����[L,R]....
	int mid=(left+right)>>1;
	a=sum[deep][L-1]-sum[deep][left-1];
	b=sum[deep][R]-sum[deep][L-1];
	if(b>=k){
		return Query(deep+1,left,mid,left+a,left+a+b-1,k);
	}
	else return Query(deep+1,mid+1,right,mid+L-left+1-a,mid+R-left+1-a-b,k-b);
}

int main(){
	int L,R,k,t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;++i){scanf("%d",&s[i]);tree[0][i]=s[i];}//��ʼ����0��Ԫ��
		sort(s+1,s+n+1);//��ԭ��������
		BuildTree(0,1,n);//��ʼ����
		for(int i=0;i<m;++i){
			scanf("%d%d%d",&L,&R,&k);
			cout<<Query(0,1,n,L,R,k)<<endl;//��0�㿪ʼ��1~n�����ڲ�ѯ����L~R�ĵ�K���������� 
		} 
	}
	return 0;
}