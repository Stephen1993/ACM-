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

const int MAX=210;
char a[MAX],b[MAX],s[MAX];

int main(){
	while(cin>>a>>b){
		int p=0;
		int la=strlen(a);
		int lb=strlen(b);
		int k=0,i,j;
		for(i=la-1,j=lb-1;i>=0&&j>=0;--i,--j){
			s[k++]=(a[i]-'A'+b[j]-'A'+p)%26+'A';
			p=(a[i]-'A'+b[j]-'A'+p)/26;
		}
		while(i>=0){
			s[k++]=(a[i]-'A'+p)%26+'A';
			p=(a[i--]-'A'+p)/26;
		}
		while(j>=0){
			s[k++]=(b[j]-'A'+p)%26+'A';
			p=(b[j--]-'A'+p)/26;
		}
		while(p){
			s[k++]=p%26+'A';
			p=p/26;
		}
		while(s[k-1] == 'A')k--;
		for(i=k-1;i>=0;--i)cout<<s[i];
		cout<<endl;
	}
	return 0;
}