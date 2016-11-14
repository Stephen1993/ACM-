/*
����:��������poj2778�Ķ�֪������󳤶�Ϊn��ģʽ���������������ĸ���
û�����Ľ���ȥ����������poj2778�ļ�ǿ��
����ֻ��Ҫ�������<=n�����д�-�����������ĸ���
��26^1+26^2+26^3+...+26^n-(A^1+A^2+A^3+...+A^n);//A��״̬����,�������������µ�����һ��״̬�ĸ���
26^1+...+26^n�����ÿ��������h���߾�����������,A^1+...+A^n�����þ�����ֿ�����������߹���:
|1 26| |Sn  | |Sn+1    |
|0 26|*|26^n|=|26^(n+1)|;//Sn=26^1+26^2+...+26^n

|A 1| |Sn| |Sn+1|
|0 1|*| A|=|A   |;//Sn=A+A^2+A^3+...+A^n

ֻҪ:|A 1|
     |0 1|
�Գ�n����|S0|��˼���,������þ���������� 
		 |A | 
*/
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

const int MAX=30+10;
//unsigned __int64 mod=1ll<<64;
unsigned __int64 array[MAX][MAX],sum[2][2][MAX][MAX],temp[2][2][MAX][MAX];
int size,n;
__int64 l;
char s[10];

struct TrieNode{
	bool mark;//����Ƿ��Ǵʸ�
	int id;//��¼�ڵ����
	TrieNode *fail,*next[26]; 
}*root,Node[MAX];

TrieNode *New_TrieNode(){
	memset(&Node[size],0,sizeof(TrieNode));
	Node[size].id=size;
	return &Node[size++];
}

void InsertNode(char *a){//����ʸ� 
	TrieNode *p=root;
	while(*a){
		if(!p->next[(*a)-'a'])p->next[(*a)-'a']=New_TrieNode();
		p=p->next[(*a)-'a'];
		++a;
	}
	p->mark=true;
}

void Build_AC(){//����AC�Զ����������ʼ����array
	memset(array,0,sizeof array); 
	TrieNode *p,*next;
	queue<TrieNode *>q;
	q.push(root);
	while(!q.empty()){
		p=q.front();
		q.pop();
		for(int i=0;i<26;++i){
			if(p->next[i]){
				next=p->fail;
				while(next && !next->next[i])next=next->fail;
				p->next[i]->fail=next?next->next[i]:root;
				if(p->next[i]->fail->mark)p->next[i]->mark=true;//��ʾ���ǰ׺�Ǵʸ�,acg,ac
				q.push(p->next[i]); 
			}else p->next[i]=(p == root)?root:p->fail->next[i];//��p->id״̬���Ե��Ƶ�p->fail->next[i]״̬
			if(!p->next[i]->mark)++array[p->id][p->next[i]->id];//��ʾ�������һ��״̬�Ǵʸ�,����Ե��� 
		}
	}
}

void MatrixInit(unsigned __int64 A[2][2][MAX][MAX],bool flag){//�����ʼ�� 
	for(int a=0;a<2;++a){
		for(int b=0;b<2;++b){
			for(int i=0;i<size;++i){
				for(int j=0;j<size;++j){
					if(flag){
						if(a+b == 0)A[a][b][i][j]=array[i][j];//A[0][0]=array
						else if(b == 1)A[a][b][i][j]=(i == j);//A[0][1]=A[1][1]=1
						else A[a][b][i][j]=0;//A[1][0]=0
					}else{
						if(a == b)A[a][b][i][j]=(i == j);//A[0][0]=A[1][1]=1
						else A[a][b][i][j]=0;//A[0][1]=A[1][0]=0;
					}
				}
			}
		}
	}
}

void MatrixMult(unsigned __int64 A[2][2][MAX][MAX],unsigned __int64 B[2][2][MAX][MAX]){//�������,a=a*b 
	unsigned __int64 C[2][2][MAX][MAX]={0};
	for(int a=0;a<2;++a){
		for(int b=0;b<2;++b){
			for(int c=0;c<2;++c){
				for(int i=0;i<size;++i){
					for(int j=0;j<size;++j){
						for(int k=0;k<size;++k){
							C[a][b][i][j]+=A[a][c][i][k]*B[c][b][k][j];
						}
					}
				}
			}
		}
	}
	for(int a=0;a<2;++a){
		for(int b=0;b<2;++b){
			for(int i=0;i<size;++i){
				for(int j=0;j<size;++j)A[a][b][i][j]=C[a][b][i][j];
			}
		}
	}
}

void MatrixPow(__int64 k){
	MatrixInit(sum,0);//sum=1
	MatrixInit(temp,1);//temp=B=|A 1|
	while(k){                 //|0 1|
		if(k&1)MatrixMult(sum,temp);
		MatrixMult(temp,temp);
		k>>=1;
	}
}

unsigned __int64 FastPow(unsigned __int64 a,int k){
	unsigned __int64 ans=1;
	while(k){
		if(k&1)ans=ans*a;
		a=a*a;
		k>>=1;
	}
	return ans;
}

unsigned __int64 FastSum(__int64 k){
	if(k == 1)return 26;
	unsigned __int64 ans=FastSum(k/2);
	unsigned __int64 a=FastPow(26ull,(k+1)/2);//�����õ���k+1,��k+1���ܻᳬint,kҪ��64λ 
	if(k&1)return 26+(26+a)*ans;//26+(26+26^m)*(26^1+26^2+...),m=(k+1)/2
	else return (1+a)*ans;//(1+26^m)*(26^1+26^2+...),m=(k+1)/2
}

int main(){
	while(scanf("%d%I64d",&n,&l)!=EOF){
		size=0;
		root=New_TrieNode();
		for(int i=0;i<n;++i){
			scanf("%s",s);
			InsertNode(s);
		}
		Build_AC();
		MatrixPow(l);
		unsigned __int64 ans=FastSum(l);
		for(int j=0;j<size;++j){//ֻҪ������յ�sum[0][1][0][i]�Ľ������ 
			for(int k=0;k<size;++k){
				ans-=sum[0][1][0][k]*array[k][j];
			}
		}
		printf("%I64u\n",ans);
	}
	return 0;
}
