#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=100010;
int s[MAX];
int n;
__int64 k;
int main(){
	while(scanf("%d%I64d",&n,&k)!=EOF){
		for(int i=0;i<n;++i){
			scanf("%d",&s[i]);
		}
		sort(s,s+n);
		int i;
		__int64 j;
		for(i=0;i<n;i+=j){
			for(j=1;s[i]==s[i+j];++j);
			if(j*n>=k)break;
			k-=j*n;
		}
		printf("%d %d\n",s[i],s[(k-1)/j]);
	}
	return 0;
}
/*
1,2,3,4,4,4,5
���31λ��������ĵ�һλ��4��Ȼ��ӵ�һλ��ʼ����1λ��Ϊ������ĵڶ�λ��
Ȼ��������ĵ�һλ������3λ����Ϊ������4�����ڶ�λ��Ϊ������ĵڶ�λ����������k/j��Ϊ������ĵڶ�λ. 
*/ 