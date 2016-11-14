/*
详细报告: 
http://hi.baidu.com/faithyzy/item/c8c8142502418bd2a517b6ee
*/
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
const int MAX=1001;
int x[MAX],y[MAX];
int main(){
	int n;
	while(cin>>n,n){
		for(int i=0;i<n;++i){
			scanf("%d",&x[i]);
		}
		for(int i=0;i<n;++i){
			scanf("%d",&y[i]);
		}
		sort(x,x+n);
		sort(y,y+n);
		int num=0;
		for(int i=0,j=0,a=n-1,b=n-1;i<=a;){
			if(x[i]>y[j]){//田最慢的马快于国王最慢的马 
				num++;
				i++;
				j++;
			}
			else if(x[i]<y[j]){//田最慢的马慢于国王最慢的马
			    num--;
				i++;
				b--;//让田最慢的马和国王最快的马比 
			}
			else{//田最慢的马和国王最慢的马同速 
				if(x[a]>y[b]){//田最快的马快于国王最快的马 
					num++;
					a--;
					b--;
				}
				else{//田最快的马慢于或等于于国王最快的马
				    if(x[i]!=y[b])num--;
					i++;
					b--;
				}
			}
		}
		cout<<num*200<<endl;
	}
	return 0;
}