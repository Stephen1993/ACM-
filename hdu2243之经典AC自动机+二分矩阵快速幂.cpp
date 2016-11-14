/*
分析:相信做过poj2778的都知道如何求长度为n的模式串不包含病毒串的个数
没做过的建议去做，此题是poj2778的加强版
本题只需要求出长度<=n的所有串-包含病毒串的个数
即26^1+26^2+26^3+...+26^n-(A^1+A^2+A^3+...+A^n);//A是状态矩阵,即在满足条件下到达另一个状态的个数
26^1+...+26^n可以用快速幂求出h或者矩阵快速幂求出,A^1+...+A^n可以用矩阵二分快速幂求出或者构造:
|1 26| |Sn  | |Sn+1    |
|0 26|*|26^n|=|26^(n+1)|;//Sn=26^1+26^2+...+26^n

|A 1| |Sn| |Sn+1|
|0 1|*| A|=|A   |;//Sn=A+A^2+A^3+...+A^n

只要:|A 1|
     |0 1|
自乘n次与|S0|相乘即可,则可以用矩阵快速幂求 
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
	bool mark;//标记是否是词根
	int id;//记录节点序号
	TrieNode *fail,*next[26]; 
}*root,Node[MAX];

TrieNode *New_TrieNode(){
	memset(&Node[size],0,sizeof(TrieNode));
	Node[size].id=size;
	return &Node[size++];
}

void InsertNode(char *a){//插入词根 
	TrieNode *p=root;
	while(*a){
		if(!p->next[(*a)-'a'])p->next[(*a)-'a']=New_TrieNode();
		p=p->next[(*a)-'a'];
		++a;
	}
	p->mark=true;
}

void Build_AC(){//建立AC自动机并构造初始矩阵array
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
				if(p->next[i]->fail->mark)p->next[i]->mark=true;//表示这个前缀是词根,acg,ac
				q.push(p->next[i]); 
			}else p->next[i]=(p == root)?root:p->fail->next[i];//从p->id状态可以递推到p->fail->next[i]状态
			if(!p->next[i]->mark)++array[p->id][p->next[i]->id];//表示到达的下一个状态非词根,则可以到达 
		}
	}
}

void MatrixInit(unsigned __int64 a[MAX][MAX],bool flag){//矩阵初始化 
	for(int i=0;i<size;++i){
		for(int j=0;j<size;++j){
			if(flag)a[i][j]=array[i][j];//a=array
			else a[i][j]=(i == j);//a=1
		}
	}
}

void MatrixAdd(unsigned __int64 a[MAX][MAX],unsigned __int64 b[MAX][MAX]){//矩阵相加,a=a+b 
	for(int i=0;i<size;++i){
		for(int j=0;j<size;++j)a[i][j]+=b[i][j];
	}
}

void MatrixMult(unsigned __int64 a[MAX][MAX],unsigned __int64 b[MAX][MAX]){//矩阵相乘,a=a*b 
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
	MatrixPow((k+1)/2);//这里用到了k+1,而k+1可能会超int,所以k即l要用64位 
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
		MatrixPow(l);//求26^1+26^2+...+26^l
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
