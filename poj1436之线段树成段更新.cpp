/*
˼·:��y����н���,��ÿ���߶ΰ������С��������,�ӵ�1���߶ο�ʼ��ѯ������
��ѯ�����߶�����ʾ�������ڲ�ͬ��ɫ����(���ɼ��߶���)���Ҽ�¼�ɼ��߶�,Ȼ����¸�������ɫ 
������������ɼ��߶�����
����ע��:0,4,1 �� 0,2,2 �� 3,4,2�������߶θ��ǵĽ��������0~4ͨ���߶������ҿɼ��߶�������,��ʵ��3��(2~3�ɼ���һ��)
���԰Ѳ�ѯ���µ�����*2,�����������ݱ��0,8,1 �� 0,4,2 �� 6,8,2��4~6֮��ɼ�һ���߶� 
*/
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

const int MAX=8000+10;
int color[MAX*2<<2];//����ɼ��߶α��(��ɫ����) 
bool mark[MAX][MAX];//��¼��i���߶κ͵�j���߶οɼ�

struct edge{
	int y1,y2,x,id;
	edge(){}
	edge(int Y1,int Y2,int X,int ID):y1(Y1),y2(Y2),x(X),id(ID){}
	bool operator <(const edge &a)const {
		return x<a.x;
	}
}s[MAX];

void Upchild(int n){
	if(color[n]){
		color[n<<1]=color[n<<1|1]=color[n];
		color[n]=0;
	}
}

void Update(int L,int R,int c,int n,int left,int right){
	if(L<=left && right<=R){color[n]=c;return;}
	Upchild(n);
	int mid=left+right>>1;
	if(L<=mid)Update(L,R,c,n<<1,left,mid);
	if(R>mid)Update(L,R,c,n<<1|1,mid+1,right);
} 

void Query(int L,int R,int id,int n,int left,int right){
	if(color[n]){mark[id][color[n]]=true;}
	if(left == right)return;
	int mid=left+right>>1;
	if(L<=mid)Query(L,R,id,n<<1,left,mid);
	if(R>mid)Query(L,R,id,n<<1|1,mid+1,right);
}

int main(){
	int t,n,y1,y2,x;
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;++i){
			scanf("%d%d%d",&y1,&y2,&x);
			s[i]=edge(y1,y2,x,i);
		}
		sort(s+1,s+n+1);
		memset(color,0,sizeof color);
		memset(mark,false,sizeof mark);
		for(int i=1;i<=n;++i){
			Query(s[i].y1*2,s[i].y2*2,s[i].id,1,0,MAX*2);//�Ȳ�ѯ�����߶���߿ɼ����߶�
			Update(s[i].y1*2,s[i].y2*2,s[i].id,1,0,MAX*2);//���¸�����ɼ��߶� 
		}
		int ans=0;
		for(int i=1;i<=n;++i){//����ͳ�ƽ�� 
			for(int j=1;j<=n;++j){
				if(mark[i][j])
				for(int k=1;k<=n;++k){
					if(mark[i][k] && mark[j][k])++ans;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}