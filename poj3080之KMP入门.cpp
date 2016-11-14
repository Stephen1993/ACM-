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

const int MAX=60+10;
char s[12][MAX],temp[MAX],temp1[MAX];
int next[MAX];

void Strcpy(char *a,char *b,int S,int T){
	int k=0;
	for(int i=S;i<=T;++i)a[k++]=b[i];
	a[k]='\0';
}

void get_next(char *a){
	int i=-1,j=0,len=strlen(a);
	next[0]=-1;
	while(j<len){
		if(i == -1 || a[i] == a[j]){
			if(a[++i] == a[++j])next[j]=next[i];
			else next[j]=i;
		}else i=next[i];
	}
	return;
}

bool KMP(char *a,char *b){
	int i=0,j=0,lena=strlen(a),lenb=strlen(b);
	//if(lena>lenb)return false;
	get_next(a);
	while(i<lena && j<lenb){
		if(i == -1 || a[i] == b[j])++i,++j;
		else i=next[i];
	}
	if(i>=lena)return true;//if(i == lena)return true;
	return false;
}

int main(){
	int t,n,k;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=0;i<n;++i)cin>>s[i];
		int len=strlen(s[0]),flag=0;
		for(int i=len;i>0;--i){
			for(int j=0;j+i-1<len;++j){
				Strcpy(temp,s[0],j,j+i-1);
				for(k=1;k<n;++k){
					if(!KMP(temp,s[k]))break;
				}
				if(k == n){
					if(flag){
						if(strcmp(temp1,temp)>0)strcpy(temp1,temp);
					}else strcpy(temp1,temp);
					flag=1;
				}
			}
			if(flag)break;
			if(i == 3){cout<<"no significant commonalities"<<endl;break;}
		}
		if(flag)cout<<temp1<<endl;
	}
	return 0;
} 