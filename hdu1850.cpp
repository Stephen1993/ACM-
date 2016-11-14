#include<iostream>
using namespace std;
int main(){
	int s[102]={0};
	int m;
	while(cin>>m,m){
		int sum=0;
		int num=0;
		for(int i=0;i<m;++i){
			cin>>s[i];
			sum=sum^s[i];
		}
		for(int i=0;i<m;++i){
			if((sum^s[i])<s[i])num++;
		}
		cout<<num<<endl;
	}
	return 0;
}