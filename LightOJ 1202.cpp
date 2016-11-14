#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;
int main(){
	int r1,c1,r2,c2,t;
	scanf("%d",&t);
	int num=1;
	while(t--){
		scanf("%d%d%d%d",&r1,&c1,&r2,&c2);
		int x=abs(r1-r2);
		int y=abs(c1-c2);
		if(abs((y+x))&1){
			cout<<"Case "<<num++<<": impossible"<<endl;
		}
		else if((abs(x-y))!=0){
			cout<<"Case "<<num++<<": "<<"2\n";
		}
		else{
			cout<<"Case "<<num++<<": "<<"1\n";
		}
	}
	return 0;
}