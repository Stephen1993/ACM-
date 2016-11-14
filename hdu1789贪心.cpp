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

const int MAX=1001;
bool mark[MAX];
int* *s=NULL;

void define_array(){//�������� 
	s=new int*[MAX];//�����ά�����1ά�´�С 
	for(int i=0;i<MAX;++i)s[i]=new int[2];//����ڶ�ά�Ĵ�С 
}

bool cmp(int *a,int *b){//�Զ�ά����������� 
	if(a[1] == b[1])return a[0]>b[0];
	return a[1]>b[1];
}

int main(){
	define_array();
	int n,t;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;++i)cin>>s[i][0];
		for(int i=0;i<n;++i)cin>>s[i][1];
		sort(s,s+n,cmp);
		memset(mark,false,sizeof mark);
		int sum=0,j;
		//˼·:ÿ�ζ�ѡ���������,�ж����Ź��δ������Ƶ����쿪ʼ(����3����ӵ����쿪ʼ)��ǰ�ƿ��ܲ����������һ����� 
		for(int i=0;i<n;++i){
			for(j=s[i][0];j>0;--j){
				if(!mark[j]){mark[j]=true;break;}//�ù��ο������ 
			}
			if(j == 0)sum+=s[i][1];
		}
		cout<<sum<<endl;
	}
	return 0;
}