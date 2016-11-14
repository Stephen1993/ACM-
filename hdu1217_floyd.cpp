#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cstdlib>
#include<algorithm>
#include<map>
#include<queue>
#include<iomanip>
#define INF 999999
using namespace std;
const int MAX=40;
double money[MAX][MAX];
int n,m,t;
bool floyd(){
	for(int k=1;k<m;++k){
		for(int i=1;i<m;++i){
			if(money[i][k]!=0){
				for(int j=1;j<m;++j){
					if(money[k][j]!=0&&money[i][j]<money[i][k]*money[k][j]){
						money[i][j]=money[i][k]*money[k][j];
						if(i==j&&money[i][j]>1){
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}
int main(){
	char s[MAX],first[MAX],second[MAX];
	double l;
	map<string,int>name;
	int num=1;
	while(scanf("%d",&n),n){
		m=1;
		for(int i=1;i<=n;++i){
			for(int j=i;j<=n;++j){
				money[i][j]=money[j][i]=0;
			}
		}
		for(int i=0;i<n;++i){
			scanf("%s",s);
			name[s]=m++;
		}
		scanf("%d",&t);
		for(int i=0;i<t;++i){
			scanf("%s%lf%s",first,&l,second);
			money[name[first]][name[second]]=l;
		}
		if(floyd())cout<<"Case "<<num++<<": Yes"<<endl;
		else cout<<"Case "<<num++<<": No"<<endl;
	}
	return 0;
}