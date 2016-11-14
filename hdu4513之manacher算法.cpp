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

const int MAX=100000+10;
int s[MAX*2],p[MAX*2];

int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		s[0]=-INF;
		for(int i=2;i<=n+n;i+=2){
			s[i-1]=INF;
			cin>>s[i];
		}
		s[n+n+1]=INF;
		s[n+n+2]=INF-3;
		int k=1,maxlen=0;
		for(int i=2;i<=n+n;++i){//这里有个小忽略,就是当k=2,i=3(k=2,i=4)时p[i]=p[2*k-i]=p[1]=0,无影响,因为后面while还是会匹配本身的 
			int maxr=k+p[k]-1;
			p[i]=min(p[2*k-i],max(maxr-i+1,1));//注意k初始化为1,若初始化k=0,则2*0-2=-2 
			while(s[i-p[i]] == s[i+p[i]]){
				if(s[i-p[i]] == INF)++p[i];
				else{//这里要做特殊判断,由于所选的回文序列要上升的 
					if((i-p[i]+2<=i && s[i-p[i]]<=s[i-p[i]+2]) || i-p[i]+2>i)++p[i];
					else break;
				}
			}
			if(i+p[i]>k+p[k])k=i;
			if(p[i]>maxlen)maxlen=p[i];
		}
		cout<<maxlen-1<<endl;
	}
	return 0;
} 