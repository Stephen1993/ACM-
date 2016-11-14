#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=14;
char s[MAX];
int n;
void calculate(){
	int l=strlen(s);
	for(int a=l-1;a>=0;a--){
		for(int b=l-1;b>=0;b--){
			if(b!=a){
				for(int c=l-1;c>=0;c--){
					if(c!=a&&c!=b){
						for(int d=l-1;d>=0;d--){
							if(d!=a&&d!=b&&d!=c){
								for(int e=l-1;e>=0;e--){
									if(e!=a&&e!=b&&e!=c&&e!=d){
										int sum=(s[a]-64)-(s[b]-64)*(s[b]-64)+(s[c]-64)*(s[c]-64)*(s[c]-64)-(s[d]-64)*(s[d]-64)*(s[d]-64)*(s[d]-64)+(s[e]-64)*(s[e]-64)*(s[e]-64)*(s[e]-64)*(s[e]-64);
										if(sum==n){
											cout<<s[a]<<s[b]<<s[c]<<s[d]<<s[e]<<endl;
											return;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	cout<<"no solution"<<endl;
}
int main(){
	while(cin>>n>>s,strcmp(s,"END")){
		int sum=0;
		sort(s,s+strlen(s));
		calculate();
	}
	return 0;
} 