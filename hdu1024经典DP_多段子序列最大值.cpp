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
const int MAX=1000001;
int *prev,*present,*s;
int n,m,m_max;
int calculate(){
	present = (int*)malloc(sizeof(int) * (n + 2));
    prev = (int*)calloc(n + 2, sizeof(int));
	*prev=*present=0;
	for(int i=1;i<=m;++i){
		m_max=-INF;
		for(int j=i;j<=n;++j){
			present[j]=max(present[j-1]+s[j],prev[j-1]+s[j]);
			prev[j-1]=m_max;
			m_max=max(m_max,present[j]);
		}
		prev[n]=m_max;
	}
	delete prev;
	delete present;
	return m_max;
}
int main(){
	while(scanf("%d%d",&m,&n)!=EOF){
		s=new int[n+1];
		for(int i=0;i<n;++i){
			scanf("%d",s+i);
		}
		s--;
		cout<<calculate()<<endl;
		delete s;
	}
	return 0;
}
