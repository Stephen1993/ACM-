/*����������n�ּ�ͥ��ҵ��ȫ��������n!������˳��
����n!̫���ˣ��Ҷ��������ҵ1,2,3��1,3,2��2,1,3��3,2,1��3,1,2��˵
����������ĵ�����һ����һ���ģ�ֻ����ɵ�˳��ͬ�Ӷ��۵ķֲ�ͬ
���Կ��Խ������ͬ����ҵ������״̬ѹ����һ��״̬����¼�۵����ٷּ���
����״̬ѹ��dp
���ڵ���״̬i,�Ӻ���״̬����i�أ�ֻ��Ҫö�����е���ҵ
���������ҵk,i�к�����ҵk����ɣ���ôi�����ɺ�i״̬��ͬ��״̬������kδ��ɵ�
״̬j=i-(1<<k)�����k����,����jһ����iС�����״̬��0ö�ٵ�2^n-1��ôjһ������i֮ǰ�Ѿ�������� 
*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <iomanip>
#define INF 99999999
typedef long long LL;
using namespace std;

const int MAX=(1<<15)+10;
int n;
int dp[MAX],t[MAX],pre[MAX],dea[20],fin[20];//dp[i]��¼����״̬i�۵����ٷ�,tʱ��Ӧ�Ļ�ȥ��������
char s[20][110];

void output(int x){
	if(!x)return;
	output(x-(1<<pre[x]));
	printf("%s\n",s[pre[x]]);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;++i)scanf("%s%d%d",&s[i],&dea[i],&fin[i]);
		int bit=1<<n;
		for(int i=1;i<bit;++i){//ö�ٵ���״̬i
			dp[i]=INF;//��ʼ������״̬i�Ŀ۷� 
			for(int j=n-1;j>=0;--j){//��������ʱ���ַ���С���룬��ÿ�����j�൱�ڰ�j���ں�������������ж���dp[i]>dp[i-temp]+score 
				int temp=1<<j;      //������n-1��ʼ����������ж���dp[i]>=dp[i-temp]+score���0��ʼ 
				if(!(i&temp))continue;//״̬i��������ҵj�������ͨ�������ҵj����״̬i
				int score=t[i-temp]+fin[j]-dea[j];//i-temp��ʾû�����j���Ǹ�״̬
				if(score<0)score=0;//���j���۷�����С��0 
				if(dp[i]>dp[i-temp]+score){
					dp[i]=dp[i-temp]+score;
					t[i]=t[i-temp]+fin[j];//����״̬i���ѵ�ʱ��
					pre[i]=j;//����״̬i��ǰ��,Ϊ�������������ҵ��˳�� 
				} 
			}
		}
		printf("%d\n",dp[bit-1]);
		output(bit-1);//��������ҵ��˳�� 
	}
	return 0;
} 