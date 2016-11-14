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
const int MAX=133;
typedef struct{
	int pos;
	int number;
	int time;
}noto;
noto s[MAX];
bool cmp(noto a,noto b){
	if(a.number==b.number){
		if(a.time==b.time){
			return a.pos<b.pos;
		}
		return a.time<b.time;
	}
	return a.number>b.number;
}
int main(){
	int n,g,s1,c,m,a,b,c1,d;
	while(cin>>n>>g>>s1>>c>>m,n||g||s1||c||m){
		for(int i=1;i<=n;++i){
			s[i-1].pos=i;
			scanf("%d %d:%d:%d",&d,&a,&b,&c1);
			s[i-1].number=d;
			s[i-1].time=c1+b*60+a*3600;
		}
		sort(s,s+n,cmp);
		int num=0;
		for(int i=0;i<n;++i){
			if(s[i].pos==m){
				num++;
				break;
			}
			num++;
		}
		if(num<=g)cout<<"Accepted today? I've got a golden medal :)"<<endl;
		else if(num<=g+s1)cout<<"Accepted today? I've got a silver medal :)"<<endl;
		else if(num<=g+s1+c)cout<<"Accepted today? I've got a copper medal :)"<<endl;
		else cout<<"Accepted today? I've got an honor mentioned :)"<<endl;
	}
	return 0;
}