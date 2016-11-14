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
const int MAX=26;
typedef struct TrieNode{
	char word[12];
	TrieNode *next[MAX];
	TrieNode(){
		memset(next,NULL,sizeof next);
		word[0]='\0';
	}
};
TrieNode root;
void InsertNode(char *a,char *b){
	TrieNode *p=&root;
	int k=0;
	while(b[k]){
		if(!p->next[b[k]-'a']){
			p->next[b[k]-'a']=new TrieNode;//如果a,b,c....还没有,就开辟一个空间表示存a,b,c... 
		}
		p=p->next[b[k]-'a'];
		k++;
	}
	strcpy(p->word,a);
}
char *SearchTrie(char *a){
	TrieNode *p=&root;
	int k=0;
	while(a[k]&&p->next[a[k]-'a']){
			p=p->next[a[k++]-'a'];
	}
	if(!a[k]&&p->word[0]!='\0')return p->word;
	return a;
}
int main(){
	char a[3002],b[12];
	scanf("%s%*c",b);
	while(scanf("%s",a),strcmp(a,"END")){
		scanf("%s",b);
		InsertNode(a,b);
	}
	scanf("%s%*c",b);
	while(gets(a),strcmp(a,"END")){
		int k=0;
		for(int i=0;i<strlen(a);++i){
			if((a[i]>='a'&&a[i]<='z')||(a[i]>='A'&&a[i]<='Z')&&i!=strlen(a)-1){
				b[k++]=a[i];
			}
			else{
				b[k]='\0';
				k=0;
				printf("%s%c",SearchTrie(b),a[i]);
			}
		}
		cout<<endl;
	}
	return 0;
}
