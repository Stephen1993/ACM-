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
const int MAX=100;
int height[MAX];
typedef struct noto{
	int x;
	int y;
	int z;
	int s;
	void mult(int &a,int &b,int &c) {
		x=a;
		y=b;
		z=c;
		s=a*b;
	}
	 friend bool cmp(noto a,noto b){
		return a.s>b.s;
	}
};
noto pos[MAX];
bool comp(const int &a,const int &b,const int &c,const int &d){
	if(a<c&&b<d||(a<d&&b<c)){
		return true;
	}
	return false;
}
int n;
int main(){
	int num=1,a,b,c;
	while(cin>>n,n){
		memset(height,0,sizeof height);
		int k=0;
		for(int i=0;i<n;++i){
			cin>>a>>b>>c;
			pos[k++].mult(a,b,c);
			pos[k++].mult(a,c,b);
			pos[k++].mult(b,c,a);
		}
		sort(pos,pos+k,cmp);
		int max_height=0;
		for(int i=0;i<k;++i){
			height[i]=pos[i].z;
			for(int j=0;j<i;++j){
				if(comp(pos[i].x,pos[i].y,pos[j].x,pos[j].y)){
					height[i]=max(height[i],height[j]+pos[i].z);
				}
			}
			max_height=max(max_height,height[i]);
		}
		cout<<"Case "<<num++<<": maximum height = "<<max_height<<endl;
	}
	return 0;
}