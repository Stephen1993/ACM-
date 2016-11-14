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

const int MAX=21;
__int64 s[MAX]={0,1,4};//记录i个数有多少种序列. 
int seq[MAX];//记录i个数时的原始序列.

void calculate(){
	for(int i=3;i<=20;++i){
		s[i]=i*(s[i-1]+1);
	}
}

void init(int &n){
	for(int i=1;i<=n;++i){
		seq[i]=i;
	}
}

void change_seq(int &num,int &n){
	for(int i=num;i<=n;++i){
		seq[i]=seq[i+1]; 
	}
}

void shuaixuan(int &n,__int64 &m){
	int num=(m-1)/(s[n]/n)+1;
	cout<<seq[num];
	m=m-(num-1)*(s[n]/n)-1;
	if(m)cout<<' ';
	--n;
	change_seq(num,n);
	return;
}

int main(){
	int n;
	__int64 m;
	calculate();
	while(scanf("%d%I64d",&n,&m)!=EOF){
		init(n);
		while(m){
			shuaixuan(n,m);
		}
		cout<<endl;
	}
	return 0;
} 
/*
http://blog.csdn.net/lulipeng_cpp/article/details/7249639
*/