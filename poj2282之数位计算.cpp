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

const int MAX=10;
int a[MAX],b[MAX];

void copy(int* a,int* b){
	for(int i=0;i<10;++i)a[i]=b[i],b[i]=0;
}

//calculate�Ǽ���������е��������λ��ʼ�������λ���������еĸ��� 
void calculate(int n,int p){//n�������,p����������λ���¿��Ա仯�ĸ��� 
	int x=n/10,y=n%10;
	n=x;
	for(int i=0;i<10;++i)b[i]+=x*p;//���λΪ0~x-1��ʱ�����λ������0~9 
	b[0]-=p;//���λΪ0�����λҲΪ0��ǰ���λ������ 
	for(int i=0;i<=y;++i)b[i]+=p;//���λΪx��ʱ�����λֻ��0~y 
	while(x)b[x%10]+=(y+1)*p,x=x/10;
	if(n)calculate(n-1,p*10);
}

int main(){
	int A,B;
	while(cin>>A>>B,A+B){
		if(A>B)B^=A,A=B^A,B=B^A;
		memset(b,0,sizeof b);
		calculate(A-1,1);//����0~A-1֮�京��0~9�ĸ���
		copy(a,b);//��b���鸳ֵ��a���鲢��b[i]=0;
		calculate(B,1);//����0~B֮�京��0~9�ĸ���
		for(int i=0;i<9;++i)cout<<b[i]-a[i]<<' ';
		cout<<b[9]-a[9]<<endl; 
	}
	return 0;
}