#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
#include<vector>
#define INF 99999999
using namespace std;
const int MAX=10;
typedef struct{
	double sum;
	int pos;
}point;
bool cmp(point a,point b){
	if(a.sum==b.sum){
		return a.pos<b.pos;
	}
	return a.sum>b.sum;
}
vector<point>s;
vector<int>p;
int n,m,k;
int main(){
	point a;
	while(scanf("%d%d%d",&n,&m,&k)!=EOF){
		s.clear();
		p.clear();
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				scanf("%lf",&a.sum);
				if(i!=0){
					s[j].sum+=a.sum;
				}
				else{
					a.pos=j+1;
					s.push_back(a);
				}
			}
		}
		sort(s.begin(),s.end(),cmp);
		for(int i=0;i<k;++i){
		   p.push_back(s[i].pos); 
		}
		sort(p.begin(),p.end());
		for(int i=k-1;i>=0;--i){
			printf("%d%c",p[i],i?' ':'\n');
		}
	}
	return 0;
}