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

const int MAX=3001;
short s[MAX],hash[10001];

int main(){
	int n,m;
	while(cin>>n>>m){
		memset(hash,0,sizeof hash);
		int sum=0;
		for(int i=0;i<n;++i){
			cin>>s[i];
			for(int j=0;j<i;++j){
				hash[s[i]+s[j]]++;
				if(s[i]+s[j]>sum)sum=s[i]+s[j];
			}
		}
		cout<<sum , m-- , hash[sum]--;
        for(int i=sum;i>=0&&m;--i){
        	while(hash[i]&&m){
	        	cout<<' '<<i;
	        	hash[i]-- , m--;
	        }
        }
        cout<<endl;
	}
	return 0;
}