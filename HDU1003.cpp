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
int present,prior,s,first,last,temp;

int main(){
	int t,n,num=1;
	cin>>t;
	while(t--){
		cin>>n;
 	    present=prior=-INF;
		for(int i=1;i<=n;++i){
			cin>>s;
			present+=s;
			if(s>present){present=s;temp=i;}//present=max(present+s,s)
			if(present>prior){prior=present;first=temp;last=i;}//prior=max(prior,present);
		}
		cout<<"Case "<<num++<<":\n";
		cout<<prior<<" "<<first<<" "<<last<<endl;
		if(t)cout<<endl;
	}
	return 0;
}