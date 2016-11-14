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

//calculate是计算对于所有的数从最低位开始计算最低位的数可以有的个数 
void calculate(int n,int p){//n代表该数,p代表该数最低位以下可以变化的个数 
	int x=n/10,y=n%10;
	n=x;
	for(int i=0;i<10;++i)b[i]+=x*p;//最高位为0~x-1的时候最低位可以是0~9 
	b[0]-=p;//最高位为0且最低位也为0则当前最低位不存在 
	for(int i=0;i<=y;++i)b[i]+=p;//最高位为x的时候最低位只能0~y 
	while(x)b[x%10]+=(y+1)*p,x=x/10;
	if(n)calculate(n-1,p*10);
}

int main(){
	int A,B;
	while(cin>>A>>B,A+B){
		if(A>B)B^=A,A=B^A,B=B^A;
		memset(b,0,sizeof b);
		calculate(A-1,1);//计算0~A-1之间含有0~9的个数
		copy(a,b);//把b数组赋值给a数组并且b[i]=0;
		calculate(B,1);//计算0~B之间含有0~9的个数
		for(int i=0;i<9;++i)cout<<b[i]-a[i]<<' ';
		cout<<b[9]-a[9]<<endl; 
	}
	return 0;
}