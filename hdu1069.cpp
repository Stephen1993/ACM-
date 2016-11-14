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
			//��a,b,c����. 
			if(a>b)a=a+b,b=a-b,a=a-b;
			if(a>c)a=a+c,c=a-c,a=a-c;
			if(b>c)b=b+c,c=b-c,b=b-c;
			s[k].w=a,s[k].l=b,s[k++].h=c;//��a,bΪ��,cΪ��. 
			s[k].w=a,s[k].l=c,s[k++].h=b;//��a,cΪ��,bΪ��.
			s[k].w=b,s[k].l=c,s[k++].h=a;//��b.cΪ��,aΪ��. 
		}
		sort(s,s+k);//����,�Եױ�����С�ı�������,����ʹ�õ�i������ֻ�ܷ��ڵ�i�����ӵ�ǰ���������,��ȻҲ���԰��յױ��������. 
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