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
char s[MAX];//������ַ��� 
int temp[MAX],size;//�������ַ���,����ASCII��
int Map[256];//ӳ��A,B,C... =��0,1,2...

struct TrieNode{
	int num,id;//��¼�����������������ʸô������
	TrieNode *fail,*next[256];//ʧ��ָ�����һ���ڵ� 
}*root,Node[MAX*10];

void ReEncode(char *a){//������ 
	temp[0]=0;
	for(int i=0,len=0,x=0;a[i] && a[i] != '=';++i){
		len+=6,x=(x<<6)|Map[a[i]];
		if(len>=8){
			temp[++temp[0]]=(x>>(len-8))&0xff;//0xff��ǡ��8λ1,x>>(len-8)��֤��ÿ8λ����&����
			len-=8; 
		}
	}
}

TrieNode *New_TrieNode(){//����ڵ� 
	memset(&Node[size],0,sizeof(TrieNode));
	return &Node[size++];
}

void InsertNode(int *a){//���벡���� 
	TrieNode *p=root;
	for(int i=1;i<=a[0];++i){
		if(!p->next[a[i]])p->next[a[i]]=New_TrieNode();
		p=p->next[a[i]];
	}
	++p->num;
}

void Build_AC(){//����AC�Զ��� 
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

int SearchTrie(int *a,int id){//��ѯģʽ����������������
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
			scanf("%s",s);//������Ǳ������ַ��� 
			ReEncode(s);//���з�����
			InsertNode(temp);
		}
		Build_AC();//����AC�Զ��� 
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