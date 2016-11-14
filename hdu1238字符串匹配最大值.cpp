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
const int MAX=102;
char start[MAX],last[MAX];
char s[MAX][MAX];
int main(){
	int t,n,k=0,num=0;
	cin>>t;
	while(t--){
		int MAX=0;
		k=0;
		int len=INF;
		cin>>n;
		for(int i=0;i<n;++i){
			cin>>s[i];
			if(strlen(s[i])<len)k=i;//找出最短的字符串. 
		}
		for(int i=strlen(s[k]);i>0;--i){//取字符串的多少长度. 
			for(int j=0;j+i<=strlen(s[k]);++j){//从第几个字符开始取. 
			    memset(start,0,sizeof start);
			    memset(last,0,sizeof last);
			    int m2=0;
				for(int m1=j;m1<j+i;++m1,++m2){
					start[m2]=s[k][m1];
				}
				for(int m3=0;m3<m2;++m3){
					last[m3]=start[m2-1-m3];
				}
				for(num=0;num<n;++num){
					if(num!=k){
						if(strstr(s[num],start)==NULL&&strstr(s[num],last)==NULL)break;
					}
				}
				if(num==n){
					MAX=i;
					break;
				}
			}
			if(num==n)break;
		}
		cout<<MAX<<endl;
	}
	return 0;
}