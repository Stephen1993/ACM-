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
const int MAX=105;
char s[MAX];
int sum[MAX];
int main(){
	int t,max_long;
	cin>>t;
	while(t--){
		memset(sum,0,sizeof sum);
		max_long=0;
		while(cin>>s,strcmp(s,"0")){
			max_long=max_long>strlen(s)?max_long:strlen(s);
			for(int j=0,i=strlen(s)-1;i>=0;--i){//求和 
				sum[j++]+=s[i]-'0';
			}
			int c=0;
			for(int i=0;i<max_long+5;++i){//进位判断 
				sum[i]=sum[i]+c;
				c=sum[i]/10;
				sum[i]=sum[i]%10;
			}
		}
		while(!sum[max_long]&&max_long)max_long--;//找到输出点.
		for(;max_long>=0;){
			cout<<sum[max_long--];
		} 
		cout<<endl;
		if(t){
			cout<<endl;
		}
	}
}