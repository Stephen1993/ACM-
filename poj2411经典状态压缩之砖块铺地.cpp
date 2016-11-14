/*��������1*2��שȥǡ������n*m�Ŀռ�,���ڵ�k�е�j��,��3��������õ�����
1:�ɵ�k-1�е�j��ש�����̽���k�е�j������
2:�ɵ�k�е�j�б�����ש����
3:��k�е�j��ש�����̽��õ�����
���Զ���ÿһ�е������ʵ������(1,0)��ʾ�õ���ש���ǲ���
������ÿһ�б��뵽���״ֻ̬��һ�֣����Ǳ�����(1)
����������3�������������ʽ�ֳ�����:
0��1��ʾ��k-1��j��������������k-1�б��������� 
����ÿһ���о�ÿһ�ֵ����״̬j,dp[j]��ʾ�����״̬�ж��������
�������ڵ�k-1��״̬j:10000111
��Ҫ�����k��״̬i:  01111011
�����Ҫ�����k��j��״̬��0��������k-1�иõ�״̬������0������һ���������������ų�ͻ
���Ե����k-1�иõ�ֻ����1��Ҳ����˵i|jһ��ÿһλ��1,Ҳ����һ�����ж��Ƿ������k��j����0��k-1��j����1 
�����Ҫ�����k��״̬j����1��������k-1�иõ���0����õ�״̬���Ե�������ж�j+1��
�����k-1�иõ���1�����k��j�е�1һ���Ǻ��̵����,����k�е�j+1��һ��Ҳ������Ϊ1
�Ӷ���k-1��j+1��һ���������̣����뱻��������������Ҳ��1.
�����ۺϵĵ�k��j�к͵�k-1��j�еĹ�ϵ(ÿһ��ÿһ�ж���ʾ�����״̬)
1:������������ӵ�j�м���ȥ�ж�j+1�� 
  1
  0
2:������������ӵ�j�м���ȥ�ж�j+1�� 
  0
  1
3:������������ӵ�j���жϵ�j+1���Ƿ�ȫ��1,Ȼ������жϵ�j+2��
  1
  1 
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

const int MAX=(1<<11)+10;
int n,m;
LL temp[MAX],dp[MAX],bin[15];
bool mark[MAX];

bool check(int i){
	while(i){
		if(i&1){
			i>>=1;
			if(!(i&1))return false;//��j����1���j+1�б�����1 
			i>>=1;//�����ж���һ�� 
		}else i>>=1;//�����ж���һ�� 
	}
	return true;
}

void Init(){
	memset(mark,false,sizeof mark);
	memset(temp,0,sizeof temp);
	for(int i=0;i<bin[m];++i){//��ʼ����һ�кͿ��Ե���ʲô״̬ 
		if(check(i))temp[i]=1,mark[i]=true;
	}
}

void DP(){
	for(int k=2;k<=n;++k){
		for(int i=0;i<bin[m];++i)dp[i]=0;
		for(int i=0;i<bin[m];++i){
			for(int j=0;j<bin[m];++j){
				if((i|j) != bin[m]-1)continue;//ÿһλ��֮�����ÿһλ��1(�ۺ�ǰ��3������ͷ�����֪)
				if(!mark[i&j])continue;//�ɳ�ʼ����ǰ������������������֪i&j����õ��ͳ�ʼ�����Ե����״̬һ������
				dp[i]+=temp[j];//i���Դ�j����,������j�ķ����� 
			}
		}
		for(int i=0;i<bin[m];++i)temp[i]=dp[i];
	}
}

int main(){
	bin[0]=1;
	for(int i=1;i<12;++i)bin[i]=2*bin[i-1];
	while(~scanf("%d%d",&n,&m),n+m){
		if(n<m)swap(n,m);//ʼ�ձ���m<n,���Ч�� 
		Init();
		DP();
		printf("%lld\n",temp[bin[m]-1]);//������һ�е���ʱ��״̬����ȫ����1 
	}
	return 0;
}