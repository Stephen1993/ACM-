/*���������:
00ֻ����01�Ƶ�,��01->1001->00
01ֻ����1,00�Ƶ�,��1->01,00->1010->01.
����a[n]��ʾn��ʱ1�ĸ�����
b[n]��ʾn��ʱ00�ĸ�����
c[n]��ʾn��ʱ01�ĸ�����
����֪0,1��һ�붼�����һ��1�� 
����a[n+1]=2^n.....0��1������1��2*1������2��2*1*2������...n��2*1*2*2*2..*2����=2^n.
b[n+1]=c[n];
c[n+1]=a[n]+b[n],
����b[n]=c[n-1]=a[n-2]+b[n-2]=2^(n-3)+b[n-2].
��ʵ�����д�����������ܷ�����һ������b[n]=2*b[n-2]+b[n-1]. 
ע�Ȿ��������.
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
void calculate(){//������� 
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