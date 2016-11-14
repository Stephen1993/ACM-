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
const int MAX=101;
typedef struct{
	int num;
	string time;
}noto;
noto s[MAX];
int sum[6],n;
int main(){
	while(cin>>n,n>=0){
		memset(sum,0,sizeof sum);
		for(int i=1;i<=n;++i){
			cin>>s[i].num>>s[i].time;
			sum[s[i].num]++;
		}
		for(int i=1;i<=n;++i){
			if(s[i].num==5){
				cout<<"100\n";
			}
			else if(s[i].num){
				int m=0;
				for(int j=1;j<=n;++j){
					if(s[j].num==s[i].num){
						if(s[j].time<=s[i].time){
							m++;
						}
					}
				}
				if(m<=sum[s[i].num]/2||m==1){
					cout<<105-(5-s[i].num)*10<<endl;
				}
				else cout<<100-(5-s[i].num)*10<<endl;
			}
			else cout<<"50\n";
		}
		cout<<endl;
	}
	return 0;
}