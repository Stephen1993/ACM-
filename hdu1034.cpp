#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=100;
int n;
int main(){
	int a,sum;
	bool flag=false;
	while(cin>>n,n){
     	vector<int>s(n+1);
        vector<int>p(n+1);
		for(int i=0;i<n;++i){
			scanf("%d",&a);
			s[i]=a;
		}
		for(int i=1;i<n;++i){
			if(s[i]!=s[0]){
				flag=true;
				break;
			}
		}
		sum=s[0];
		int num=0;
		while(flag){
			flag=false;
			if(num&1){
				s[0]=(p[n-1]/2+p[0]/2)%2==0?(p[n-1]/2+p[0]/2):(p[n-1]/2+p[0]/2)+1;
				for(int i=1;i<n;++i){
					s[i]=(p[i-1]/2+p[i]/2)%2==0?(p[i-1]/2+p[i]/2):(p[i-1]/2+p[i]/2)+1;
				}
				sum=s[0];
				for(int i=1;i<n;++i){
			       if(s[i]!=s[0]){
				      flag=true;
				      break;
			       }
		        }
			}
			else{
				p[0]=(s[n-1]/2+s[0]/2)%2==0?(s[n-1]/2+s[0]/2):(s[n-1]/2+s[0]/2)+1;
				for(int i=1;i<n;++i){
					p[i]=(s[i-1]/2+s[i]/2)%2==0?(s[i-1]/2+s[i]/2):(s[i-1]/2+s[i]/2)+1;
				}
				sum=p[0];
				for(int i=1;i<n;++i){
			        if(p[i]!=p[0]){
				       flag=true;
				       break;
			        }
                }
			}
			num++;
		}
		cout<<num<<' '<<sum<<endl;
	}
	return 0;
} 