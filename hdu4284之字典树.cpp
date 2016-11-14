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

const int MAX=10;
const int N=5000+10;
char s[N][8],ch[8];
char d[10][5]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
int sum;

struct TrieNode{
	int num;
	TrieNode *next[MAX];
	TrieNode(){
		num=0;
		memset(next,0,sizeof next);
	}
}root;

void InsertNode(char *a){
	int k=0;
	TrieNode *p=&root;
	while(a[k]){
		if(!p->next[a[k]-'0'])p->next[a[k]-'0']=new TrieNode;
		p=p->next[a[k++]-'0'];
		++p->num;
	}
}

int SearchTrie(char *a){
	int k=0;
	TrieNode *p=&root;
	while(a[k] && p->next[a[k]-'0'])p=p->next[a[k++]-'0'];
	if(a[k])return 0;
	return p->num;
}

void trans(char *a){
	int len=strlen(a);
	for(int i=0;i<len;++i){
		if(a[i] == 'a' || a[i] == 'b' || a[i] == 'c')a[i]='2';
		else if(a[i] == 'd' || a[i] == 'e' || a[i] == 'f')a[i]='3';
		else if(a[i] == 'g' || a[i] == 'h' || a[i] == 'i')a[i]='4';
		else if(a[i] == 'j' || a[i] == 'k' || a[i] == 'l')a[i]='5';
		else if(a[i] == 'm' || a[i] == 'n' || a[i] == 'o')a[i]='6';
		else if(a[i] == 'p' || a[i] == 'q' || a[i] == 'r' || a[i] == 's')a[i]='7';
		else if(a[i] == 't' || a[i] == 'u' || a[i] == 'v')a[i]='8';
		else if(a[i] == 'w' || a[i] == 'x' || a[i] == 'y' || a[i] == 'z')a[i]='9';
		else a[i]='1';
	}
}

void Free(TrieNode *p){
	for(int i=0;i<10;++i)if(p->next[i])Free(p->next[i]);
	delete p;
}

int main(){
	int t,n,m;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<n;++i)scanf("%s",s[i]);
		for(int i=0;i<m;++i){
			scanf("%s",ch);
			trans(ch);
			InsertNode(ch);
		}
		for(int i=0;i<n;++i)printf("%d\n",SearchTrie(s[i]));
		for(int i=0;i<10;++i){
			if(root.next[i])Free(root.next[i]);
			root.next[i]=0;
		} 
	}
	return 0;
}