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

const int MAX=100000+10;
char s1[MAX],s2[MAX];

int main(){
	while(cin>>s1>>s2){
		int i=0,j=0,k=0;
		int lena=strlen(s1);
		int lenb=strlen(s2);
		if(lena<lenb){cout<<"no"<<endl;continue;}
		for(i=0;i<lena;++i){
			if(s1[i] == s2[0]){
				for(j=1,k=i+1;j<lenb;++j,++k){
					if(s1[k%lena] != s2[j])break;
				}
			}
			if(j == lenb){cout<<"yes"<<endl;break;}
		}
		if(i == lena)cout<<"no"<<endl;
	}
	return 0;
}