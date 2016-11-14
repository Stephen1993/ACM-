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

const int MAX=1000000+10;
int a[MAX];
int b[10000+10];
int next[10000+10];

void get_next(int a[],int len){
	int i=0,j=-1;
	next[0]=-1;
	while(i<len){
		if(j == -1 || a[i] == a[j]){
			if(a[++i] == a[++j])next[i]=next[j];
			else next[i]=j;
		}else j=next[j];
	}
}

int KMP(int a[],int b[],int lena,int lenb){
	int i=0,j=0;
	while(i<lenb && j<lena){
		if(j == -1 || a[j] == b[i])++i,++j;
		else j=next[j];
	}
	if(j == lena)return i-j+1;
	return -1;
}

int main(){
	int n,m,t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(int i=0;i<n;++i)scanf("%d",&a[i]);
		for(int i=0;i<m;++i)scanf("%d",&b[i]);
	 	get_next(b,m);
	 	cout<<KMP(b,a,m,n)<<endl;
	}
	return 0;
} 