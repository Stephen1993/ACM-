/*
˼·:�����Ѷ�������ν�ԭ�����ֺ��ж�ǰ׺�Ƿ��ǻ��ĺͺ�׺�Ƿ��ǻ��Ĵ�
����Խ�ԭ����ת��s2,Ȼ����ԭ��s1ȥƥ��s2,����s1ƥ�䵽��λ�þ���s1�����ǰ׺���Ĵ�
ͬ����s2ȥƥ��s1�õ�s2�����ǰ׺���Ĵ�,��s1������ڻ��Ĵ�
Ȼ�����next[k]������,next[k]��ת����λ�þ�����һ��ǰ׺���Ĵ�(0~k��x~len��ͬ,��x~len����0~k��ת�õ���,����0~k�ǻ��Ĵ�)
ֱ��k=0,������ǰ׺���Ĵ��ͺ�׺���Ĵ����,Ȼ���ԭ������ɨ��������ֵ���� 
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

const int MAX=500000+10;
char s[MAX*2];
int next[MAX*2],sum[MAX],val[27];
int pre[MAX],pos[MAX];//���ԭ���еĻ���ǰ׺�ͻ��ĺ�׺ 

void get_next(char *a,int len){
	int i=-1,j=0;
	next[0]=-1;
	while(j<len){
		if(i == -1 || a[i] == a[j])next[++j]=++i;
		else i=next[i];
	}
	return;
}

int main(){
	int n;
	cin>>n;
	while(n--){
		for(int i=0;i<26;++i)scanf("%d",&val[i]);
		scanf("%s",s);
		int len=strlen(s),k=len,temp=len;
		for(int i=1;i<=len;++i)sum[i]=sum[i-1]+val[s[i-1]-'a'];
		s[len]='#';//�м���һ���ַ�������next[len]��һ����#ǰ��,��Ѱ�ҵ��Ļ���ǰ׺һ����ԭ���Ļ���ǰ׺ 
		while(k)s[++len]=s[--k];//��ԭ����ת������ԭ������ 
		s[++len]='\0';
		get_next(s,len);
		k=len;
		while(next[k])pre[next[k]]=n+1,k=next[k];//���ǰnext[len]���ַ��ǻ��Ĵ�,����ǻ���ǰ׺ 
		for(int i=0;i<temp;++i){//ǰ���������ִ�����λ��ʵ�ֽ����ԭ����ת������ǰ��,Ϊ������ĺ�׺ 
			s[i]=s[i]^s[temp+1+i];
			s[temp+1+i]=s[i]^s[temp+1+i];
			s[i]=s[i]^s[temp+1+i];
		}
		get_next(s,len);
		k=len;
		while(next[k])pos[next[k]]=n+1,k=next[k];//���ǰnext[len]�ǻ��Ĵ�,����ǻ��ĺ�׺
		int ans=-INF,num=0;
		for(int i=1;i<temp;++i){//�����ֵ 
			if(pre[i] == n+1)num+=sum[i];
			if(pos[temp-i] == n+1)num+=sum[temp]-sum[i];
			if(num>ans)ans=num;
			num=0;
		}
		cout<<ans<<endl;
	}
	return 0;
}