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
const int MAX=10;
int main(){
	int t,n;
	string a,b;
	short num;
	cin>>t;
	while(t--){
		cin>>n;
		map<string,map<string,short> >s;//����map�Ķ�άӳ��,map���Զ������еĹؼ�������. 
		for(int i=0;i<n;++i){
			cin>>a>>b>>num;
			s[b][a]+=num;//s�еĹؼ����Ѿ��ź�����,�Ȱ���һά����,Ȼ��ڶ�ά,Ȼ�����ά...��nά. 
		}
		map<string,map<string,short> >::iterator p=s.begin();
		map<string,short>::iterator d;
		for(;p!=s.end();++p){
			cout<<p->first<<endl;
			for(d=p->second.begin();d!=p->second.end();++d){
				cout<<"   |----"<<d->first<<'('<<d->second<<')'<<endl;
			}
		}
		if(t)cout<<endl;
	}
	return 0;
}