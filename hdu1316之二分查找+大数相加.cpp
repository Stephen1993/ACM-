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

const int MAX=1000;
int f[MAX][200];
char a[200],b[200];
int n;

void calculate(){
	f[0][0]=f[0][1]=1;
	f[1][0]=1,f[1][1]=2;
	for(int i=2;i<=1000;++i){
		int len=max(f[i-1][0],f[i-2][0]);
		for(int j=1;j<=len;++j){
			f[i][j]+=f[i-1][j]+f[i-2][j];
			f[i][j+1]=f[i][j]/10;
			f[i][j]=f[i][j]%10;
		}
		if(f[i][len+1])len++;
		f[i][0]=len;
		if(len>101){n=i;break;}
	}
	return;
}

bool cmp(int *p,char *s){
	for(int i=p[0];i>=1;--i){
		if(s[p[0]-i]-'0'>p[i])return false;
		else if(s[p[0]-i]-'0'<p[i])return true;
	}
	return true;
}

bool cmp2(int *p,char *s){
	for(int i=p[0];i>=1;--i){
		if(s[p[0]-i]-'0'>p[i])return false;
		else if(s[p[0]-i]-'0'<p[i])return true;
	}
	return false;
}

int binary_search(char *c){
	int left=0,right=n,mid;
	while(left<right){
		mid=left+(right-left)/2;
		if(f[mid][0]>strlen(c) || (f[mid][0] == strlen(c) && cmp(f[mid],c))){
			right=mid;
		}
		else left=mid+1;
		if(left == right-1)
		if((f[left][0]>strlen(c) || (f[left][0] == strlen(c) && cmp(f[left],c))))return left;
		else return right;
	}
	return right;
}

int binary_search2(char *c){
	int left=0,right=n,mid;
	while(left<right){
		mid=left+(right-left)/2;
		if(f[mid][0]<strlen(c) || (f[mid][0] == strlen(c) && !cmp2(f[mid],c))){
			left=mid;
		}
		else right=mid-1;
		if(left == right-1)
		if((f[right][0]<strlen(c) || (f[right][0] == strlen(c) && !cmp2(f[right],c))))return right;
		else return left;
	}
	return left;
}

int main(){
	calculate();
	while(cin>>a>>b,strcmp(a,"0") || strcmp(b,"0")){
		int x=binary_search(a);//找到第一个大于等于a的. 
		int y=binary_search2(b);//找到第一个小于等于b的. 
		cout<<y-x+1<<endl;
	}
	return 0;
}