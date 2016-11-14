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

const int MAX=26;

int main(){
	int j,n;
	while(cin>>n){
		int s[n];
		for(int i=0;i<n;++i)cin>>s[i];
		for(int i=0;i<26;++i){
			j=0;
			for(j=0;j<n;++j){//求出是哪个字母. 
				char a=s[j]^(i+'A');
				if(a<'A' || a>'Z'){//a^b=c ==> a=b^c.
					break;
				}
			}
			if(j == n){j=i;break;}//把找到的字母赋给j. 
		}
		for(int i=0;i<n;++i){
			cout<<(char) (s[i]^(j+'A'));
		}
		cout<<endl;
	}
	return 0;
} 