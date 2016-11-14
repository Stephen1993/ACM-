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

const int MAX=5;
char s[3];
int number[MAX];
bool flag;

void check(char ch,int &num){
	if(ch == 'A')num=1;
	else if(ch == 'J')num=11;
	else if(ch == 'Q')num=12;
	else if(ch == 'K')num=13;
	else for(int i=2;i<10;++i){
		if(ch == i+'0'){num=i;break;}
	}
	if(ch == '1')num=10;
}

int f(int a,int op,int c){
	if(op == 0)return a+c;
	if(op == 1)return a-c;
	if(op == 2)return a*c;
	if(c && a%c == 0)return a/c;
	return INF;
}

bool calculate(int i,int j,int k){
	int temp1,temp2;
	temp1=f(number[0],i,number[1]);
	if(temp1 != INF)temp2=f(number[2],k,number[3]);
	if(temp2 == INF)temp1=INF;
	if(temp1 != INF)temp1=f(temp1,j,temp2);
	if(temp1 == 24 || temp1 == -24)return true;
	temp1=f(number[0],i,number[1]);
	if(temp1 != INF)temp1=f(temp1,j,number[2]);
	if(temp1 != INF)temp1=f(temp1,k,number[3]);
	if(temp1 == 24 || temp1 == -24)return true;
	return false;
}

void Perm(int k){
	if(k == 3){
		for(int i=0;i<4 && !flag;++i)for(int j=0;j<4 && !flag;++j)for(int k=0;k<4 && !flag;++k){
			flag=calculate(i,j,k);
		}
		return;
	}
	Perm(k+1);
	for(int i=k+1;i<4;++i){
		if(flag)return;
		if(number[i] == number[k])continue;
		swap(number[k],number[i]);
		Perm(k+1);
		swap(number[k],number[i]);
	}
}

int main(){
	while(~scanf("%s",s)){
		check(s[0],number[0]);
		for(int i=1;i<=3;++i){
			scanf("%s",s);
			check(s[0],number[i]);
		}
		flag=false;
		Perm(0);
		if(flag)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}