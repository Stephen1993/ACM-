/*
˼·:����С���ַ����ܰ���s1,s2�����ַ���,�������Ҫs1+s2���ɵĴ�
���s1,s2���ص��Ļ�(s1����s2,s2����s1��s1,s2�����ص�),��
aaaabb
    bbccc
������Ҫ�Ĵ��͸�����,���Կ�����s1ȥƥ��s2���s1ǰ׺��s2��׺�ص���
��s2ȥƥ��s1���s2ǰ׺��s1��׺�ص��� 
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

const int MAX=1000000+10;
char s1[MAX],s2[MAX];
int next[MAX];

void get_next(char *a,int len){
	int i=-1,j=0;
	next[0]=-1;
	while(j<len){
		if(i == -1 || a[i] == a[j]){
			if(a[++i] == a[++j])next[j]=next[i];
			else next[j]=i;
		}else i=next[i];
	}
	return;
}

int KMP(char *a,char *b,int lena,int lenb){
	int i=0,j=0;
	while(i<lena && j<lenb){
		if(i == -1 || a[i] == b[j])++i,++j;
		else i=next[i];
	}
	return i;
}

int main(){
	int n;
	cin>>n;
	while(n--){
		scanf("%s%s",s1,s2);
		int lena=strlen(s1),lenb=strlen(s2);
		get_next(s1,lena);
		int a=KMP(s1,s2,lena,lenb);
		get_next(s2,lenb);
		int b=KMP(s2,s1,lenb,lena);
		if(a == lena)cout<<lenb<<endl;
		else if(b == lenb)cout<<lena<<endl;
		else cout<<lena+lenb-max(a,b)<<endl;
	}
	return 0;
}