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

const int MAX=100;
int height[MAX];

typedef struct node{
	int w;
	int l;
	int h;
	bool operator<(node b)const{
		if(w == b.w)return l>b.l;
		return w>b.w;
	}
};
node s[MAX];

int main(){
	int n,a,b,c,num=1;
	while(cin>>n,n){
		int k=0;
		for(int i=0;i<n;++i){
			cin>>a>>b>>c;
			//对a,b,c排序. 
			if(a>b)a=a+b,b=a-b,a=a-b;
			if(a>c)a=a+c,c=a-c,a=a-c;
			if(b>c)b=b+c,c=b-c,b=b-c;
			s[k].w=a,s[k].l=b,s[k++].h=c;//以a,b为底,c为高. 
			s[k].w=a,s[k].l=c,s[k++].h=b;//以a,c为底,b为高.
			s[k].w=b,s[k].l=c,s[k++].h=a;//以b.c为底,a为高. 
		}
		sort(s,s+k);//排序,以底边中最小的边来排序,这样使得第i个箱子只能放在第i个箱子的前面的箱子上,当然也可以按照底边面积排序. 
		int Max=s[0].h;
		height[0]=s[0].h;
		for(int i=1;i<k;++i){
			height[i]=s[i].h;
			for(int j=0;j<i;++j){
				if(s[i].w<s[j].w && s[i].l<s[j].l){
					height[i]=max(height[i],s[i].h+height[j]);
				}
			}
			Max=max(Max,height[i]);
		}
		cout<<"Case "<<num++<<": maximum height = "<<Max<<endl;
	}
	return 0;
}