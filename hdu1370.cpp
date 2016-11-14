#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 999999999
using namespace std;

const int MAX=21253;
int s[24][29][34];//23,28,33的最小公倍数是21252(否则要求出它们的最小公倍数然后打表),所以求余时循环周期是21252. 

int main(){
	int p,e,c,d,num=0,t;
	for(int i=1;i<MAX;++i){
		s[i%23][i%28][i%33]=i;
	}
	cin>>t;
	while(t--){
		num=0;
		while(cin>>p>>e>>c>>d,p!=-1 || e!=-1 || c!=-1 || d!=-1){
			int sum=s[p%23][e%28][c%33]-d;
			while(sum<=0)sum+=21252;
		    printf ("Case %d: the next triple peak occurs in %d days.\n",++num,sum);
	    }
	    if(t)cout<<endl;
	}
	return 0;
}
