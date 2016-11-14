#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=2;
bool flag=false;

typedef struct TrieNode{
	bool mark;
	TrieNode *next[MAX];
	TrieNode(){
		memset(next,0,sizeof next);
		mark=false;
	}
};
TrieNode root;
//stack<TrieNode *>Free;

void InsertNode(char *s){
	int k=0;
	TrieNode *p=&root;
	while(s[k]){
		if(!p->next[s[k]-'0']){
			p->next[s[k]-'0']=new TrieNode;
		}else if(s[k+1] == '\0')flag=true;//��ʾ���Ǳ��˵�ǰ׺. 
		p=p->next[s[k]-'0'];
		k++;
		if(p->mark == true)flag=true;//��ʾ�б���������ǰ׺. 
	}
	p->mark=true;
}

void Free(TrieNode *p){
	for(int i=0;i<2;++i){
		if(p->next[i])Free(p->next[i]);
	}
	delete p;
}

int main(){
	char s[10];
	int num=1;
	while(cin>>s){
		flag=false;
		while(s[0] != '9'){
			if(!flag)
			InsertNode(s);
			cin>>s;
		}
		if(flag)cout<<"Set "<<num++<<" is not immediately decodable\n";
		else cout<<"Set "<<num++<<" is immediately decodable\n";
		/*if(root.next[0])Free.push(root.next[0]);
		if(root.next[1])Free.push(root.next[1]);
		TrieNode *p;
		while(!Free.empty()){
			p=Free.top();
			Free.pop();
			for(int i=0;i<2;++i){
				if(p->next[i])Free.push(p->next[i]);
			}
			delete p;
		}*/
		Free(&root);//ɾ���ڵ�.(Ϊʲô�Ѹ��ڵ��ͷŵ�Ҳ��AC��)
		/*for(int i=0;i<2;++i){
			if(root.next[i])Free(root.next[i]);
		}*/
		root.next[0]=root.next[1]=NULL;//ע���ͷ������ڵ������ָ��ҪΪ��. 
	}
	return 0;
}