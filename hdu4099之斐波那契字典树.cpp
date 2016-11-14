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

const int MAX=100+10;
const int Base=10;
char a[MAX],b[MAX],sum[MAX];

struct TrieNode{
	int id;
	TrieNode *next[10];
	TrieNode(){
		id=-1;
		memset(next,0,sizeof next);
	}
}root;

void InsertNode(char *s,int id){
	int k=0;
	TrieNode *p=&root;
	while(s[k] && k<41){
		if(!p->next[s[k]-'0'])p->next[s[k]-'0']=new TrieNode;
		p=p->next[s[k++]-'0'];
		if(p->id == -1)p->id=id;
	}
}

int SearchTrie(char *s){
	int k=0;
	TrieNode *p=&root;
	while(s[k] && p->next[s[k]-'0'])p=p->next[s[k++]-'0'];
	if(s[k])return -1;
	return p->id;
}

void add(){
	int x,y,c=0;
	a[0]=b[0]='1';
	a[1]=b[1]=0;
	InsertNode(a,0);
	for(int i=2;i<100000;++i){
		int lena=strlen(a)-1;//a是0~lena是从高位到低位 
		int lenb=strlen(b)-1;//b是0~lenb是从高位到低位
		int k=0;
		if(lenb>49){//b是较长的串,只需要a,b的前50位即可 
			a[lena--]=0;//保证a,b相应的位置对应,比如a=45,b=456 ==>a=4,b=45,这样前50位不会出错 
			b[lenb--]=0;
		}
		while(lena>=0 || lenb>=0 || c){
			if(lena<0)x=0;
			else x=a[lena--]-'0';
			if(lenb<0)y=0;
			else y=b[lenb--]-'0';
			sum[k++]=(x+y+c)%10+'0';
			c=(x+y+c)/10;
		}
		for(int j=0;j<k/2;++j){ 
			sum[j]=sum[k-1-j]^sum[j];
			sum[k-1-j]=sum[j]^sum[k-1-j];
			sum[j]=sum[j]^sum[k-1-j];
		}
		sum[k]=0;
		//cout<<i<<": "<<sum<<endl;
		//system("pause");
		InsertNode(sum,i);//插入斐波那契数前缀
		strcpy(a,b);
		strcpy(b,sum);
	}
}

int main(){
	add();
	int n;
	while(scanf("%d",&n)!=EOF){ 
		for(int i=0;i<n;++i){
			scanf("%s",a);
			printf("Case #%d: %d\n",i+1,SearchTrie(a));
		}
	}
	return 0;
}