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
const int MAX=1111;
char s[MAX],p[100];
int main(){
	int t;
	cin>>t;
	getchar();
	while(t--){
		int num=0;
		gets(s);
		for(int i=0,k=0;i<=strlen(s);++i){
			if(s[i]!=' '&&s[i]!='\0'){
				p[k++]=s[i];
			}
			if(s[i]==' '||s[i]=='\0'){
				if(num)cout<<' ';
				for(int j=k-1;j>=0;--j){
					cout<<p[j];
				}
				num++;
				k=0;
			}
		}
		cout<<endl;
	}
	return 0;
}