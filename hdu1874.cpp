#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int a,b,x,s1,t,n,m,s[202][202];
	while(cin>>n>>m){
		memset(s,-1,sizeof(s));
		for(int i=0;i<n;++i){
			s[i][i]=0;
		}
		for(int i=0;i<m;++i){
			cin>>a>>b>>x;
			if(s[a][b]>x||s[a][b]==-1)
			s[a][b]=s[b][a]=x;
		}
		cin>>s1>>t;
		for(int k=0;k<n;++k){
			for(int i=0;i<n;++i){
				for(int j=0;j<n;++j){
					if(s[i][k]!=-1&&s[k][j]!=-1){
						if(s[i][j]==-1||s[i][j]>s[i][k]+s[k][j])
						  s[i][j]=s[i][k]+s[k][j];
					}
				}
			}
		}
		cout<<s[s1][t]<<endl;
	}
	return 0;
}