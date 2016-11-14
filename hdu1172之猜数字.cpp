#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=101;
int n,p[4],p1[4];
typedef struct{
	int a;
	int b;
	int c;
}noto;
noto s[MAX];
bool panduan(int x){
	int sum,pos_num;
	p1[0]=x%10;p1[1]=(x/10)%10;p1[2]=(x/100)%10;p1[3]=x/1000;
	for(int i=0;i<n;++i){
		sum=pos_num=0;
		p[0]=s[i].a%10;p[1]=(s[i].a/10)%10;p[2]=(s[i].a/100)%10;p[3]=s[i].a/1000;
		for(int j=0;j<4;++j){//先找第j位是否有匹配 
			if(p1[j]==p[j]){//判断p[j]是否与p1[j]匹配 
				sum++;
				pos_num++;
				p[j]=INF;
				continue;
			}
			for(int k=0;k<4;++k){
				if(p1[j]==p[k]&&p1[k]!=p[k]){//p[k]与p1[j]匹配但是p[k]不能与p1[k]匹配,否则要让p1[k]与p[k]匹配. 
					sum++;
					p[k]=INF;
					break;
				}
			}
		}
		if(sum!=s[i].b||pos_num!=s[i].c)return false;
	}
	return true;
}
int main(){
	int a,b,c;
	while(cin>>n,n){
		for(int i=0;i<n;++i){
			cin>>a>>b>>c;
			s[i].a=a;
			s[i].b=b;
			s[i].c=c;
		}
		int num=0,sum;
		for(int i=1000;i<=9999;++i){
			if(panduan(i)){
				sum=i;
				num++;
				if(num>=2){break;}
			}
		}
		if(num==1)
		cout<<sum<<endl;
		else cout<<"Not sure"<<endl;
	}
	return 0;
}