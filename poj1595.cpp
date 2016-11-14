#include<iostream>
using namespace std;
const int MAX=10020;
int prime[MAX]={0};
void calculate(){
	for(int i=2;i<=MAX;++i){
		if(!prime[i]){
			for(int j=2;j<=MAX/i;++j){
				prime[j*i]=1;
			}
		}
	}
}
int main(){
	int n,c;
	calculate();
	while(cin>>n>>c){
		bool flag=false;
		cout<<n<<' '<<c<<':';
		int num=0;
		for(int i=1;i<=n;++i){
			if(!prime[i])num++;
		}
		if(2*c>num)c=num;
		else
		if(num&1)c=c*2-1;
		else c=c*2;
		int sum=0;
		for(int i=1;i<=n;++i){
			if(flag)break;
			if(!prime[i]){
				if(sum==(num-c)/2){
					flag=true;
					for(int j=i;j<=n&&c;++j){
						if(!prime[j]){
							cout<<' '<<j;
							c--;
						}
					}
				}
				sum++;
			}
		}
		cout<<endl<<endl;
	}
	return 0;
}