/*本题规律题:
00只能由01推到,即01->1001->00
01只能由1,00推到,即1->01,00->1010->01.
现设a[n]表示n秒时1的个数，
b[n]表示n秒时00的个数，
c[n]表示n秒时01的个数，
由题知0,1过一秒都会产生一个1， 
所以a[n+1]=2^n.....0秒1个数，1秒2*1个数，2秒2*1*2个数，...n秒2*1*2*2*2..*2个数=2^n.
b[n+1]=c[n];
c[n+1]=a[n]+b[n],
所以b[n]=c[n-1]=a[n-2]+b[n-2]=2^(n-3)+b[n-2].
其实本题多写几个样例就能发现另一个规律b[n]=2*b[n-2]+b[n-1]. 
注意本题大数相加.
*/
#include<iostream> 
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=1002;
int s[MAX][MAX/2]={{0},{0},{1},{1}};
int p[MAX]={1}; 
void calculate(){//大数相加 
	for(int i=4;i<MAX-1;++i){
		for(int c=0,j=0;j<400;++j){
			p[j]=p[j]*2+c;
			c=p[j]/10;
			p[j]=p[j]%10;	
		}
		for(int c=0,j=0;j<400;++j){
			s[i][j]=p[j]+s[i-2][j]+c;
			c=s[i][j]/10;
			s[i][j]=s[i][j]%10;
		}
	}
}
int main(){
	int n;
	calculate();
	while(cin>>n){
		bool flag=false;
		if(n==1){
			cout<<"0\n";
		}
		else{
			for(int i=300;i>=0;--i){
				if(s[n][i]||flag){
					printf("%d",s[n][i]);
					flag=true;
				}
			}
			cout<<endl;
		}
	}
	return 0;
}