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
const int MAX=102;
map<string,string>s;
map<string,string>::iterator p;
int main(){
	string a,b;
	while(cin>>a,a!="XXXXXX"){
		b=a;
		sort(b.begin(),b.end());
		s.insert(pair<string,string>(a,b));
	}
	while(cin>>a,a!="XXXXXX"){
		bool flag=true;
		sort(a.begin(),a.end());
		for(p=s.begin();p!=s.end();p++){
			if(p->second==a){
				cout<<p->first<<endl;
				flag=false;
			}
		}
		if(flag)cout<<"NOT A VALID WORD"<<endl;
		cout<<"******"<<endl;
	}
	return 0;
}