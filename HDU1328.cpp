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

const int MAX=51;
char s[MAX];

int main(){
	int n,num=1;
	cin>>n;
	while(n--){
		cin>>s;
		for(int i=0;i<strlen(s);++i){
			s[i]=(s[i]-'A'+1)%26+'A';
		}
		cout<<"String #"<<num++<<endl<<s<<endl<<endl;
	}
	return 0;
} 