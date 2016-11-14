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
		map<string,map<string,short> >s;//建立map的二维映射,map会自动对其中的关键字排序. 
		for(int i=0;i<n;++i){
			cin>>a>>b>>num;
			s[b][a]+=num;//s中的关键字已经排好序了,先按第一维排序,然后第二维,然后第三维...第n维. 
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