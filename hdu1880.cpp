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

const int MAX=100001;
map<string,string>a;
map<string,string>b;

int main(){
	string z,t;
	string tmp, word, meaning;
	getline(cin, tmp);
	while (tmp != "@END@")
	{
		string::size_type idx = tmp.find(']');
		word = tmp.substr(0, idx + 1);
		meaning = tmp.substr(idx + 2, tmp.size() - idx - 2);
		a.insert(make_pair(word, meaning));
		b.insert(make_pair(meaning, word));
		getline(cin, tmp);
	}
	int n;
	cin>>n;
	getline(cin,z);
	for(int i=0;i<n;++i){
		getline(cin,z);
		if(z[0] == '['){
			if(a[z] != "\0"){cout<<a[z];}
			else printf("what?");
		}
		else{
			if(b[z] != "\0"){t=b[z];t=t.substr(1,t.size()-2);cout<<t;}
			else printf("what?");
		}
		cout<<endl;
	}
	return 0;
}