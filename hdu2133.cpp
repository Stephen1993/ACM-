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

const int MAX=10;
char s[7][10]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
int month[14]={0,31,28,31,30,31,30,31,31,30,31,30,31};

bool check(int &y){
	if((y%4 == 0 && y%100 !=0) || y%400 ==0)return true;//ÊÇÈòÄê
	return false; 
}

int main(){
	int y,m,d;
	while(scanf("%d%d%d",&y,&m,&d)!=EOF){
		if(m==0 || d==0){printf("illegal\n");continue;}
		if(month[m] == 30 && d==31){printf("illegal\n");continue;}
		if(!check(y) && m == 2 && d==29){printf("illegal\n");continue;}
		if(m == 2 && d>29){printf("illegal\n");continue;}
		int temp=d;
		for(int i=1;i<m;++i)temp+=month[i];
		if(check(y) && m>2)++temp;
		for(int i=1;i<y;++i){
			temp+=365;
			if(check(i))++temp;
			temp%=7;
		}
		printf("%s\n",s[temp]);
	}
	return 0;
}