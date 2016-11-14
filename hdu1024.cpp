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

const int MAX=1000001;
int *s,*present,*prior;
//present����ǰj�����Ұ�����j������i������������,prior��ʾǰj����i�������е����� 

int main(){
	int m,n;
	while(cin>>m>>n){
		s=new int[n+1];
		for(int i=1;i<=n;++i)scanf("%d",s+i);
		present=new int[n+1];
		prior=(int *)calloc(n+1,sizeof(int));//calloc��maccoc����������������ڴ��������Ѷ����ݳ�ʼ��Ϊ0
		present[0]=0;//ֻ��Ҫ��present[0]��ʼ��,��Ϊpresent[n]������present[n-1]�õ�
		int sum=0;
		for(int i=1;i<=m;++i){
			sum=-INF;
			for(int j=i;j<=n-m+i;++j){//m��ʱ��Ӧ���ټ���ǰn����,m-1��ʱ��Ӧ����Ҫ����ǰn-1����,...i�ζ�Ӧ����Ҫ����ǰn-m+i���� 
				//present[j-1]���������ǰj-1����i�����е����ֵ,��j=j-1ʱ���Ѿ�������present[j-1] 
			   //prior[j-1]���������ǰj-1����i-1�����е����ֵ,��Ϊ��û����prior[j-1]Ϊi�ε����ֵ
				present[j]=max(present[j-1]+s[j],prior[j-1]+s[j]);//����j��������ǰi�ε����������Գ�һ����ǰi-1�κϳ�i�� 
				prior[j-1]=sum;//����Ϊǰj-1����i�ε����ֵ,sum����ǰj-1����i�ε����ֵ 
				sum=max(present[j],sum);//����ǰj����i�ε����ֵ 
			}//present[j]=max(present[j-1]+s[j],prior[j-1]+s[j]);prior[j-1]=(present[j-1],prior[j-2]);
			prior[n-m+i]=sum;//prior[n]=max(present[n],prior[n-1]);
		} 
		cout<<sum<<endl;
		delete[] s;
		delete[] present;
		delete[] prior;
	}
	return 0;
}