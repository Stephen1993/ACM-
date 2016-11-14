#include<iostream>
#include<cstdio>
using namespace std;
const int MAX=500;
int sum[MAX],s[7],m[MAX];
char a[7];
int n;
void trans(int A,int *B){
	int k=1;
	while(A)B[k++]=A%10,A=A/10;
	B[0]=k-1;
}
void mult(int *c,int *d){
	memset(m,0,sizeof(int)*(c[0]+d[0]+1));
	for(int i=1;i<=c[0];++i){
		for(int j=1;j<=d[0];++j){
			m[i+j-1]+=c[i]*d[j];
			m[i+j]+=m[i+j-1]/10;
			m[i+j-1]=m[i+j-1]%10;
		}
	}
	for(int i=1;i<=c[0]+d[0];++i)c[i]=m[i];
	c[0]=c[0]+d[0];
	if(!c[c[0]])c[0]--;
}
int main(){
	while(cin>>a>>n){
		if(n==0){
			cout<<"1\n";
			continue;
		}
		int num=0,A=0;
		memset(sum,0,sizeof sum);
		for(int i=0;i<6;++i){
			if(a[i]!='.')A=A*10+a[i]-'0';
			else num=5-i;
		}
		if(A==0){
			cout<<"0\n";
			continue;
		}
		while(A%10==0)num--,A=A/10;
		trans(A,s);
		sum[0]=sum[1]=1;
		for(int i=0;i<n;++i){
			mult(sum,s);
		}
		num=n=n*num;
		while(n>sum[0])sum[0]++;
		n=sum[0]-n;
		for(int i=sum[0];i>=1;--i){
			if(!n)cout<<'.';
			printf("%d",sum[i]);
			n--;
		}
		while(num<0){
			printf("0");
			num++;
		}
		cout<<endl;
	}
	return 0;
}