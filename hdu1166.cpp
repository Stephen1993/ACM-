#include<iostream>
#include<string.h>
using namespace std;
const int MAX=55555;
int d[MAX];
int main(){
	int t,n,a,b;
	int num=1;
	char s[10];
	cin>>t;
	while(t--){
		cout<<"Case "<<num++<<':'<<endl;
		cin>>n;
		for(int i=1;i<=n;++i){
			scanf("%d",&d[i]);
		}
		while(cin>>s,strcmp(s,"End")){
			cin>>a>>b;
			if(!strcmp(s,"Add")){
				d[a]+=b;
			}
			else if(!strcmp(s,"Sub")){
				d[a]-=b;
			}
			else{
				int sum=0;
				for(int j=a;j<=b;++j){
					sum+=d[j];
				}
				cout<<sum<<endl;
			}
		}
	}
	return 0;
}