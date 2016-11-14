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

const int MAX=200000+10;
const int mod=10007;
char s[MAX];
int next[MAX];

void get_next(char *a,int len){
	int i=-1,j=0;
	next[0]=-1;
	while(j<len){
		if(i == -1 || a[i] == a[j])next[++j]=++i;
		else i=next[i];
	}
	return;
}

int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n>>s;
		get_next(s,n);
		int sum=0,k=0;
		for(int i=1;i<=n;++i){
			k=i;
			++sum;//加上前i个字串本身是一个匹配 
			while(next[k])sum=(sum+1)%mod,k=next[k];//加上第i-1个字符被匹配的次数 
		}
		cout<<sum<<endl;
	}
	return 0;
}