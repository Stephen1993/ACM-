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
unsigned __int64 array[MAX][MAX],sum[MAX][MAX],temp[MAX][MAX],ans[MAX][MAX];
__int64 l;
int size,n; 
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

void MatrixInit(unsigned __int64 a[MAX][MAX],bool flag){//�����ʼ�� 
	for(int i=0;i<size;++i){
		for(int j=0;j<size;++j){
			if(flag)a[i][j]=array[i][j];//a=array
			else a[i][j]=(i == j);//a=1
		}
	}
}

void MatrixAdd(unsigned __int64 a[MAX][MAX],unsigned __int64 b[MAX][MAX]){//�������,a=a+b 
	for(int i=0;i<size;++i){
		for(int j=0;j<size;++j)a[i][j]+=b[i][j];
	}
}

void MatrixMult(unsigned __int64 a[MAX][MAX],unsigned __int64 b[MAX][MAX]){//�������,a=a*b 
	unsigned __int64 c[MAX][MAX]={0};
	for(int i=0;i<size;++i){
		for(int j=0;j<size;++j){
			for(int k=0;k<size;++k){
				c[i][j]+=a[i][k]*b[k][j];
			}
		}
	}
	for(int i=0;i<size;++i){
		for(int j=0;j<size;++j)a[i][j]=c[i][j];
	}
}

void MatrixPow(__int64 k){
	MatrixInit(sum,0);//sum=1
	MatrixInit(temp,1);//temp=array
	while(k){
		if(k&1)MatrixMult(sum,temp);
		MatrixMult(temp,temp);
		k>>=1;
	}
}

void MatrixSum(__int64 k){//A^1+A^2+A^3+...+A^n
	if(k == 1){MatrixInit(ans,1);return;}
	MatrixSum(k/2);
	MatrixPow((k+1)/2);//�����õ���k+1,��k+1���ܻᳬint,����k��lҪ��64λ 
	if(k&1){//A+(A+A^m)*(A^1+A^2+...);//m=(k+1)/2
		MatrixInit(temp,1);//temp=A;
		MatrixAdd(sum,temp);//sum=sum+temp=A^m+A
		MatrixMult(ans,sum);//ans=ans*sum=(A^1+A^2+...)*(A^m+A)
		MatrixAdd(ans,temp);//ans=ans+temp=ans+A=A^1+A^2+...)*(A^m+A)
	}else{//(1+A^m)*(A^1+A^2+...);//m=(k+1)/2
		MatrixInit(temp,0);//temp=1
		MatrixAdd(temp,sum);//temp=temp+sum=1+A^m
		MatrixMult(ans,temp);//ans=ans*temp=(A^1+A^2+...)*(1+A^m)
	}
}

int main(){
	while(scanf("%d%I64d",&n,&l)!=EOF){
		size=2;
		array[0][0]=1,array[0][1]=26;
		array[1][0]=0,array[1][1]=26;
		MatrixPow(l);//��26^1+26^2+...+26^l
		unsigned __int64 all=sum[0][1];
		printf("%I64u\n",all);
		size=0;
		root=New_TrieNode();
		for(int i=0;i<n;++i){
			scanf("%s",s);
			InsertNode(s);
		}
		Build_AC();
		MatrixSum(l);//A^1+A^2+A^3+...+A^n
		for(int i=0;i<size;++i)all-=ans[0][i];
		printf("%I64u\n",all);
	}
	return 0;
}
