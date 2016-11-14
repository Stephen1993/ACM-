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

const int MAX=256;
char s[5000];
int temp[5000];//记录还原后的字符串的ASCII码
int size,Map[MAX];//映射 

struct TrieNode{
	int id;//标记是否是病毒串,用最后查询到的字符串序号标记 
	int num;//记录病毒串个数 
	TrieNode *fail,*next[MAX];//失败指针个下一个节点
	/*TrieNode(){
		id=0,fail=0;
		memset(next,0,sizeof next);
	}*/
}*root,Node[50000];

TrieNode *New_TrieNode(){
	memset(&Node[size],0,sizeof(TrieNode));
	return &Node[size++];
}

void InsertNode(int *a){
	TrieNode *p=root;
	for(int i=1;i<=a[0];++i){
		if(!p->next[a[i]])p->next[a[i]]=New_TrieNode();
		p=p->next[a[i]];
	}
	++p->num;
}

void Build_AC(){
	TrieNode *p=root,*next;
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

int SearchTrie(int *a,int id){
	int sum=0;
	TrieNode *p=root,*next;
	for(int i=1;i<=a[0];++i){
		while(!p->next[a[i]] && p != root)p=p->fail;
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

void ReEncode(char *a){
	temp[0]=0;
	for(int i=0,x=0,len=0;a[i] && a[i] != '=';++i){
		len+=6,x=(x<<6)|Map[a[i]];
		if(len>=8){
			temp[++temp[0]]=((x>>(len-8))&0xff);//x>>(len-8)是截断成8的整数倍,0xff恰好8位1
			len-=8;
		} 
	}
}

void Init(){
	for(int i=0;i<26;++i)Map[i+'A']=i;
	for(int i=26;i<52;++i)Map[i-26+'a']=i;
	for(int i=52;i<62;++i)Map[i-52+'0']=i;
	Map['+']=62,Map['/']=63;
}

/*void Free(TrieNode *p){
	for(int i=0;i<256;++i)if(p->next[i])Free(p->next[i]);
	delete p;
}*/

int main(){
	Init();
	int n;
	while(scanf("%d",&n)!=EOF){
		size=0;
		root=New_TrieNode();
		for(int i=0;i<n;++i){
			scanf("%s",s);//输入的是加密的编码,需要去还原
			ReEncode(s);//反编码
			InsertNode(temp);//插入原串 
		}
		Build_AC();//建立AC自动机 
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			scanf("%s",s);
			ReEncode(s);
			printf("%d\n",SearchTrie(temp,i+1));//查询匹配个数
		}
		cout<<endl; 
		//Free(root);
	}
	return 0;
}