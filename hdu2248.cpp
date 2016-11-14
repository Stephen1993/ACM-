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

const int MAX=20000+10;
const int Base=10000;
int s[MAX],n;//s[j]记录的前i个数mod n为j的最后一个位置 
char str[110];
int temp[3000],sum[3000],A[3000];
bool prime[110];

void Prime(){
	prime[1]=true;
	for(int i=2;i*2<=100;++i)prime[i*2]=true;
	for(int i=3;i*i<=100;++i){
		if(!prime[i]){
			for(int j=i*i;j<=100;j+=2*i)prime[j]=true;
		}
	}
}

int factor(int x,int k){
	int num=0;
	while(x%2 == 0)++num,x=x/2;
	if(num>=k)return 2;
	for(int i=3;i*i<=x;i+=2){
		if(x%i == 0){
			while(x%i == 0)++num,x=x/i;
			if(num>=k)return i;
		}
	}
	if(x != 1)++num;
	if(num>=k)return x;
	return 0;
}

void Mult(int *A,int *B){
	int l=A[0]+B[0]-1,i,j,k;
	memset(temp,0,sizeof(int)*(l+3));
	for(i=1,k=1;i<=A[0];++i){
		k=i;
		if(A[i]){//为0本次就不用计算了 
			for(j=1;j<=B[0];++j,++k){
				temp[k]+=A[i]*B[j];
				if(temp[k]>=Base){
					temp[k+1]+=temp[k]/Base;
					temp[k]=temp[k]%Base;
				}
			}
		}
	}
	while(temp[k]>=Base){
		temp[k+1]+=temp[k]/Base;
		temp[k]=temp[k++]%Base;
	}
	if(!temp[k])--k;
	A[0]=k;
	for(i=1;i<=k;++i)A[i]=temp[i];
}

void FastPow(int k){
	sum[0]=1,sum[1]=1;
	A[0]=1,A[1]=2;
	while(k){
		if(k&1)Mult(sum,A);
		Mult(A,A);
		k>>=1;
	}
}

void problem1(){
	scanf("%s",str);
	int num=strlen(str);
	if(!prime[num])printf("Yes.\n");
	else printf("No.\n");
}

void problem2(){
	int a,l=INF,p,k,t=0;
	scanf("%d",&n);
	memset(s+1,-1,sizeof(int)*(n+1));
	s[0]=0;
	for(int i=1;i<=n;++i){
		scanf("%d",&a);
		p=(t+a)%n;
		if(s[p] != -1)if(i-s[p]<l)l=i-s[p],k=s[p]+1;//k记录满足条件的开始位置 
		s[p]=i;
		t=p;
	}
	if(l == INF)printf("可怜的亦纷菲!\n");
	else{
		for(int i=k;i<k+l-1;++i)printf("%d ",i);
		printf("%d\n",k+l-1);
	}
}

void problem3(){
	int x,k;
	scanf("%d%d",&x,&k);
	int temp=factor(x,k);
	if(temp)printf("%d\n",temp);
	else printf("no\n");
}

void problem4(){
	scanf("%d",&n);
	FastPow(n);
	printf("%d",sum[sum[0]]);
	for(int i=sum[0]-1;i>0;--i)printf("%04d",sum[i]);
	printf("\n");
}

int main(){
	Prime();
	while(~scanf("%s",str)){
		if(strcmp(str,"Swords") == 0)problem1();
		else if(strcmp(str,"Stones") == 0)problem2();
		else if(strcmp(str,"Search") == 0)problem3();
		else problem4();
	}
	return 0;
}