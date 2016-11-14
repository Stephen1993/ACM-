#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#include<cmath>
#define INF 99999999
using namespace std;
const int MAX=100;
__int64 n;
int t;
int main(){
	cin>>t;
	while(t--){
		scanf("%I64d",&n);
		double sum=n*log10(n)-(__int64)(n*log10(n));
		sum=pow(10,sum);
		cout<<int(sum)<<endl;
	}
	return 0;
}