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

const int MAX=200003;
int dpx[MAX],dpy[MAX];//dpx�����浱ǰ��һ��ǰi�����ֵ,dpy������ǰi�пɵ����ֵ.

int main(){
	int n,m,s;
	while(cin>>n>>m){
		for(int i=2;i<=n+1;++i){
			for(int j=2;j<=m+1;++j){
				scanf("%d",&s);
				dpx[j]=max(dpx[j-1],dpx[j-2]+s);//��ǰ����ǰj���ܻ�õ����ֵ. 
			}
			dpy[i]=max(dpy[i-1],dpy[i-2]+dpx[m+1]);//ǰi������ܻ�õ����ֵ. 
		}
		cout<<dpy[n+1]<<endl;
	}
	return 0;
} 