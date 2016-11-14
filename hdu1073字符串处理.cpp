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
const int MAX=5005;
string start,end,system_date,use_date;
string chuli(string a){
	string s;
	for(int i=0;i<a.size();++i){
		if(a[i]!=' '&&a[i]!='\t'&&a[i]!='@'){
			s+=a[i];
		}
	}
	return s;
}
int main(){
	int t;
	cin>>t;
	getchar();
	while(t--){
		while(getline(cin,start),start!="START");
		getline(cin,system_date);
		while(getline(cin,end),end!="END"){
			if(end.size()==0)system_date+="@";
			else system_date+=end;
		}
		while(getline(cin,start),start!="START");
		getline(cin,use_date);
		while(getline(cin,end),end!="END"){
			if(end.size()==0)use_date+="@";
			else use_date+=end;
		}
		if(system_date==use_date){
			cout<<"Accepted"<<endl;
		}
		else{
			if(chuli(system_date)==chuli(use_date)){
				cout<<"Presentation Error"<<endl;
			}
			else{
				cout<<"Wrong Answer"<<endl;
			}
		}
	}
	return 0;
}