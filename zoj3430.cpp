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
char s[MAX];//输入的字符串 
int temp[MAX],size;//编码后的字符串,储存ASCII码
int Map[256];//映射A,B,C... =〉0,1,2...

struct TrieNode{
	int num,id;//记录病毒串个数和最后访问该串的序号
	TrieNode *fail,*next[256];//失败指针和下一个节点 
}*root,Node[MAX*10];

void ReEncode(char *a){//反编码 
	temp[0]=0;
	for(int i=0,len=0,x=0;a[i] && a[i] != '=';++i){
		len+=6,x=(x<<6)|Map[a[i]];
		if(len>=8){
			temp[++temp[0]]=(x>>(len-8))&0xff;//0xff是恰好8位1,x>>(len-8)保证是每8位进行&运算
			len-=8; 
		}
	}
}

TrieNode *New_TrieNode(){//分配节点 
	memset(&Node[size],0,sizeof(TrieNode));
	return &Node[size++];
}

void InsertNode(int *a){//插入病毒串 
	TrieNode *p=root;
	for(int i=1;i<=a[0];++i){
		if(!p->next[a[i]])p->next[a[i]]=New_TrieNode();
		p=p->next[a[i]];
	}
	++p->num;
}

void Build_AC(){//建立AC自动机 
	TrieNode *p,*next;
	queue<TrieNode *>q;
	q.push(root);
	while(!q.empty()){
		p=q.front();
		q.pop();
		for(int i=0;i<256;++i){
			if(p->next[i]){
				next=p->fail;
				while(next && !next->next[i])next=next->fail;
				p->next[i]->fail=next?next->next[i]:root;
				q.push(p->next[i]);
			}
		}
	}
}

int SearchTrie(int *a,int id){//查询模式串包含病毒串个数
	int sum=0;
	TrieNode *p=root,*next;
	for(int i=1;i<=a[0];++i){
		while(p != root && !p->next[a[i]])p=p->fail;
		p=p->next[a[i]];
		if(!p)p=root;
		next=p;
		while(next != root && next->id != id){
			sum+=next->num;
			next->id=id;
			next=next->fail;
		}
	}
	return sum;
}

void Init(){
	for(int i=0;i<26;++i)Map[i+'A']=i;
	for(int i=26;i<52;++i)Map[i-26+'a']=i;
	for(int i=52;i<62;++i)Map[i-52+'0']=i;
	Map['+']=62,Map['/']=63;
}

int main(){
	Init();
	int n;
	while(scanf("%d",&n)!=EOF){
		size=0;
		root=New_TrieNode();
		for(int i=0;i<n;++i){
			scanf("%s",s);//输入的是编码后的字符串 
			ReEncode(s);//进行反编码
			InsertNode(temp);
		}
		Build_AC();//建立AC自动机 
		cin>>n;
		for(int i=1;i<=n;++i){
			scanf("%s",s);
			ReEncode(s);
			printf("%d\n",SearchTrie(temp,i));
		}
		printf("\n");
	}
	return 0;
}