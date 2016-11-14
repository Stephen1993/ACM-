#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<queue> 
#define INF 99999999
using namespace std;
const int MAX=1005;
int p[MAX];
char s[MAX];
int main(){
	int sum=0;
	while(cin>>s){
		memset(p,0,sizeof p);
		int k=0;
		bool flag=true;
		for(int i=0;i<strlen(s);++i){
			if(s[i]=='5'){
				if(!flag)
				  k++;
				flag=true;
				continue;
			}
			p[k]=p[k]*10+s[i]-'0';
			flag=false;
		}
		if(s[strlen(s)-1]!='5')k++;
		sort(p,p+k);
		for(int i=0;i<k;++i){
			if(i!=0)printf(" %d",p[i]);
			else cout<<p[i];
		}
		cout<<endl;
	}
	return 0;
}