#include<iostream>
#include<cstdio>
using namespace std;
const int MAX=1299710;
int prime[MAX]={0};
void calculate(){
	for(int i=2;i<MAX;++i){
		if(!prime[i]){
			for(int j=2;j<MAX/i;j++){
				prime[j*i]=1;
			}
		}
	}
}
int main(){
	int n,a,b;
	calculate();
	while(cin>>n,n){
		if(!prime[n]){
			printf("0\n");
		}
		else{
			a=n-1;
			b=n+1;
			while(prime[a]||prime[b]){
				if(prime[a]){
					a=a-1;
				}
				if(prime[b]){
					b=b+1;
				}
			}
			cout<<b-a<<endl;
		}
	}
	return 0;
}