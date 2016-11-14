#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 9999999
using namespace std;

const int MAX=1000000+10;
char a[60],b[MAX];

struct TrieNode{
	int num;//��¼���ʵ�����
	TrieNode *next[26],*fail;//��һ���ڵ��ʧ��ָ��
	TrieNode(){
		num=0;
		fail=0;
		memset(next,0,sizeof next);
	} 
}*root;

void InsertNode(char *a){
	int k=0;
	TrieNode *p=root;
	while(a[k]){
		if(!p->next[a[k]-'a'])p->next[a[k]-'a']=new TrieNode;
		p=p->next[a[k++]-'a'];
	}
	++p->num;
}

void Build_AC(){
	TrieNode *p=root,*next;
	queue<TrieNode *>q;
	q.push(p);
	while(!q.empty()){//һ��һ��Ĺ���fail 
		p=q.front();
		q.pop();
		for(int i=0;i<26;++i){
			if(p->next[i]){
				next=p->fail;
				while(next){
					if(next->next[i]){p->next[i]->fail=next->next[i];break;}
					next=next->fail;
				}
				if(!next)p->next[i]->fail=root;
				q.push(p->next[i]);
			}
		}
	}
}

int SearchTrie(char *a){
	int k=0,sum=0;
	TrieNode *p=root,*next; 
	while(a[k]){
		while(!p->next[a[k]-'a'] && p != root)p=p->fail;
		p=p->next[a[k++]-'a'];
		if(!p)p=root;
		next=p;
		while(next != root && next->num != -1){//������0���ж��Ƿ��Ѿ�Ѱ�ҹ� 
			sum+=next->num;
			next->num=-1;//����ע��һ��Ҫ��ֵΪ����,����Ϊ0 
			next=next->fail;
		}
	}
	return sum;
}

void Free(TrieNode *p){
	for(int i=0;i<26;++i)if(p->next[i])Free(p->next[i]);
	delete p;
}

int main(){
	int T,n;
	cin>>T;
	while(T--){
		root=new TrieNode;
		cin>>n;
		for(int i=0;i<n;++i){
			cin>>a;
			InsertNode(a);//���뵥�� 
		}
		Build_AC();//����ʧ��ָ��,Ҳ���ǽ���AC�Զ����ľ���
		cin>>b;
		cout<<SearchTrie(b)<<endl;//��ѯ���еĵ�������
		Free(root);
	}
	return 0;
}
/* 
10
2
abcdef
bcd
abcdef
1
h
hhhhh
5
bhea
her
he
h
ha
bhera
5
bhea
her
he
h
ha
bhera
*/