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
char s1[MAX],s2[MAX];
int next[MAX],sum[MAX],val[27];
int per[MAX],pos[MAX];//�������ǰ׺���Ĵ��ͺ�׺���Ĵ�

void get_next(char *a,int len){
	int i=-1,j=0;
	next[0]=-1;
	while(j<len){
		if(i == -1 || a[i] == a[j])next[++j]=++i;
		else i=next[i];
	}
}

int KMP(char *a,char *b,int len){
	int i=0,j=0;
	while(i<len && j<len){
		if(i == -1 || a[i] == b[j])++i,++j;
		else i=next[i];
	}
	return i;
}

int main(){
	int n,k;
	cin>>n;
	while(n--){
		for(int i=0;i<27;++i)scanf("%d",&val[i]);
		scanf("%s",s1);
		int len=strlen(s1);
		for(int i=0;i<len;++i)s2[i]=s1[len-1-i],sum[i+1]=sum[i]+val[s1[i]-'a'];
		get_next(s1,len);
		k=KMP(s1,s2,len);//��s1���ǰ׺���Ĵ�λ��
		while(k)per[k]=n+1,k=next[k];//�������ǰ׺���Ĵ� 
		get_next(s2,len);
		k=KMP(s2,s1,len);//��s1����׺���Ĵ�λ�� 
		while(k)pos[k]=n+1,k=next[k];//������к�׺���Ĵ� 
		int ans=-INF,num=0;
		for(int i=1;i<len;++i){
			if(per[i] == n+1)num+=sum[i];
			if(pos[len-i] == n+1)num+=sum[len]-sum[i];
			if(num>ans)ans=num;
			num=0;
		}
		cout<<ans<<endl;
	}
} 