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

const int MAX=102;
double Time[MAX],p[MAX];//time表示到达从第i个充电站充完电直达第i个充电站所需要的最少时间

int main(){
	int n;
	double c,t,vr,vt1,vt2,l;
	while(cin>>l){
		cin>>n>>c>>t>>vr>>vt1>>vt2;
		for(int i=1;i<=n;++i)cin>>p[i];
		p[n+1]=l;
		for(int i=1;i<=n+1;++i)Time[i]=INF;
		for(int i=1;i<=n+1;++i){
			for(int j=0;j<i;++j){//通过第j个充电站到达第i个充电站 
				double s=p[i]-p[j];
				double T=s>c ? c/vt1+(s-c)/vt2 : s/vt1;
				if(j)T+=t;
				Time[i]=min(Time[i],Time[j]+T);
			}
		}
		if(Time[n+1]<=l/vr)cout<<"What a pity rabbit!"<<endl;
		else cout<<"Good job,rabbit!"<<endl;
	}
} 
