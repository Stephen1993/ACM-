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

const int MAX=1000+10;
int Left[MAX],Right[MAX];//��¼�ȵ�ǰ����λ��i��������ĸ���ڵ���hight[i]������˺����Ҷ�
int hight[2][MAX];//hight[i]��¼ÿһ�д��ϵ��µ���ǰ�еĸ�(������һ����ͬ��ĸ�ĸ���)
int n,m;
char s[MAX][MAX],Map[26][3];//Mapӳ��a,b,c,w,x,y,z��ת����� 

int MaxMatrix(){
	int sum=0;
	for(int k=0;k<3;++k){//ת����������ĸ 
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){//��hight 
				if(i == 0)hight[0][j]=1;
				else hight[i%2][j]=(Map[s[i][j]-'a'][k] == Map[s[i-1][j]-'a'][k]) ? hight[(i-1)%2][j]+1 : 1;
				Left[j]=Right[j]=j;
			}
			for(int j=1;j<m;++j){//��Left 
				while(Left[j]-1>=0 && hight[i%2][Left[j]-1]>=hight[i%2][j] && 
					  Map[s[i][Left[j]-1]-'a'][k] == Map[s[i][Left[j]]-'a'][k])Left[j]=Left[Left[j]-1];
			}
			for(int j=m-2;j>=0;--j){//��Right
				while(Right[j]+1<m && hight[i%2][Right[j]+1]>=hight[i%2][j] && 
					  Map[s[i][Right[j]+1]-'a'][k] == Map[s[i][Right[j]]-'a'][k])Right[j]=Right[Right[j]+1];
			}
			for(int j=0;j<m;++j){
				sum=max(sum,(Right[j]-Left[j]+1)*hight[i%2][j]);
			}
		}
	}
	return sum;
}

int main(){
	for(int i=0;i<3;++i)for(int j=0;j<3;++j)Map[i][j]=i+'a';
	Map['w'-'a'][0]='a',Map['w'-'a'][1]='b',Map['w'-'a'][2]='w';
	Map['x'-'a'][0]='x',Map['x'-'a'][1]='b',Map['x'-'a'][2]='c';
	Map['y'-'a'][0]='a',Map['y'-'a'][1]='y',Map['y'-'a'][2]='c';
	Map['z'-'a'][0]='a',Map['z'-'a'][1]='b',Map['z'-'a'][2]='c';
	while(~scanf("%d%d",&n,&m)){
		for(int i=0;i<n;++i)scanf("%s",s+i);
		printf("%d\n",MaxMatrix());
	}
	return 0;
}