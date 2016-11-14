#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

const int MAX=100;
string a,b;
int next[MAX];

void get_next(string &a){
	int i=0,j=-1;//i不变,j改变. 
	next[0]=-1;
	while(i<a.size()){//长度最好不要用a.size(),用len(len=a.size()). 
		if(j == -1 || a[i] == a[j]){
			if(a[++i] != a[++j])next[i]=j;
			else next[i]=next[j];
		}
		else j=next[j];
	}
	return;
}

bool KMP(string &a,string &b){
	int i=0,j=0;//i改变,j不改变. 
	while(i<(int)a.size() && j<(int)b.size()){//长度最好不要用a.size(),用len(len=a.size()). 
		if(i == -1 || a[i] == b[j])++i,++j;
		else i=next[i];
	}
	if(i>=(int)a.size())return true;//size返回的是unsigned类型. 
	return false;
}

int main(){
	while(cin>>a>>b){
		get_next(a);
		if(KMP(a,b))cout<<"a是b的子串"<<endl;
		else cout<<"a不是b的子串"<<endl;
	}
	return 0;
}