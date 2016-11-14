/*
�����ĿҪ���õ�ŷ��·�����֪ʶ������ҲҪ���鼯����Ŀ˵���ǣ�����n�����ʣ�Ҫ���ж���Щ�����ܲ�����β������
�����Ŀ��˼�󣬽���ת���������ַ�������ȡ��λ��ĸ��Ϊ�±�����ʾ���ڵ�ĳ��֣��Լ����Ӧ�ڵ���Ⱥͳ��ȵ����ӣ�
ת��Ϊ���鼯��Ӧ�ü��ɡ���ô�ӿ�������һ������λ��ĸ�ڵ㹹�ɵ�ͼ�����ҽ���ͼ��һ��ŷ����·����ŷ��ͨ·��ʱ��
����������Ŀ��Ҫ������ŷ����·��ŷ��ͨ·���ж������ܽ�Ϊ���£�
1�����еĵ���ͨ
2��ŷ����·�����е����Ⱥͳ���һ����
3��ŷ��ͨ·��������� - ���� = 1���յ�� ���� - ��� = 1�� ���������е���� = ����
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
const int MAX=27;
int father[MAX],rank[MAX];
int in_du[MAX],out_du[MAX],number[MAX];//��ȣ�����.��Ȳ����ڳ��ȵĵ�. 
bool mark[MAX];//��ǵ����Ƿ����.
int n;
char s[1002];
void make_set(int num){
	for(int i=0;i<num;++i){
		father[i]=i;
		rank[i]=1;
	}
}
int findset(int v){
	if(v!=father[v]){
		father[v]=findset(father[v]);
	}
	return father[v];
} 
void Union(int x,int y){
	int a=findset(x);
	int b=findset(y);
	if(x==y)return;
	if(rank[a]>rank[b]){
		father[b]=a;
		rank[a]+=rank[b];
	}
	else{
		father[b]=a;
		rank[b]+=rank[a];
	}
}
int main(){
	int t,first,last;
	cin>>t;
	while(t--){
		int sum=0;//��¼���ڵ�. 
		memset(in_du,0,sizeof in_du);
		memset(out_du,0,sizeof out_du);
		memset(mark,false,sizeof mark);
		memset(number,0,sizeof number);
		make_set(26);
		cin>>n;
		for(int i=0;i<n;++i){
			scanf("%s",s);
			first=s[0]-'a';
			last=s[strlen(s)-1]-'a';
			in_du[last]++;
			out_du[first]++;
			mark[first]=mark[last]=true;
			Union(first,last);
		}
		for(int i=0;i<26;++i){
			if(findset(i)==i&&mark[i]){
				sum++;
			}
		}
		if(sum>1){
			cout<<"The door cannot be opened."<<endl;
			continue;
		}
		int k=0;
		for(int i=0;i<26;++i){
			if(mark[i]&&in_du[i]!=out_du[i]){
				number[k++]=i;
			}
		}
		if(k>2){
			cout<<"The door cannot be opened."<<endl;
			continue;
		}
		if(k==0){
			cout<<"Ordering is possible."<<endl;
			continue;
		}
		if(k==2){
			if(in_du[number[0]]+1==out_du[number[0]]&&in_du[number[1]]-1==out_du[number[1]]||in_du[number[0]]-1==out_du[number[0]]&&in_du[number[1]]+1==out_du[number[1]]){
				cout<<"Ordering is possible."<<endl;
			}
			else{
				cout<<"The door cannot be opened."<<endl;
			}
		}
	}
	return 0;
} 