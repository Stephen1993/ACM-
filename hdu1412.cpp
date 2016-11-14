#include<iostream>
#include<algorithm>
using namespace std;
int main(){
	int s[20001],n,m;
	while(cin>>n>>m){
		for(int i=0;i<n;++i){
			cin>>s[i];
		}
		for(int i=n;i<n+m;++i){
			cin>>s[i];
		}
		sort(s,s+m+n);
		cout<<s[0];
		for(int i=1;i<m+n;++i){
		  	if(s[i]!=s[i-1]){
	  			cout<<' '<<s[i];
	  		}
		}
		cout<<endl;
	}
	return 0;
}