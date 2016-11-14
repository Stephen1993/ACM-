#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<algorithm>
#include<queue>
#include<iomanip>
#define INF 999999
using namespace std;
const int MAX=1111;
int main(){
	int a,b,t;
	scanf("%d",&t);
	int num=1;
	while(t--){
		scanf("%d%d",&a,&b);
		if(a==0){
			cout<<"Case "<<num++<<": "<<"0\n";
			continue;
		}
		int sum=0;
		if(a<=b){
			sum+=b*4+10+9;
		}
		if(a>b){
			sum+=a*4+(a-b)*4+10+9;
		}
		cout<<"Case "<<num++<<": "<<sum<<endl;
	}
	return 0;
}