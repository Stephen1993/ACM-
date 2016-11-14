#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<iomanip>
#include<limits.h>
using namespace std;
const int MAX=31;
int s[MAX][MAX+10000]={0};
int main(){
	s[1][0]=1;
	for(int i=2;i<=30;++i){
		int num=1;
		int k=0;
		for(int j=0;s[i-1][j]!=0;j++){
			if(s[i-1][j]==s[i-1][j+1]){
				num++;
			}
			else{
				s[i][k++]=num;
				s[i][k++]=s[i-1][j];
				num=1;
			}
		}
	}
	int n;
	while(cin>>n,n){
	    int sum=0;
	    for(int i=0;s[n][i]!=0;++i){
	       sum++;
	    }
		cout<<sum<<endl;
	}
	return 0;
}